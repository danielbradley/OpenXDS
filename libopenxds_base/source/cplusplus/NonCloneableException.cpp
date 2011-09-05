/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.exceptions/NonCloneableException.h"

#include <openxds.core.adt/IString.h>
#include <openxds.core.adt.std/StdString.h>
#include <cstdlib>

using namespace openxds;
using namespace openxds::exceptions;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;

static const char* EXCEPTION_TYPE = "NoncloneableException";

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

NoncloneableException::NoncloneableException()
{}

NoncloneableException::NoncloneableException( const char* msg ) : RuntimeException( msg )
{}

NoncloneableException::NoncloneableException( IException* anException, const char* msg ) : RuntimeException( anException, msg )
{}

NoncloneableException::~NoncloneableException()
{}

//-----------------------------------------------------------------------------
// Public Methods
//-----------------------------------------------------------------------------

const char*
NoncloneableException::getType() const
{
	return EXCEPTION_TYPE;
}

//----------------------------------------------------------------------------- 
// Virtual Methods from Object
//----------------------------------------------------------------------------- 

IException* NoncloneableException::copy() const
{
	return this->copyNoncloneableException();
}

NoncloneableException* NoncloneableException::copyNoncloneableException() const
{
	if ( this->hasChainedException() )
	{
		IException* copy = this->chainedException->copy();
		const char* msg = this->_message->getChars( this->_message );

		return new NoncloneableException( copy, msg );
	} else {
		return new NoncloneableException( this->_message->getChars( this->_message ) );
	}
}
