/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds/Object.h"
#include "openxds.base/Runtime.h"
#include "openxds.core.base/Clock.h"
#include "openxds.core.base/CRuntime.h"
#include "openxds.core.threads/Mutex.h"

#include <exception>
#include <new>
#include <cstdlib>
#include <cstdio>

using namespace openxds::base;
using namespace openxds::core::base;
using namespace openxds::core::threads;

bool      Runtime::test            = false;
IMutex*   Runtime::lock            = null;
long long Runtime::allocationCount = 0;

#ifdef OPENXDS_USE_DEBUG_NEW_AND_DELETE

void* operator new ( size_t size )
{
	void* p = malloc( size ); // in operator new
	if ( null != p ) {
		if ( Runtime::test ) Runtime::incrementAllocationCount();
	} else {
		throw std::bad_alloc();
	}
	return p;
}

void  operator delete( void* obj )
{
	if ( obj )
	{
		free( obj ); // in operator delete
		if ( Runtime::test ) Runtime::decrementAllocationCount();
	}
}

#endif

Runtime::Runtime()
{}

Runtime::~Runtime()
{}

void*
Runtime::malloc( size_t size )
{
	void* p;
	if ( Runtime::test ) Runtime::lock->lock( Runtime::lock );
	p = CRuntime_malloc( size );
	if ( Runtime::test ) Runtime::lock->unlock( Runtime::lock );
	return p;
}

void*
Runtime::calloc( size_t nmemb, size_t size )
{
	void* p;
	if ( Runtime::test ) Runtime::lock->lock( Runtime::lock );
	p = CRuntime_calloc( nmemb, size );
	if ( Runtime::test ) Runtime::lock->unlock( Runtime::lock );
	return p;
}

void*
Runtime::realloc( void* ptr, size_t size )
{
	void* p;
	if ( Runtime::test ) Runtime::lock->lock( Runtime::lock );
	p = CRuntime_realloc( ptr, size );
	if ( Runtime::test ) Runtime::lock->unlock( Runtime::lock );
	return p;
}

void
Runtime::free( void* ptr )
{
	if ( Runtime::test ) Runtime::lock->lock( Runtime::lock );
	CRuntime_free( ptr );
	if ( Runtime::test ) Runtime::lock->unlock( Runtime::lock );
}

unsigned long
Runtime::getUpTime() const
{
	return Clock_GetUptime();
}

unsigned long
Runtime::getUserTime() const
{
	return Clock_GetUserTime();
}

unsigned long
Runtime::getSystemTime() const
{
	return Clock_GetSystemTime();
}

void
Runtime::startTest()
{
	Runtime::test = true;
	Runtime::lock = new_Mutex();
}

void
Runtime::stopTest()
{
	Runtime::lock->free( Runtime::lock );
	Runtime::test = false;
}

void
Runtime::incrementAllocationCount()
{
	Runtime::lock->lock( Runtime::lock );
	Runtime::allocationCount++;
	Runtime::lock->unlock( Runtime::lock );
}

void
Runtime::decrementAllocationCount()
{
	Runtime::lock->lock( Runtime::lock );
	Runtime::allocationCount--;
	Runtime::lock->unlock( Runtime::lock );
}

long long
Runtime::getAllocationCount()
{
	long long count = 0;
	if ( Runtime::test ) Runtime::lock->lock( Runtime::lock );
	count = Runtime::allocationCount;
	if ( Runtime::test ) Runtime::lock->unlock( Runtime::lock );
	return count;
}

long long
Runtime::getCRuntimeAllocationCount()
{
	long long count = 0;
	if ( Runtime::test ) Runtime::lock->lock( Runtime::lock );
	count = CRuntime_GetAllocationCount();
	if ( Runtime::test ) Runtime::lock->unlock( Runtime::lock );
	return count;
}

void
Runtime::sleepFor( unsigned int seconds )
{
	CRuntime_SleepForSeconds( seconds );
}

void
Runtime::microSleepFor( unsigned int microseconds )
{
	CRuntime_SleepForMicroseconds( microseconds );
}

void
Runtime::printMemorySummary( void* f )
{
	if ( Runtime::test ) Runtime::lock->lock( Runtime::lock );
	{
		FILE* fp = (FILE*) f;
		long long object_count = Object::getObjectCount();
		long long alloc_count  = Runtime::getAllocationCount();
		long long calloc_count = Runtime::getCRuntimeAllocationCount();

		fprintf( fp, "Runtime::printMemorySummary: objects: %lli news: %lli mallocs: %lli\n", object_count, alloc_count, calloc_count );
	}
	if ( Runtime::test ) Runtime::lock->unlock( Runtime::lock );
}

