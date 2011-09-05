/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/RuntimeException.h>
#include <openxds.core.adt/IString.h>
#include <openxds.core.adt.std/StdString.h>
#include <cstdlib>

using namespace openxds;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;

static const char* EXCEPTION_TYPE = "RuntimeException";

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

RuntimeException::RuntimeException()
{}

RuntimeException::RuntimeException( const char* msg ) : Exception( msg )
{}

RuntimeException::RuntimeException( IException* anException, const char* msg ) : Exception( anException, msg )
{}

RuntimeException::~RuntimeException()
{}

//-----------------------------------------------------------------------------
// Public Methods
//-----------------------------------------------------------------------------

const char*
RuntimeException::getType() const
{
	return EXCEPTION_TYPE;
}

//----------------------------------------------------------------------------- 
// Virtual Methods from Object
//----------------------------------------------------------------------------- 

IException* RuntimeException::copy() const
{
	return this->copyRuntimeException();
}

RuntimeException* RuntimeException::copyRuntimeException() const
{
	if ( this->hasChainedException() )
	{
		IException* copy = this->chainedException->copy();
		const char* msg = this->_message->getChars( this->_message );

		return new RuntimeException( copy, msg );
	} else {
		return new RuntimeException( this->_message->getChars( this->_message ) );
	}
}
