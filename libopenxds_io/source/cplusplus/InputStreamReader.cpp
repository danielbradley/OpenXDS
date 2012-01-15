/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/InputStreamReader.h>
#include <openxds.io/InputStream.h>
#include <openxds.io.exceptions/IOException.h>

using namespace openxds::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

InputStreamReader::InputStreamReader( const InputStream& in )
{
  this->isReference = true;
  this->istream = (InputStream*) &in;
}

InputStreamReader::InputStreamReader( InputStream* in )
{
  this->isReference = false;
  this->istream = in;
}

InputStreamReader::~InputStreamReader()
{
  if ( false == this->isReference )
  {
    this->istream->close();
    delete this->istream;
  }
}

long
InputStreamReader::readInto( char* cbuf, long offset, long len )
throw (IOException*)
{
  return this->istream->read( (byte*) cbuf, offset, len );
}

void InputStreamReader::close()
{
  if ( false == this->isReference ) {
    this->istream->close();
  }
}
