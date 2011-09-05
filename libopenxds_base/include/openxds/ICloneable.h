/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_ICLONEABLE_H
#define OPENXDS_ICLONEABLE_H

#include "openxds/Interface.h"

namespace openxds {

// Interface
class  ICloneable : public Interface
{
public:
	virtual ~ICloneable() {};
	
	virtual Object* clone() const = 0;
};

};

#endif
