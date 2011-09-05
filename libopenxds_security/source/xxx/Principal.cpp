/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/security/Principal.h>

#include <openxds/base/String.h>
#include <openxds/base/StringBuffer.h>
#include <openxds/security/PrivilegedAttribute.h>

using namespace openxds::base;
using namespace openxds::security;

Principal::Principal( PrivilegedAttribute* privilegedAttribute )
{
  this->attribute = privilegedAttribute;
}

Principal::~Principal()
{
  delete this->attribute;
}

Object*
Principal::clone() const
{
  return new Principal(
      (PrivilegedAttribute*) this->attribute->clone() );
}

String*
Principal::toString() const
{
  StringBuffer sb;
  sb.append( "<principal>" );
  String* attr = this->attribute->toString();
  sb.append( *attr );
  delete attr;
  sb.append( "</principal>" );
  return sb.toString();
}

const PrivilegedAttribute*
Principal::getPrivilegedAttributeX() const
{
  return &this->getPrivilegedAttribute();
}

const PrivilegedAttribute&
Principal::getPrivilegedAttribute() const
{
  return *this->attribute;
}

