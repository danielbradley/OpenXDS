/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/PrintWriter.h>

#include <openxds.base/FormattedString.h>
#include <openxds.base/Runtime.h>
#include <openxds.io/OutputStream.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.core.base/CharString.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

using namespace openxds::base;
using namespace openxds::core::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

PrintWriter::PrintWriter( OutputStream& ostream ) : os( ostream )
{
	this->isReference = true;
	
	this->os.open();
}

PrintWriter::PrintWriter( OutputStream* ostream ) : os( *ostream )
{
	this->isReference = false;

	this->os.open();
}

PrintWriter::~PrintWriter()
{
	this->flush();
	this->close();
	if ( false == this->isReference )
	{
		delete &this->os;
	}
}

//
//  Print Implementation
//

void PrintWriter::print( const openxds::base::String* s ) const
throw (IOException*)
{
  this->print( s->getChars(), s->getLength() );
}

void PrintWriter::print( const openxds::base::String& s ) const
throw (IOException*)
{
  this->print( s.getChars(), s.getLength() );
}

void PrintWriter::print( String* s ) const
throw (IOException*)
{
  this->print( s->getChars(), s->getLength() );
  delete s;
}

void PrintWriter::print( const char* characters ) const
throw (IOException*)
{
  String s( characters );
  this->write( s.getChars(), 0, s.getLength() );
  //this->write( characters, 0, strlen( characters ) );
}  

void PrintWriter::print( const char* characters, long count ) const
throw (IOException*)
{
  this->write( characters, 0, count );
}  

//
//	error: generic thunk code fails for method
//	‘virtual void openxds::io::PrintWriter::printf(const char*, ...) const’ which uses ‘...’
//
void
PrintWriter::printf( const char* format, ... ) const
{
	va_list ap;
	va_start( ap, format );
	{
		int written;
		int size = 10;
		char* self = (char*) Runtime::calloc( size, sizeof( char ) );

		written = vsnprintf( self, size, format, ap );
		va_end(ap);

		if ( written >= size )
		{
			va_start(ap,format);

			CRuntime_free( self );
			self = (char*) Runtime::calloc( written + 1, sizeof( char ) );
			written = vsnprintf( self, written + 1, format, ap );
			
			va_end(ap);
		}

		this->print( self, CharString_getLength( self ) );
		free_CharString( self );
	}
}

void PrintWriter::println() const
{
  this->write( (char) EOL );
}

void PrintWriter::printlnDos() const
{
	this->write( '\r' ); //13
	this->write( '\n' ); //10
}

void PrintWriter::printlnMac() const
{
	this->write( '\r' );
}

void PrintWriter::printlnUnix() const
{
	this->write( '\n' );
}

void PrintWriter::println( const openxds::base::String* s ) const
throw (IOException*)
{
  this->print( s );
  this->println();
}

void PrintWriter::println( const openxds::base::String& s ) const
throw (IOException*)
{
  this->print( s );
  this->println();
}

void PrintWriter::println( String* s ) const
throw (IOException*)
{
  this->print( s );
  this->println();
}

void PrintWriter::println( const char* characters ) const
throw (IOException*)
{
  this->print( characters );
  this->println();
}

void PrintWriter::println( const char* characters, long count ) const
throw (IOException*)
{
  this->print( characters, count );
  this->println();
}

//
//  Writer Implementation
//

void PrintWriter::close()
throw (IOException*)
{
  if ( false == isReference ) {
    this->os.close();
  }
}

void PrintWriter::flush() const
throw (IOException*)
{
  this->os.flush();
}
  
void
PrintWriter::write( const char* characters, long offset, long count ) const
throw (IOException*)
{
  this->os.write( (const byte*) characters, offset, count );
}

void
PrintWriter::write( char character ) const
throw (IOException*)
{
  this->os.write( (byte) character );
}

void
PrintWriter::write( const String* str, long offset, long count ) const
throw (IOException*)
{
  const char* cbuf = str->getChars();
  this->write( cbuf, offset, count );
}

OutputStream&
PrintWriter::getOutputStream()
{
	return this->os;
}

const OutputStream&
PrintWriter::getOutputStream() const
{
	return this->os;
}

openxds::Object*
PrintWriter::clone() const
{
  return new PrintWriter( dynamic_cast<OutputStream*>( this->os.clone() ) );
}
