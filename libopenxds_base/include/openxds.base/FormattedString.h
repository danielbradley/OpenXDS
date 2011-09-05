/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_FORMATTEDSTRING_H
#define OPENXDS_BASE_FORMATTEDSTRING_H

#include <openxds.base/String.h>

#include <openxds.base.h>
#include <openxds.base_exceptions.h>

namespace openxds {
	namespace base {

class FormattedString : public String
{
public:

	FormattedString( const char* format, ... );
	virtual ~FormattedString();

};

};};

#endif
