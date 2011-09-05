/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_EXCEPTIONS_ACCESSEXCEPTION_H
#define OPENXDS_SECURITY_EXCEPTIONS_ACCESSEXCEPTION_H

#include "openxds.security.h"
#include <openxds.base.h>
#include <openxds/Exception.h>

namespace openxds {
	namespace security {
		namespace exceptions {

class AccessException : public openxds::Exception
{
public:
  AccessException() {}
  AccessException( const char* aMessage ) : Exception( aMessage ) {}
  virtual ~AccessException() {}
};

};};};

#endif
