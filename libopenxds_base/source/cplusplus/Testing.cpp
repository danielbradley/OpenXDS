/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.testing/Testing.h"

#include "openxds/Object.h"

#include "openxds.base/FormattedString.h"
#include "openxds.base/ProcessInfo.h"
#include "openxds.base/Runtime.h"
#include "openxds.base/String.h"
#include "openxds.base/StringBuffer.h"
#include "openxds.base/System.h"

#include <openxds.core.base/CharString.h>
#include <openxds.core.base/Clock.h>
#include <openxds.core.base/CRuntime.h>
#include <openxds.core.base/Time.h>

#include <cstdio>

using namespace openxds::base;
using namespace openxds::testing;
using namespace openxds::core::base;

static const char* PASSED = "   passed   ";
static const char* FAILED = "!! FAILED !!";

long
Testing::memoryUsage( bool(*function)(void) )
{
	bool result;
	long usage = 0;
	ProcessInfo pi;
	long start;
	long finish;

	start = pi.getMemoryUsage();
	result = function();
	finish = pi.getMemoryUsage();
	usage = ( finish - start );
	if ( !result ) usage ^= usage;
	return usage;
}

bool
Testing::runTestSet( const char* id, bool(*function)(void) )
{
	ITime* now = Time_Now();
	fprintf( stdout, "\n<testset class=\"%s\" timestamp=\"%s\">\n", id, now->getTextual( now ) );
	String* s = debugProfile( id, function );
	bool status = ( CharString_contains( s->getChars(), "passed" ) == 1 );
	fprintf( stdout, "\n</testset>\n" );
	delete s;
	return status;
}

bool
Testing::runTest( const char* id, bool(*function)(void) )
{
	bool status = false;
	{
		FormattedString test_id( "\n<test id=\"%s\">\n", id );
		
		const char* tid = test_id.getChars();
		fprintf( stdout, "%s", tid );

		Object::startTest();
		Runtime::startTest();
		{

			fflush( stdout );
			String* s = debugProfile( id, function );
			const char* chars = s->getChars();
			status = (CharString_contains( chars, "passed" ) == 1);
			fprintf( stdout, "%s\n", chars );
			fprintf( stdout, "</test>\n" );
			delete s;
		}
		Runtime::stopTest();
		Object::stopTest();
	}
	return status;
}

bool
Testing::skipTest( const char* id, bool(*function)(void), const char* reason )
{
	fprintf( stdout, "<test id=\"%s\">\n\t<result status=\"skipped\"/>%s</test>\n", id, reason );
	return false;
}

bool
Testing::runTest( const char* id, bool(*function)(void), unsigned int count )
{
	fprintf( stdout, "<test id=\"%s\">\n", id );
	String* s = debugProfile( id, function, count );
	bool status = ( CharString_contains( s->getChars(), "passed" ) == 1 );
	const char*const chars = s->getChars();
	fprintf( stdout, "%s</test>\n", chars );
	delete s;
	return status;
}

bool
Testing::skipTest( const char* id, bool(*function)(void), unsigned int count, const char* reason )
{
	fprintf( stdout, "<test id=\"%s\">\n\t<result status=\"skipped\"/>%s\n</test>\n", id, reason );
	return false;
}

int
Testing::profileMain( int(*function)( int, char** ), int argc, char** argv )
{
	int result;
	String* profileResult;

	Runtime runtime;
	ProcessInfo pi;

	const char* result_string;

	long long object_count_start;
	long long object_count_finish;	
	long long object_count;

	long long allocated_count_start;
	long long allocated_count_finish;
	long long allocated_count;

	long long memory_start;
	long long memory_finish;
	long long memory;

	unsigned long user_time_start;
	unsigned long user_time_finish;
	unsigned long user_time;
	
	unsigned long system_time_start;
	unsigned long system_time_finish;
	unsigned long system_time;

	object_count_start    = Object::getObjectCount();
	allocated_count_start = Runtime::getAllocationCount();
	memory_start          = CRuntime_GetAllocationCount(); //pi.getMemoryUsage();
	system_time_start     = Clock_GetSystemTime();
	user_time_start       = Clock_GetUserTime();

#ifdef _WIN32
#ifdef _DEBUG
	_CrtCheckMemory();
#endif
#endif
	result = function( argc, argv );
#ifdef _WIN32
#ifdef _DEBUG
	_CrtCheckMemory();
#endif
#endif

	user_time_finish       = Clock_GetUserTime();
	
	system_time_finish     = Clock_GetSystemTime();
	memory_finish          = CRuntime_GetAllocationCount(); //pi.getMemoryUsage();
	object_count_finish    = Object::getObjectCount();
	allocated_count_finish = Runtime::getAllocationCount();

	object_count = object_count_finish - object_count_start;
	//  fprintf( stderr, "%u\n", object_count );
	allocated_count = allocated_count_finish - allocated_count_start;
	//  fprintf( stderr, "\n%u\n", allocated_count );
	memory       = memory_finish - memory_start;
	//  fprintf( stderr, "%u\n", memory );
	user_time    = user_time_finish - user_time_start;
	//  fprintf( stderr, "%u\n", user_time );
	system_time  = system_time_finish - system_time_start;
	//  fprintf( stderr, "%u\n", system_time );
	
	if ( result ) {
		result_string = PASSED;
	} else {
		result_string = FAILED;
	}

	StringBuffer sb;
	FormattedString status( "<result status=\"%s\"/>", result_string );
	FormattedString timing( "<timing user=\"%05lu\" sys=\"%05lu\"/>" , user_time, system_time );
	FormattedString mem( "<memory objLeak=\"%05lli\" newLeak=\"%05lli\" cRuntimeLeak=\"%05lli\"/>", object_count, allocated_count, memory );


	sb.append( status );
	sb.append( timing );
	sb.append( mem );
	profileResult = sb.asString();

	fprintf( stdout, "%s\n", profileResult->getChars() );
	return result;
}


String*
Testing::debugProfile( const char* id, bool(*function)(void) )
{
	return profile( id, function, 1 );
}

String*
Testing::debugProfile( const char* id, bool(*function)(void), unsigned int count )
{
	return profile( id, function, count );
}

String*
Testing::profile( const char* id, bool(*function)(void), unsigned int count )
{
	String* profileResult;
	bool result;
	bool memory_leak = 0;

	Runtime runtime;
	ProcessInfo pi;

	const char* result_string;

	long long allocated_count_start;
	long long allocated_count_finish;
	long long allocated_count;

	long long object_count_start;
	long long object_count_finish;	
	long long object_count;

	long long cruntime_start;
	long long cruntime_finish;
	long long cruntime;

	unsigned long user_time_start;
	unsigned long user_time_finish;
	unsigned long user_time;
	
	unsigned long system_time_start;
	unsigned long system_time_finish;
	unsigned long system_time;

	object_count_start    = Object::getObjectCount();
	allocated_count_start = Runtime::getAllocationCount();
	cruntime_start        = CRuntime_GetAllocationCount(); //pi.getMemoryUsage();
	system_time_start     = Clock_GetSystemTime();
	user_time_start       = Clock_GetUserTime();

#ifdef _WIN32
#ifdef _DEBUG
	_CrtCheckMemory();
#endif
#endif
	{
		unsigned int i;
		for ( i=0; i < count; i++ )
		{
			result = function();
		}
	}
#ifdef _WIN32
#ifdef _DEBUG
	_CrtCheckMemory();
#endif
#endif
	user_time_finish       = Clock_GetUserTime();
	
	system_time_finish     = Clock_GetSystemTime();
	cruntime_finish          = CRuntime_GetAllocationCount(); //pi.getMemoryUsage();
	object_count_finish    = Object::getObjectCount();
	allocated_count_finish = Runtime::getAllocationCount();

	allocated_count = allocated_count_finish - allocated_count_start;
	//  fprintf( stderr, "\n%u\n", allocated_count );
	object_count = object_count_finish - object_count_start;
	//  fprintf( stderr, "%u\n", object_count );
	cruntime = cruntime_finish - cruntime_start;
	//  fprintf( stderr, "%u\n", memory );

	memory_leak = allocated_count | object_count | cruntime;

	user_time    = user_time_finish - user_time_start;
	//  fprintf( stderr, "%u\n", user_time );
	system_time  = system_time_finish - system_time_start;
	//  fprintf( stderr, "%u\n", system_time );


	//	If there have been any memory leaks fail the test.

	if ( allocated_count || object_count || cruntime )
	{
		result = false;
	}
	
	if ( result ) {
		result_string = PASSED;
	} else {
		result_string = FAILED;
	}

	if ( true )
	{
		StringBuffer sb;
		FormattedString status( "<result status=\"%s\"/>", result_string );
		FormattedString timing( "<timing user=\"%05lu\" sys=\"%05lu\"/>" , user_time, system_time );
		FormattedString memory( "<memory objLeak=\"%05lli\" newLeak=\"%05lli\" cRuntimeLeak=\"%05lli\"/>", object_count, allocated_count, cruntime );

		sb.append( status );
		sb.append( timing );
		if ( memory_leak )
			sb.append( memory );
		profileResult = sb.asString();
	} else {
		profileResult = new FormattedString( "<profile id=\"%s\" status=\"%s\" user=\"%05u\" sys=\"%05u\" leak=\"%05lli\" objleak=\"%05lli\" mem=\"%lli\"/>",
			id, result_string, user_time, system_time, allocated_count, object_count, cruntime );
	}
	return profileResult;
}
