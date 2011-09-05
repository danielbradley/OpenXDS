/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_PRINCIPAL_H
#define OPENXDS_SECURITY_PRINCIPAL_H

#include "openxds.security.h"
#include <openxds/Object.h>

namespace openxds {
  namespace security {

/**
 *  A principal identifies some sort of person, or account,
 *  or role, etc. It contains some sort of PrivilegedAttribute.
 */
class Principal : public openxds::base::Object
{
public:
  Principal( PrivilegedAttribute* privilegedAttribute );
  ~Principal();

  /**
   *  @deprecated, formally <code>getPrivilegedAttribute()</code>.
   */
  const PrivilegedAttribute* getPrivilegedAttributeX() const;

  const PrivilegedAttribute& getPrivilegedAttribute() const;

  virtual openxds::base::Object* clone() const;
  virtual openxds::base::String* toString() const;

private:
  PrivilegedAttribute* attribute;
};

};};

#endif
