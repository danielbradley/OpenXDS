/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/OutputStream.h>

#include <openxds/Exception.h>
#include <openxds.io/File.h>
#include <openxds.io/IEndPoint.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.core.base/CharString.h>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

using namespace openxds::base;
using namespace openxds::core::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

OutputStream::OutputStream()
{
  this->isReference = false;
  this->ioEndPoint = null;
}

OutputStream::OutputStream( IEndPoint& io )
{
  this->isReference = true;
  this->ioEndPoint  = &io;
}

OutputStream::OutputStream( IEndPoint* io )
{
  this->isReference = false;
  this->ioEndPoint  = io;
}

/*
 *  Note: See note for similar constructor for InputStream. <p>
 *
 * OutputStream::OutputStream( const IOEndPoint* io )
 * {
 *   //  Note: dynamic cast is needed here because
 *   //  we are casting across the inheritance
 *   //  hierarchy from Object* to IOEndPoint
 *   //
 *   //          Interface
 *   //              |
 *   //  Object IOEndPoint
 *   //     |   /
 *   //     File
 * 
 *   this->ioEndPoint = dynamic_cast<IOEndPoint*>( io->clone() );
 *   if ( null == this->ioEndPoint )
 *   {
 *     throw new Exception( "Arg" );
 *   }
 * }
 *
 */

OutputStream::~OutputStream()
{
	if ( this->ioEndPoint && !this->isReference )
	{
		delete this->ioEndPoint;
	}
}

bool
OutputStream::open()
{
	return true;
}

void
OutputStream::write( const byte value ) const
throw (IOException*)
{
  byte buf[1];
  buf[0] = value;
  this->write( buf, 0, 1 );
}

void
OutputStream::write( const    byte* buf,
                     long   offset,
                     long   nrToWrite ) const
throw (IOException*)
{
  //const byte* posn = &buf[offset];
  const byte* posn = buf;
  this->ioEndPoint->write( posn, nrToWrite );
}

void
OutputStream::write( const char* format, ... ) const
throw (IOException*)
{
	va_list ap;
	va_start( ap, format );
	
	char* str = new_CharString_format_valist( format, ap );
	unsigned int written = CharString_getLength( str );
	this->write( str, 0, written );
	free_CharString( str );
	
	va_end( ap );
}

void
OutputStream::close() const
{
  if ( false == this->isReference ) {
    this->ioEndPoint->close();
  }
}

void
OutputStream::flush() const throw (IOException*)
{
  this->ioEndPoint->flush();
}

openxds::Object*
OutputStream::clone() const
{  
  return new OutputStream( (IEndPoint*) this->ioEndPoint->clone() );
}

IEndPoint&
OutputStream::getIOEndPoint()
{
	return *this->ioEndPoint;
}

const IEndPoint&
OutputStream::getIOEndPoint() const
{
	return *this->ioEndPoint;
}

