/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_ENTRY_H
#define OPENXDS_SECURITY_ENTRY_H

#include "openxds.security.h"
#include <openxds/Object.h>

namespace openxds {
  namespace security {

/**
 *  Is a mapping between a privileged attribute and a right
 *  for access policies. <p>
 */
class Entry : public openxds::base::Object
{
public:
  Entry( PrivilegedAttribute* attr, Right* aRight );
  PrivilegedAttribute* getPrivilegedAttribute() const;
  Right* getRight() const;
  
private:
  PrivilegedAttribute* privilegedAttribute;
  Right* right;
};

};};

#endif
