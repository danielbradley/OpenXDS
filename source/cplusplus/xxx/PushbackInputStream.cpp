/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/io/PushbackInputStream.h>

#include <openxds/base/Debug.h>
#include <openxds/base/String.h>
#include <openxds/io/InputStream.h>
#include <openxds/io/IOException.h>
#include <openxds/util/CircularByteBuffer.h>

using namespace openxds::base;
using namespace openxds::io;
using namespace openxds::util;

PushbackInputStream::PushbackInputStream( const InputStream& in )
{
	this->istream = null;
	this->buffer = null;

	this->isReference = true;
	this->istream = (InputStream*) &in;
	this->buffer = new CircularByteBuffer();
	Debug::returnedObject();	
}

PushbackInputStream::PushbackInputStream( InputStream* in )
{
	this->isReference = false;
	this->istream = in;
	this->buffer = new CircularByteBuffer();
	Debug::returnedObject();	
}

PushbackInputStream::~PushbackInputStream()
{
	if ( false == this->isReference )
	{
		delete this->istream;
		Debug::deletedObject();
	}
	if ( this->buffer )
	{
		delete this->buffer;
		Debug::deletedObject();
	}
}

int
PushbackInputStream::read() throw (IOException*)
{
	int ret;
	byte buf[1];
	int nrRead = this->read( buf, 0, 1 );

	if ( 0 == nrRead ) //EOS != c )
	{
		ret = EOS;
	} else {
		ret = buf[0];
	}
	return ret;
}

void
PushbackInputStream::unread( byte b ) throw (IOException*)
{
  byte buf[1];
  buf[0] = b;
  
  this->unread( buf, 0, 1 );
}

unsigned int
PushbackInputStream::read( byte* buf,
                           unsigned int offset,
                           unsigned int nrToRead )
throw (IOException*)
{
  // XXX Does not check size of buffer.
  
  unsigned int nrRead = 0;
  while ( (nrRead < nrToRead) && ( this->buffer->isNotEmpty() ) )
  {
    buf[ offset + nrRead ] = this->buffer->read();
    nrRead++;
  }

  int b = 0;
  while ( nrRead < nrToRead )
  {
    b = this->istream->read();
    if ( InputStream::EOS == b )
    {
      break;
    } else {
      buf[ offset + nrRead ] = b;
      nrRead++;
    }
  }
  
  return nrRead;
}  

void
PushbackInputStream::unread( const byte* buf,
                             unsigned int offset,
                             unsigned int nrToUnread )
throw (IOException*)
{
  // XXX Does not check size of buf.
  if ( ((unsigned int) nrToUnread) > this->buffer->space() )
  {
    throw new IOException( new String( "Not enough room in buffer" ) );
  }
  
  for ( int i= nrToUnread - 1; i >= 0; i-- )
  {
    this->buffer->unread( buf[ offset + i ] );
  }
}

void PushbackInputStream::close()
{
  if ( false == this->isReference ) {
    this->istream->close();
  }
}
