/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/Device.h>

#include <openxds/Object.h>

using namespace openxds;
using namespace openxds::io;

Device::Device( unsigned long long int deviceSerialNumber )
{
  this->serialNumber = deviceSerialNumber;
}

Device::~Device()
{}

Object*
Device::clone() const
{
  return new Device( this->serialNumber );
}

bool
Device::equals( const Object& anObject ) const
{
	const Device* dev = dynamic_cast<const Device*>( &anObject );
	if ( null != dev )
	{
		return ( this->serialNumber == dev->serialNumber );
	}
	else
	{
		return false;
	}
}
