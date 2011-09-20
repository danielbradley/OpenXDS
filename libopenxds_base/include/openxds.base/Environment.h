/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_ENVIRONMENT_H
#define OPENXDS_BASE_ENVIRONMENT_H

#include <openxds.base.h>
#include <openxds/Object.h>

namespace openxds {
	namespace base {

class Environment : public openxds::Object
{
private:
	static const char* arg0;

public:
	static void        init( int argc, const char** argv );
	static String*     executableDirectory();
	static const char* getValue( const char* variableName );
};

};};

#endif
