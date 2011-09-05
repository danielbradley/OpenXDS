/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_EXCEPTIONS_IMPLEMENTATIONEXCEPTION_H
#define OPENXDS_EXCEPTIONS_IMPLEMENTATIONEXCEPTION_H

#include <openxds.h>
#include <openxds/RuntimeException.h>

namespace openxds {
	namespace exceptions {

class ImplementationException : public RuntimeException
{
public:
	ImplementationException();
	ImplementationException( const char* msg );
	ImplementationException( IException* anException, const char* msg );
	virtual ~ImplementationException();

	virtual IException* copy() const;
	virtual const char* getType() const;

	ImplementationException* copyImplementationException() const;
	int getIndex() const;
	
private:
	int index;
};

};};

#endif


