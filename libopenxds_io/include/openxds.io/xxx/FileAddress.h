/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENOCL_IO_FILEADDRESS_H_
#define _OPENOCL_IO_FILEADDRESS_H_

#include <openxds/base/Object.h>
#include <openxds/io/Address.h>

#include <openxds/io.h>

namespace openxds {
  namespace io {

class FileAddress : public openxds::base::Object, public Address
{
public:
  FileAddress( const FileSystem& hostFileSystem,
               unsigned long fileSerialNumber );
  virtual ~FileAddress();

  const FileSystem& getFileSystem() const;
  unsigned long getSerialNumber() const;
  const Device& getDevice() const;


  virtual bool equals( const openxds::base::Object& anObject ) const;
  bool equals( const Address& anAddress ) const;

  virtual openxds::base::Object* clone() const;
  virtual openxds::base::String* toString() const;

private:
  FileSystem* fileSystem;
  unsigned long serialNumber;
};

};};

#endif

