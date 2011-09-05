/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_EXCEPTIONS_INDEXOUTOFBOUNDSEXCEPTION_H
#define OPENXDS_EXCEPTIONS_INDEXOUTOFBOUNDSEXCEPTION_H

#include <openxds.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace exceptions {

class IndexOutOfBoundsException : public NoSuchElementException
{
public:
	IndexOutOfBoundsException();
	IndexOutOfBoundsException( const char* msg );
	IndexOutOfBoundsException( IException* anException, const char* msg );
	IndexOutOfBoundsException( int index );
	virtual ~IndexOutOfBoundsException();

	virtual IException* copy() const;
	virtual const char* getType() const;

	IndexOutOfBoundsException* copyIndexOutOfBoundsException() const;
	int getIndex() const;
	
private:
	int index;
};

};};

#endif


