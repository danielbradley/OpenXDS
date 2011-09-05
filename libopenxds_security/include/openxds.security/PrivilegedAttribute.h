/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_PRIVILEGEDATTRIBUTE_H
#define OPENXDS_SECURITY_PRIVILEGEDATTRIBUTE_H

#include "openxds.security.h"
#include <openxds.util/AbstractKey.h>

namespace openxds {
  namespace security {

/**
 *  This is a very basic type like a uid, sid,
 *  account identifier, or certificate. <p>
 *
 *  @subclass SecurityAttribute
 */
class PrivilegedAttribute : public openxds::util::AbstractKey
{
public:
  virtual ~PrivilegedAttribute();

  virtual openxds::base::Object* clone() const = 0;
  virtual openxds::base::String* toString() const = 0;
  virtual unsigned int getHashValue() const = 0;
  virtual int compareTo( const openxds::base::Object& anObject ) const
  	throw (openxds::base::NonComparableException*) = 0;
  virtual bool equals( const openxds::base::Comparable& anObject ) const = 0;
protected:
  PrivilegedAttribute();
};

};};

#endif
