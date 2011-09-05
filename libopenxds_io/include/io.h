/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_H
#define OPENXDS_IO_H

#include <openxds/types.h>
#include <openxds/global.h>

namespace openxds {
  namespace io {

static const bool IO_DEBUG = false;

class PUBLIC Address;
//class Descriptor;
class PUBLIC Device;
class PUBLIC Path;

class PUBLIC FileSystem;
class PUBLIC FileAddress;

class PUBLIC Statistics;

class PUBLIC IOEndPoint;
//class FileDescriptor;
class PUBLIC File;
class PUBLIC Directory;
class PUBLIC IOBuffer;

//class Stream;
class PUBLIC InputStream;
class PUBLIC PushbackInputStream;

class PUBLIC OutputStream;
class PUBLIC Reader;
class PUBLIC InputStreamReader;

class PUBLIC Writer;
class PUBLIC OutputStreamWriter;
class PUBLIC Printer;
class PUBLIC PrintWriter;
class PUBLIC UndeletablePrintWriter;
class PUBLIC LineParser;

class PUBLIC IO;
class PUBLIC FileInputStream;
class PUBLIC FileOutputStream;


class PUBLIC FileAlreadyExistsException;
class PUBLIC FileNotFoundException;
class PUBLIC IOException;
class PUBLIC RaceConditionException;

};};

#endif // _OPENOCL_IO_H_
