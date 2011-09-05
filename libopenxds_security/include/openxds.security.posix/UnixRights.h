/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENOCL_SECURITY_POSIX_UNIXRIGHTS_H_
#define _OPENOCL_SECURITY_POSIX_UNIXRIGHTS_H_

#include <openxds/base.h>
#include <openxds/security.h>

namespace openxds {
namespace security {
namespace posix {

// Static Class
class UnixRights
{
public:
  static const openxds::security::Right* READ;
  static const openxds::security::Right* WRITE;
  static const openxds::security::Right* EXECUTE;
};

};
};
};

#endif

