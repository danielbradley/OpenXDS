/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.exceptions/IndexOutOfBoundsException.h>
#include <openxds.core.adt/IString.h>
#include <openxds.core.adt.std/StdString.h>
#include <cstdlib>

using namespace openxds;
using namespace openxds::exceptions;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;

static const char* EXCEPTION_TYPE = "IndexOutOfBoundsException";

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

IndexOutOfBoundsException::IndexOutOfBoundsException() : NoSuchElementException()
{}

IndexOutOfBoundsException::IndexOutOfBoundsException( const char* msg ) : NoSuchElementException( msg )
{}

IndexOutOfBoundsException::IndexOutOfBoundsException( IException* anException, const char* msg ) : NoSuchElementException( anException, msg )
{}

IndexOutOfBoundsException::IndexOutOfBoundsException( long index ) : NoSuchElementException()
{
	this->index = index;
}

IndexOutOfBoundsException::~IndexOutOfBoundsException()
{}

//-----------------------------------------------------------------------------
// Public Methods
//-----------------------------------------------------------------------------

const char*
IndexOutOfBoundsException::getType() const
{
	return EXCEPTION_TYPE;
}

//----------------------------------------------------------------------------- 
// Virtual Methods from Object
//----------------------------------------------------------------------------- 

IException* IndexOutOfBoundsException::copy() const
{
	return this->copyIndexOutOfBoundsException();
}

IndexOutOfBoundsException* IndexOutOfBoundsException::copyIndexOutOfBoundsException() const
{
	if ( this->hasChainedException() )
	{
		IException* copy = this->chainedException->copy();
		const char* msg = this->_message->getChars( this->_message );

		return new IndexOutOfBoundsException( copy, msg );
	} else {
		return new IndexOutOfBoundsException( this->_message->getChars( this->_message ) );
	}
}

long
IndexOutOfBoundsException::getIndex() const
{
	return this->index;
}
