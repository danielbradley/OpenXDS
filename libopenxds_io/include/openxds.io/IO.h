/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_IO_H
#define OPENXDS_IO_IO_H

#include <openxds.io.h>

namespace openxds {
  namespace io {

class IO
{
public:

  static InputStream&  in();
  static PrintWriter& out();
  static PrintWriter& err();

  static InputStream*  createIn();
  static PrintWriter* createOut();
  static PrintWriter* createErr();

  static InputStream&  IN;
  static PrintWriter& OUT;
  static PrintWriter& ERR;
};

};};

#endif
