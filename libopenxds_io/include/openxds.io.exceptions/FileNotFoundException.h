/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_FILENOTFOUNDEXCEPTION_H
#define OPENXDS_IO_FILENOTFOUNDEXCEPTION_H

#include <openxds.io.exceptions/IOException.h>
#include <openxds.base.h>

namespace openxds {
	namespace io {
		namespace exceptions {

class FileNotFoundException : public IOException
{
public:
  virtual ~FileNotFoundException() {};
  
  virtual const char* getType() const { return "FileNotFoundException"; }
};

};};};

#endif
