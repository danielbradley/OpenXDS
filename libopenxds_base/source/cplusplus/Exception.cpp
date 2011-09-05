/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/Exception.h>
#include <openxds.core.adt/IString.h>
#include <openxds.core.adt.std.h>
#include <openxds.core.adt.std/StdString.h>
#include <cstdlib>

using namespace openxds;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;

static const char* EXCEPTION_TYPE = "Exception";

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

Exception::Exception()
{
#ifdef OPENXDS_BASE_ABORT_ON_EXCEPTION
	abort();
#endif

	this->chainedException = (Exception*) null;
	this->_message = (IString*) new_StdString( "" );
}

Exception::Exception( const char* msg )
{
#ifdef OPENXDS_BASE_ABORT_ON_EXCEPTION
	abort();
#endif

	this->chainedException = (Exception*) null;
	this->_message = (IString*) new_StdString( msg );
}

Exception::Exception( IException* anException, const char* msg )
{
#ifdef OPENXDS_BASE_ABORT_ON_EXCEPTION
	abort();
#endif

	this->chainedException = anException;
	this->_message = (IString*) new_StdString( msg );
}

Exception::~Exception()
{
	if ( null != this->chainedException )
	{
		delete this->chainedException;
	}
	this->_message = this->_message->free( this->_message );
}

//-----------------------------------------------------------------------------
// Public Methods
//-----------------------------------------------------------------------------

IException*
Exception::retrieveChainedException()
{
	IException* ex = this->chainedException;
	this->chainedException = null;
	return ex;
}

const char*
Exception::getMessage() const
{
	return this->_message->getChars( this->_message );
}

const char*
Exception::getType() const
{
	return EXCEPTION_TYPE;
}

bool
Exception::hasChainedException() const
{
	bool has = false;
	if ( null != this->chainedException )
	{
		has = true;
	}
	return has;
}   

IException* Exception::copy() const
{
	return this->copyException();
}

Exception* Exception::copyException() const
{
	if ( this->hasChainedException() )
	{
		IException* copy = this->chainedException->copy();
		const char* msg = this->_message->getChars( this->_message );

		return new Exception( copy, msg );
	} else {
		return new Exception( this->_message->getChars( this->_message ) );
	}
}
