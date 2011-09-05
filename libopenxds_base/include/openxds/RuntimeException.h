/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_RUNTIMEEXCEPTION_H
#define OPENXDS_RUNTIMEEXCEPTION_H

#include <openxds.h>
#include <openxds/Exception.h>

namespace openxds {

class RuntimeException : public openxds::Exception
{
public:
	RuntimeException();
	RuntimeException( const char* msg );
	RuntimeException( IException* anException, const char* msg );
	virtual ~RuntimeException();

	virtual IException* copy() const;
	virtual const char* getType() const;

	RuntimeException* copyRuntimeException() const;
};

};

#endif


