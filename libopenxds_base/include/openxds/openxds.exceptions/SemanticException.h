/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_EXCEPTIONS_SEMANTICEXCEPTION_H
#define OPENXDS_EXCEPTIONS_SEMANTICEXCEPTION_H

#include <openxds.h>
#include <openxds/RuntimeException.h>

namespace openxds {
	namespace exceptions {

class SemanticException : public RuntimeException
{
public:
	SemanticException();
	SemanticException( const char* msg );
	SemanticException( IException* anException, const char* msg );
	virtual ~SemanticException();

	virtual IException* copy() const;
	virtual const char* getType() const;

	virtual SemanticException* copySemanticException() const;
};

};};

#endif


