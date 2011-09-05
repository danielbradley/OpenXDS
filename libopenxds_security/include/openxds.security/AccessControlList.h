/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_ACCESSCONTROLLIST_H
#define OPENXDS_SECURITY_ACCESSCONTROLLIST_H

#include "openxds.security.h"
#include "openxds.security/AccessPolicy.h"
#include "openxds.security/AccessPolicy.h"

#include <openxds.base.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds.security.h>

namespace openxds {
	namespace security {

/**
 *  Non const objects passed to this class are swallowed by
 *  the object. Any duplicate objects are deallocated by the
 *  class, and all objects are deallocated during deletion. <p>
 */
class AccessControlList : public AccessPolicy
{
public:
  AccessControlList();
  virtual ~AccessControlList();
  
  /**
   *  Modifies the map so that the "attr" points to the
   *  passed RightsList "list". If an entry already exists
   *  it is deleted. <p>
   *
   *  If the previous rights list is desired the caller should
   *  call "get" first. <p>
   *
   *  @return true if no previous entry existed, else false.
   */
  bool set( const SecurityAttribute& attr, const RightsList& list );

  /**
   *  This method adds an entry mapping the passed security attribute
   *  object to the passed list object (it swallows both parameters). <p>
   */
  bool set( const SecurityAttribute* attr, const RightsList* list );

  /**
   *  Returns the rights list mapped from a key object equal
   *  to the security attribute passed, removing it from the
   *  ACL. <p>
   *
   *  If the passed SecurityAttribute is not the exact same
   *  object as the key object, the key object is deleted. <p>
   *
   *  @returns the rights list specified by "attr".
   */
  RightsList* remove( const SecurityAttribute& attr )
  throw (openxds::base::NoSuchElementException*);

  /**
   *  Returns a reference to a rights list pointed to by the
   *  security attribute passed. <p>
   */
  const RightsList& get( const SecurityAttribute& attr ) const
      throw (openxds::base::NoSuchElementException*);

  /**
   *  Returns a copy of the rights list specified by the
   *  security attribute passed. <p>
   */
  RightsList* retrieve( const SecurityAttribute& attr ) const
  throw (openxds::base::NoSuchElementException*);  

  /**
   *  Returns an iterator of map entries mapping security
   *  attributes to rights lists. <p>
   */
  openxds::base::Iterator* keys() const;

private:
  openxds::util::Dictionary* map;
};

};};

#endif
