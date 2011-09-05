/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.security/AccessControlList.h>

#include <openxds/Object.h>
//#include <openxds.util/Dictionary.h>
//#include <openxds/util/ObjectKey.h>
#include <openxds/security/RightsList.h>
#include <openxds/security/SecurityAttribute.h>

#include <cstdio>

using namespace openxds::base;
using namespace openxds::util;
using namespace openxds::security;

AccessControlList::AccessControlList()
{
  this->map = new Dictionary();
}

AccessControlList::~AccessControlList()
{
  delete this->map;
}

bool
AccessControlList::set( const SecurityAttribute& attr,
                        const RightsList&        rightsList )
{
  bool result = false;

  // If the attribute already exists in the ACL remove all trace
  // of its existance.
  //
  try
  {
    RightsList* value = this->remove( attr );
    printf( "AccessControlList::set(...): removing\n" );
    delete value;
    result = false;
  }
  catch ( NoSuchElementException* ex )
  {
    delete ex;
    result = true;
  }

  // Be sure to clone the passed parameters for the map.
  //  
  this->map->put( new ObjectKey( attr.clone() ), rightsList.copy() );
  return result;
}

bool
AccessControlList::set( const SecurityAttribute* attr,
                        const RightsList*        rightsList )
{
  bool result = false;

  // If the attribute already exists in the ACL remove all trace
  // of its existance.
  //
  try
  {
    RightsList* value = this->remove( *attr );
    printf( "AccessControlList::set(...): removing\n" );
    delete value;
    result = false;
  }
  catch ( NoSuchElementException* ex )
  {
    delete ex;
    result = true;
  }

  // Be sure to clone the passed parameters for the map.
  //
  const Object* obj = rightsList;
  
  this->map->put( new ObjectKey( attr ), const_cast<Object*>( obj ) );
  return result;
}

RightsList*
AccessControlList::remove( const SecurityAttribute& attr )
throw (NoSuchElementException*)
{
  return (RightsList*) this->map->removeValue( attr );
}

const RightsList&
AccessControlList::get( const SecurityAttribute& attr ) const
throw (NoSuchElementException*)
{
  return (RightsList&) this->map->getValue( attr );
}

Iterator*
AccessControlList::keys() const
{
  return this->map->keys();
}
