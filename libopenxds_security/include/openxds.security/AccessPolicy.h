/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_ACCESSPOLICY_H
#define OPENXDS_SECURITY_ACCESSPOLICY_H

#include "openxds.security.h"
#include <openxds.security/Policy.h>

namespace openxds {
  namespace security {

/**
 *  Maps privileged attributes to rights. <p>
 *
 *  Should this class swallow passed parameters or not???
 */
class AccessPolicy : public Policy
{
public:
  virtual ~AccessPolicy();

  /**
   *  Swallows parameters passed. <p>
   *
   *  @returns true if the entry did not exist, false otherwise. <p>
   */
  //bool addEntry( PrivilegedAttribute* anAttr, Right* aRight );
  
  /**
   *  @returns true if entry existed, false otherwise. <p>
   */
  //bool deleteEntry( const PrivilegedAttribute* attr, const Right* aRight );

  //Vector* getEntries( const PrivilegedAttribute* attr ) const;

protected:
  AccessPolicy();

private:
};

};};

#endif
