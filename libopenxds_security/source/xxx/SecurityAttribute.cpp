/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/security/SecurityAttribute.h>

#include <openxds/base/ImplementationException.h>
#include <openxds/base/String.h>
#include <openxds/base/StringBuffer.h>

using namespace openxds::base;
using namespace openxds::security;
using namespace openxds::util;

SecurityAttribute::SecurityAttribute( SecurityAttribute::Type TYPE,
                                      String* aDefiningAuthority,
		                              String* aValue )
{
  this->attributeType = TYPE;
  this->definingAuthority = aDefiningAuthority;
  this->value = aValue;
}

SecurityAttribute::~SecurityAttribute()
{
  delete this->definingAuthority;
  delete this->value;
}

Object* SecurityAttribute::clone() const
{
  return new SecurityAttribute(
      this->getType(),
      (String*) this->getDefiningAuthority().clone(),
      (String*) this->getValue().clone() );
}

unsigned int
SecurityAttribute::getHashValue() const
{
	return 0;
}

bool
SecurityAttribute::equals( const Object* obj ) const
{
  return this->equals( *obj );
}

bool SecurityAttribute::equals( const Object& obj ) const
{
  bool result = false;

  const SecurityAttribute* attr = dynamic_cast<const SecurityAttribute*>( &obj );

  if ( null != attr )
  {
    if ( this->getType() == attr->getType() )
    {
      if ( this->getDefiningAuthority().equals( attr->getDefiningAuthority() ) )
      {
        if ( this->getValue().equals( attr->getValue() ) )
        {
          result = true;
    } } }
  }
  return result;
}

bool SecurityAttribute::equals( const Comparable& obj ) const
{
  bool result = false;

  const SecurityAttribute* attr = dynamic_cast<const SecurityAttribute*>( &obj );

  if ( null != attr )
  {
    if ( this->getType() == attr->getType() )
    {
      if ( this->getDefiningAuthority().equals( attr->getDefiningAuthority() ) )
      {
        if ( this->getValue().equals( attr->getValue() ) )
        {
          result = true;
    } } }
  }
  return result;
}

int
SecurityAttribute::compareTo( const openxds::base::Object& anObject ) const
throw (openxds::base::NonComparableException*)
{
	throw new ImplementationException( "not yet implemented" );
}

SecurityAttribute::Type SecurityAttribute::getType() const
{
  return this->attributeType;
}

const String*
SecurityAttribute::getDefiningAuthorityX() const
{
  return &this->getDefiningAuthority();
}

const String&
SecurityAttribute::getDefiningAuthority() const
{
  return *this->definingAuthority;
}

const String*
SecurityAttribute::getValueX() const
{
  return &this->getValue();
}

const String& SecurityAttribute::getValue() const
{
  return *this->value;
}

String*
SecurityAttribute::toString() const
{
  StringBuffer sb;
  sb.append( "<securityattribute type=\"" );
  sb.append( this->attributeType );
  sb.append( "\" definingAuthority=\"" );
  sb.append( *this->definingAuthority );
  sb.append( "\" value=\"" );
  sb.append( *this->value );
  sb.append( "\"/>" );
  return sb.toString();
}

Key*
SecurityAttribute::copy() const
throw (NonCloneableException*)
{
	throw new ImplementationException();
}
