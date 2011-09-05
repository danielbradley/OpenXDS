/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENOCL_IO_FILEDESCRIPTORPSA_H_
#define _OPENOCL_IO_FILEDESCRIPTORPSA_H_

#include <openxds/types.h>

#include <openxds/base.h>
#include <openxds/io.h>
#include <openxds/security.h>

namespace openxds {
  namespace io {

/**
 *  Class FileDescriptorPSA (Platform Specific Adapter)
 */
class FileDescriptorPSA
{
public:
  // Modes
  static const int READ_ONLY;
  static const int WRITE_ONLY;
  static const int READ_WRITE;

  // Special
  static const int APPEND;
  static const int CREATE;

  // Standard File Descriptor Values
  static const int FileDescriptorPSA::IN;
  static const int FileDescriptorPSA::OUT;
  static const int FileDescriptorPSA::ERR;

  static FileDescriptor*
  Create( const openxds::base::String* filePath, int MODE, int FLAGS )
  throw ( openxds::security::AccessException*,
          FileAlreadyExistsException*,
          IOException* );

  static FileDescriptor*
  Open( const openxds::base::String* filePath, int FLAGS )
  throw ( openxds::security::AccessException*,
          FileNotFoundException*,
          IOException* );

  static void Close( const FileDescriptor* fd ) throw (IOException*);

private:
  static FileDescriptor*
  Open( const openxds::base::String* filePath, int FLAGS, int MODE )
  throw ( openxds::security::AccessException*,
          FileAlreadyExistsException*,
          FileNotFoundException*,
          IOException* );
  
  //static unsigned int
  //Open( const openxds::base::String* filePath,
  //      int FLAGS )
  //    throw (IOException*);
};

};};

#endif // _OPENOCL_IO_FILEDESCRIPTORPSA_H_
