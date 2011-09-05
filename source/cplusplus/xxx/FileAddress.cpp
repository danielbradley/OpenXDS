/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/io/FileAddress.h>

#include <openxds/base/Object.h>
#include <openxds/base/String.h>
#include <openxds/io/FileSystem.h>

using namespace openxds::base;
using namespace openxds::io;

FileAddress::FileAddress( const FileSystem& hostFileSystem,
                          unsigned long fileSerialNumber )
{
  this->fileSystem = (FileSystem*) hostFileSystem.clone();
  this->serialNumber = fileSerialNumber;
}

FileAddress::~FileAddress()
{
  delete this->fileSystem;
}

const FileSystem&
FileAddress::getFileSystem() const
{
  return *this->fileSystem;
}

unsigned long
FileAddress::getSerialNumber() const
{
  return this->serialNumber;
}

const Device&
FileAddress::getDevice() const
{
  return this->fileSystem->getDevice();
}

bool
FileAddress::equals( const Object& anObject ) const
{
  const FileAddress* address = dynamic_cast<const FileAddress*>( &anObject );
  if ( null == address ) {
    return false;
  } else {
    return this->equals( (const Address&) *address );
  }
}

bool
FileAddress::equals( const Address& anAddress ) const
{
  bool equal = false;
  const FileAddress* address = dynamic_cast<const FileAddress*>( &anAddress );
  if ( null != address )
  {
    if ( this->fileSystem->equals( *address->fileSystem ) )
    {
      equal = ( this->serialNumber == address->serialNumber ); 
    }
  }
  return equal;
}

Object*
FileAddress::clone() const
{
  return new FileAddress( *this->fileSystem, this->serialNumber );
}

String*
FileAddress::toString() const
{
  // XXX
  return new String( "FileAddress::toString not implemented" );
}
