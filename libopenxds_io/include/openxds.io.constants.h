/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENXDS_IO_CONSTANTS_H_
#define _OPENXDS_IO_CONSTANTS_H_

#include <fcntl.h>

namespace openxds {
  namespace io {

static const unsigned int OPENXDS_IO_EOF = 0;
static const int OPENXDS_IO_EOS = -1;
//static const int OPENXDS_IO_EOS = 0;

static const int OPENXDS_IO_READ_ONLY                = O_RDONLY;
static const int OPENXDS_IO_WRITE_ONLY               = O_WRONLY;
static const int OPENXDS_IO_READ_WRITE               = O_RDWR;
static const int OPENXDS_IO_APPEND                   = O_APPEND;
static const int OPENXDS_IO_CREATE                   = O_CREAT;

/*
static const int OPENXDS_IO_READ_ONLY                = 0x00000001;
static const int OPENXDS_IO_WRITE_ONLY               = 0x00000002;
static const int OPENXDS_IO_READ_WRITE               = 0x00000003;
static const int OPENXDS_IO_APPEND                   = 0x00000004;
static const int OPENXDS_IO_CREATE                   = 0x00000008;
*/
static const int OPENXDS_IO_DATA_SYNC                = 0x00000010;
static const int OPENXDS_IO_EXCLUSIVE                = 0x00000020;
static const int OPNEOCL_IO_NON_CONTROLLING_TERMINAL = 0x00000040;
static const int OPENXDS_IO_NON_BLOCKING             = 0x00000080;
static const int OPENXDS_IO_NON_DELAYING             = 0x00000100;
static const int OPENXDS_IO_RSYNC                    = 0x00000200;
static const int OPENXDS_IO_SYNC                     = 0x00000400;
static const int OPENXDS_IO_TRUNC                    = 0x00000800;

static const int OPENXDS_IO_ACCESS_ALLOWED = 0;
static const int OPENXDS_IO_ACCESS_DENIED  = 1;
static const int OPENXDS_IO_FILE_NOT_FOUND = 2;
static const int OPENXDS_IO_IO_EXCEPTION   = 3;

static const int OPENXDS_IO_IN = 0;
static const int OPENXDS_IO_OUT = 1;
static const int OPENXDS_IO_ERR = 2;

};};

#endif
