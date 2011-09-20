/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.core.base/Environment.h"
#include "openxds.base/Environment.h"
#include "openxds.base/String.h"

using namespace openxds::base;
using namespace openxds::core::base;

const char*
Environment::arg0 = "";

void
Environment::init( int argc, const char** argv )
{
	arg0 = argv[0];
}

String*
Environment::executableDirectory()
{
	String* dir = NULL;

	IEnvironment* environment = new_Environment( arg0 );
	{
		dir = new String( environment->getDirectoryContainingExecutable( environment ) );
	}
	environment->free( environment );

	return dir;
}

const char*
Environment::getValue( const char* variableName )
{
	return Environment_getEnvironmentVariable( variableName );
}
