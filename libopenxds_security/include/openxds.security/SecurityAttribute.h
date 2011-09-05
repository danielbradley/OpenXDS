/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_SECURITYATTRIBUTE_H
#define OPENXDS_SECURITY_SECURITYATTRIBUTE_H

#include "openxds.security.h"
#include "openxds.security/PrivilegedAttribute.h"
#include <openxds.base/NonCloneableException.h>
#include <openxds.base.h>

namespace openxds {
  namespace security {

/**
 *  Represents accessids, groupids, etc. <p>
 *
 */
class SecurityAttribute : public PrivilegedAttribute
{
public:

enum Type {
  Public = 1,
  AccessId = 2,
  PrimaryGroupId = 3,
  GroupId = 4,
  AttributeSet = 5,
  Role = 6,
  Clearance = 7,
  Capability = 8
};

  SecurityAttribute( SecurityAttribute::Type TYPE,
                     openxds::base::String* definingAuthority,
		             openxds::base::String* value );
  virtual ~SecurityAttribute();
  
  virtual openxds::base::Object* clone() const;

	virtual unsigned int getHashValue() const;

  /**
   *  @deprecated.
   */
  virtual bool equals( const openxds::base::Object* obj ) const;
  virtual bool equals( const openxds::base::Object& obj ) const;
  virtual bool equals( const openxds::base::Comparable& anObject ) const;

  virtual int compareTo( const openxds::base::Object& anObject ) const
  	throw (openxds::base::NonComparableException*);

  virtual openxds::base::String* toString() const;
  
  virtual SecurityAttribute::Type getType() const;

  /**
   *  @deprecated, formally <code>getDefiningAuthority()</code>.
   */
  virtual const openxds::base::String* getDefiningAuthorityX() const;

  virtual const openxds::base::String& getDefiningAuthority() const;

  /**
   *  @deprecated, formally <code>getValue()</code>.
   */
  virtual const openxds::base::String* getValueX() const;

  virtual const openxds::base::String& getValue() const;

	virtual openxds::util::Key* copy() const
		throw (openxds::base::NonCloneableException*);

private:
  SecurityAttribute::Type attributeType;
  openxds::base::String* definingAuthority;
  openxds::base::String* value;
};

};};

#endif
