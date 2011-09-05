/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.exceptions/ImplementationException.h>
#include <openxds.core.adt/IString.h>
#include <openxds.core.adt.std/StdString.h>
#include <cstdlib>

using namespace openxds;
using namespace openxds::exceptions;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;

static const char* EXCEPTION_TYPE = "ImplementationException";

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

ImplementationException::ImplementationException()
{}

ImplementationException::ImplementationException( const char* msg ) : RuntimeException( msg )
{}

ImplementationException::ImplementationException( IException* anException, const char* msg ) : RuntimeException( anException, msg )
{}

ImplementationException::~ImplementationException()
{}

//-----------------------------------------------------------------------------
// Public Methods
//-----------------------------------------------------------------------------

const char*
ImplementationException::getType() const
{
	return EXCEPTION_TYPE;
}

//----------------------------------------------------------------------------- 
// Virtual Methods from Object
//----------------------------------------------------------------------------- 

IException* ImplementationException::copy() const
{
	return this->copyImplementationException();
}

ImplementationException* ImplementationException::copyImplementationException() const
{
	if ( this->hasChainedException() )
	{
		IException* copy = this->chainedException->copy();
		const char* msg = this->_message->getChars( this->_message );

		return new ImplementationException( copy, msg );
	} else {
		return new ImplementationException( this->_message->getChars( this->_message ) );
	}
}
