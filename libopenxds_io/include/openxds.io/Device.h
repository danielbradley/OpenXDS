/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_DEVICE_H
#define OPENXDS_IO_DEVICE_H

#include <openxds/Object.h>
#include <openxds/ICloneable.h>
#include <openxds.io.h>

namespace openxds {
	namespace io {

class Device : public openxds::Object, openxds::ICloneable
{
public:
  Device( unsigned long long int deviceSerialNumber );
  virtual ~Device();
  openxds::Object* clone() const;
  bool equals( const openxds::Object& anObject ) const;
private:
  unsigned long long int serialNumber;
};

};};

#endif
