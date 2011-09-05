/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_POLICY_H_
#define OPENXDS_SECURITY_POLICY_H_

#include "openxds.security.h"
#include <openxds/Object.h>

namespace openxds {
  namespace security {

/**
 *  This will probably be moved to openxds::base. <p>
 */
class Policy : public openxds::Object
{
public:
  virtual ~Policy();

protected:
  Policy();
};

};};

#endif
