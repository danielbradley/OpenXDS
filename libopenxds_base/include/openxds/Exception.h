/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_EXCEPTION_H
#define OPENXDS_EXCEPTION_H

#include <openxds.h>

#include <openxds/Object.h>
#include <openxds/IException.h>
#include <openxds.core.adt/IString.h>

namespace openxds {

class Exception : public Object, public IException
{
public:
	Exception();
	Exception( const char* msg );
	Exception( IException* anException, const char* msg );
	virtual ~Exception();

	IException* retrieveChainedException();
	const char* getMessage() const;
	bool hasChainedException() const;

	virtual const char* getType() const;
	virtual IException* copy() const;

	Exception* copyException() const;
	
    // ARE THESE POSSIBLE IN C++???
    //void printStackTrace();
    //void printStackTrace(PrintStream ps);
    //void printStackTrace(PrintWriter pw);
protected:
	openxds::core::adt::IString* _message;
	IException* chainedException;
};
    
};

#endif
