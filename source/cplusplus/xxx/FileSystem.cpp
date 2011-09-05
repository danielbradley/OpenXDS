/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/io/FileSystem.h>

#include <openxds/io/Device.h>

using namespace openxds::base;
using namespace openxds::io;

FileSystem::FileSystem( const Device& hostDevice )
{
  this->device = (Device*) hostDevice.clone();
}

FileSystem::~FileSystem()
{
  delete this->device;
}

const Device&
FileSystem::getDevice() const
{
  return *this->device;
}

bool
FileSystem::equals( const Object& anObject ) const
{
  bool equal = false;

  const FileSystem* fs = dynamic_cast<const FileSystem*>( &anObject );
  if ( null != fs )
  {
    equal = this->device->equals( *fs->device );
  } 
  return equal;
}

Object*
FileSystem::clone() const
{
  return new FileSystem( *this->device );
}
