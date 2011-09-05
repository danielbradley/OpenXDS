/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/PrintWriter.h>

#include <openxds.base/String.h>
#include <openxds.io/OutputStream.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.core.base/CharString.h>

//#include <cstdarg>

using namespace openxds::base;
using namespace openxds::core::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

PrintWriter::PrintWriter( const OutputStream& ostream )
{
  this->isReference = true;
  this->os = (OutputStream*) &ostream;
}

PrintWriter::PrintWriter( const OutputStream* ostream )
{
 // IO::out().println( "PrintWriter( const OutputStream* )" );

  this->isReference = true;
  this->os = (OutputStream*) ostream;
}

PrintWriter::PrintWriter( OutputStream* ostream )
{
  this->isReference = false;
  this->os = ostream;
}

PrintWriter::~PrintWriter() throw (IOException*)
{
	this->flush();
	this->close();
	if ( false == this->isReference )
	{
		delete this->os;
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

void PrintWriter::print( const char* characters, unsigned int count ) const
throw (IOException*)
{
  this->write( characters, 0, count );
}  

void
PrintWriter::printf( const char* format, ... ) const
{
	va_list ap;
	va_start( ap, format );
	
	char* str = new_CharString_format_valist( format, ap );
	this->print( str, CharString_getLength( str ) );
	free_CharString( str );
	
	va_end( ap );
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

void PrintWriter::println( const char* characters, unsigned int count ) const
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
    this->os->close();
  }
}

void PrintWriter::flush() const
throw (IOException*)
{
  this->os->flush();
}
  
void
PrintWriter::write( const char* characters, unsigned int offset, unsigned int count ) const
throw (IOException*)
{
  this->os->write( (const byte*) characters, offset, count );
}

void
PrintWriter::write( char character ) const
throw (IOException*)
{
  this->os->write( (byte) character );
}

void
PrintWriter::write( const String* str, unsigned int offset, unsigned int count ) const
throw (IOException*)
{
  const char* cbuf = str->getChars();
  this->os->write( (const byte*) cbuf, offset, count );
}

openxds::Object*
PrintWriter::clone() const
{
  return new PrintWriter( (OutputStream*) this->os->clone() );
}
