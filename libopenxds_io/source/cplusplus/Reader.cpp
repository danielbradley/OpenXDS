/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/Reader.h>
#include <openxds.io/InputStream.h>
#include <openxds.io.exceptions/IOException.h>

using namespace openxds::io;
using namespace openxds::io::exceptions;

const int Reader::EOS = OPENXDS_IO_EOS;

Reader::Reader()
{}

Reader::~Reader()
{}

long
Reader::read() throw (IOException*)
{
  char cbuf[1];
  long c = this->readInto( cbuf, 0, 1 );
  if ( EOS != c )
  {
    c = (int) cbuf[0];
  }
  return c;
}

long
Reader::skip( long n ) throw (IOException*)
{
	char* cbuf = new char[n];
	long read = this->readInto( cbuf, 0, n );
	delete cbuf;
	return read;
}
 
