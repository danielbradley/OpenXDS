/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENOCL_IO_IO_H_
#define _OPENOCL_IO_IO_H_

#include <openxds/base.h>
#include <openxds/io.h>
//#include <openxds/io/File.h>
//#include <openxds/io/OutputStream.h>
//#include <openxds/io/PrintWriter.h>

namespace openxds {
  namespace io {

class IO
{
public:

  static InputStream& in();
  static Printer&     out();
  static Printer&     err();

  static InputStream* createIn();
  static Printer*     createOut();
  static Printer*     createErr();

  static InputStream& IN;
  static Printer&     OUT;
  static Printer&     ERR;
};

};};

#endif
