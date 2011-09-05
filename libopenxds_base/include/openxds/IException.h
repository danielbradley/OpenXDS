/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IEXCEPTION_H
#define OPENXDS_IEXCEPTION_H

#include <openxds.h>

#include <openxds/Interface.h>

namespace openxds {

class IException : public Interface
{
public:
	virtual ~IException() {};

	virtual const char* getMessage() const = 0;
	virtual IException* retrieveChainedException() = 0;
	virtual bool hasChainedException() const = 0;

	virtual IException* copy() const = 0;
	virtual const char* getType() const = 0;
};
    
};

#endif
