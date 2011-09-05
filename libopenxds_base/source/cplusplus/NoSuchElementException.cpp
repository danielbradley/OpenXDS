/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds.core.adt/IString.h>
#include <openxds.core.adt.std/StdString.h>
#include <cstdlib>

using namespace openxds;
using namespace openxds::exceptions;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;

static const char* EXCEPTION_TYPE = "NoSuchElementException";

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

NoSuchElementException::NoSuchElementException()
{}

NoSuchElementException::NoSuchElementException( const char* msg ) : RuntimeException( msg )
{}

NoSuchElementException::NoSuchElementException( IException* anException, const char* msg ) : RuntimeException( anException, msg )
{}

NoSuchElementException::~NoSuchElementException()
{}

//-----------------------------------------------------------------------------
// Public Methods
//-----------------------------------------------------------------------------

const char*
NoSuchElementException::getType() const
{
	return EXCEPTION_TYPE;
}

//----------------------------------------------------------------------------- 
// Virtual Methods from Object
//----------------------------------------------------------------------------- 

IException* NoSuchElementException::copy() const
{
	return this->copyNoSuchElementException();
}

NoSuchElementException* NoSuchElementException::copyNoSuchElementException() const
{
	if ( this->hasChainedException() )
	{
		IException* copy = this->chainedException->copy();
		const char* msg = this->_message->getChars( this->_message );

		return new NoSuchElementException( copy, msg );
	} else {
		return new NoSuchElementException( this->_message->getChars( this->_message ) );
	}
}
