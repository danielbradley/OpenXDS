/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENOCL_IO_FILESYSTEM_H_
#define _OPENOCL_IO_FILESYSTEM_H_

#include <openxds/base/Object.h>

#include <openxds/io.h>

namespace openxds {
  namespace io {

class FileSystem : public openxds::base::Object
{
public:
  FileSystem( const Device& hostDevice );
  virtual ~FileSystem();

  const Device& getDevice() const;

  bool equals( const openxds::base::Object& anObject ) const;
  virtual openxds::base::Object* clone() const;


private:
  Device* device;
};

};};

#endif
