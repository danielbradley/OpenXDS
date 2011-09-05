/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.exceptions/SemanticException.h>
#include <openxds.core.adt/IString.h>
#include <openxds.core.adt.std/StdString.h>
#include <cstdlib>

using namespace openxds;
using namespace openxds::exceptions;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;

static const char* EXCEPTION_TYPE = "SemanticException";

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

SemanticException::SemanticException()
{}

SemanticException::SemanticException( const char* msg ) : RuntimeException( msg )
{}

SemanticException::SemanticException( IException* anException, const char* msg ) : RuntimeException( anException, msg )
{}

SemanticException::~SemanticException()
{}

//-----------------------------------------------------------------------------
// Public Methods
//-----------------------------------------------------------------------------

const char*
SemanticException::getType() const
{
	return EXCEPTION_TYPE;
}

//----------------------------------------------------------------------------- 
// Virtual Methods from Object
//----------------------------------------------------------------------------- 

IException* SemanticException::copy() const
{
	return this->copySemanticException();
}

SemanticException* SemanticException::copySemanticException() const
{
	if ( this->hasChainedException() )
	{
		IException* copy = this->chainedException->copy();
		const char* msg = this->_message->getChars( this->_message );

		return new SemanticException( copy, msg );
	} else {
		return new SemanticException( this->_message->getChars( this->_message ) );
	}
}
