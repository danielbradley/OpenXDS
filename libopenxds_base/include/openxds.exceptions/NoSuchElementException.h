/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_EXCEPTIONS_NOSUCHELEMENTEXCEPTION_H
#define OPENXDS_EXCEPTIONS_NOSUCHELEMENTEXCEPTION_H

#include <openxds.h>
#include <openxds/RuntimeException.h>

namespace openxds {
	namespace exceptions {

class NoSuchElementException : public RuntimeException
{
public:
	NoSuchElementException();
	NoSuchElementException( const char* msg );
	NoSuchElementException( IException* anException, const char* msg );
	virtual ~NoSuchElementException();

	virtual IException* copy() const;
	virtual const char* getType() const;

	NoSuchElementException* copyNoSuchElementException() const;
	int getIndex() const;
	
private:
	int index;
};

};};

#endif


