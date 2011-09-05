/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_TESTING_TESTING_H
#define OPENXDS_TESTING_TESTING_H

#ifdef _WIN32
#ifdef _MSC_VER
#include <crtdbg.h>
#endif
#endif

#include <openxds.base.h>
#include <openxds.testing.h>

namespace openxds {
	namespace testing {

class  Testing
{
public:
	static bool    runTestSet( const char* id, bool(*function)(void) );
	static bool    runTest( const char* id, bool(*function)(void) );
	static bool    skipTest( const char* id, bool(*function)(void), const char* reason );
	static bool    runTest( const char* id, bool(*function)(void), unsigned int count );
	static bool    skipTest( const char* id, bool(*function)(void), unsigned int count, const char* reason );

	static long                   memoryUsage( bool(*function)(void) );
	static openxds::base::String* debugProfile( const char* id, bool(*function)(void) );
	static openxds::base::String* debugProfile( const char* id, bool(*function)(void), unsigned int count );
	static openxds::base::String*      profile( const char* id, bool(*function)(void), unsigned int count );
	static int                    profileMain( int(*function)( int, char**), int argc, char** argv );
};

};};

#endif
