/*
 *  Copyright (C) 2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_UTIL_ITOKEN_H
#define OPENXDS_UTIL_ITOKEN_H

#include <openxds/Interface.h>
#include <openxds.base.h>

namespace openxds {
	namespace util {

class IToken : public openxds::Interface
{
public:
	virtual ~IToken() {};

	virtual openxds::base::String* getValue() const = 0;
};

};};

#endif
