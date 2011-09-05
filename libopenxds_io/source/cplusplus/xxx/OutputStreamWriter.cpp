/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/io/OutputStreamWriter.h>

#include <openxds/base/String.h>
#include <openxds/io/OutputStream.h>
#include <openxds/io/IOException.h>

using namespace openxds::base;
using namespace openxds::io;

OutputStreamWriter::OutputStreamWriter( const OutputStream& ostream )
{
  this->isReference = true;
  this->os = (OutputStream*) &ostream;
}

OutputStreamWriter::OutputStreamWriter( OutputStream* ostream )
{
  this->isReference = false;
  this->os = ostream;
}

OutputStreamWriter::~OutputStreamWriter() throw (IOException*)
{
  if ( false == this->isReference ) {
    delete this->os;
  }
}

void
OutputStreamWriter::print( const openxds::base::String* s ) const
throw (IOException*)
{
  this->print( s->getChars(), s->getLength() );
}

void
OutputStreamWriter::print( const char* characters, unsigned int count ) const
throw (IOException*)
{
  this->os->write( (byte*)characters, 0, count );
}  

void
OutputStreamWriter::println() const
{
  this->os->write( (byte) EOL );
}

void
OutputStreamWriter::println( const openxds::base::String* s ) const
throw (IOException*)
{
  this->print( s );
  this->println();
}

void
OutputStreamWriter::println( const char* characters, unsigned int count ) const
throw (IOException*)
{
  this->print( characters, count );
  this->println();
}

void
OutputStreamWriter::close()
{
  this->os->close();
}

void
OutputStreamWriter::flush() const
{
  this->os->flush();
}

void
OutputStreamWriter::write( const char* characters,
                           unsigned int offset,
                           unsigned int count ) const
throw (IOException*)
{
  this->os->write( (const byte*) characters, offset, count );
}

void
OutputStreamWriter::write( char character ) const
throw (IOException*)
{
  this->os->write( (byte) character );
}

void
OutputStreamWriter::write( const String* str,
                           unsigned int offset,
                           unsigned int count ) const
throw (IOException*)
{
  const char* cbuf = str->getChars();
  this->os->write( (const byte*) cbuf, offset, count );
}

Object*
OutputStreamWriter::clone() const
{
  return new OutputStreamWriter( (OutputStream*) this->os->clone() );
}
