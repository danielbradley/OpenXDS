/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.io/IOBuffer.h"

#include "openxds.io.exceptions/WouldBlockException.h"
#include "openxds.io.exceptions/IOException.h"

#include <openxds.base/DynamicBuffer.h>
#include <openxds.base/Runtime.h>

using namespace openxds::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

IOBuffer::IOBuffer()
{
  this->buffer = new DynamicBuffer();
  this->closed = false;

//  Device dev( 0 );
//  FileSystem fs( dev );
//  this->address = new FileAddress( fs, 0 );
//	this->descriptor = new FileDescriptor( 0 );
}

IOBuffer::IOBuffer( const String& str )
{
	this->buffer = new DynamicBuffer();
	this->closed = false;
	this->write( (byte*) str.getChars(), str.getLength() );

//  Device dev( 0 );
//  FileSystem fs( dev );
//  this->address = new FileAddress( fs, 0 );
//	this->descriptor = new FileDescriptor( 0 );
}

IOBuffer::~IOBuffer()
{
  delete this->buffer;
//  delete this->address;
}

long
IOBuffer::read( byte* buffer, long bufferSize ) const
throw (IOException*)
{
	if ( this->closed && this->buffer->isEmpty() ) {
		return XEOF;
	}

	long i;
	for( i=0; i < bufferSize; i++ )
	{
		if ( this->buffer->isNotEmpty() ) {
			buffer[i] = this->buffer->read();
		} else {
			break;
		}
	}
	return i;
}

long
IOBuffer::write( const byte* buffer, long count ) const
throw (IOException*)
{
  long i;
  for ( i=0; i < count; i++ ) {
    this->buffer->write( buffer[i] );
  }
  return i;
}

//void
//IOBuffer::applyACL( const AccessControlList& acl )
//throw (AccessException*, IOException*)
//{}
//
//void
//IOBuffer::control( int command, const String* args[] )
//throw (IOException*)
//{}
//
//unsigned int
//IOBuffer::seek( unsigned int offset, unsigned int whence )
//{
//  return 0;
//}

void
IOBuffer::flush() const
throw (IOException*)
{}

void
IOBuffer::close() throw (IOException*)
{
  this->closed = true;
}

IEndPoint*
IOBuffer::duplicate() const
throw (IOException*)
{
  IOBuffer* iob = new IOBuffer();
  delete iob->buffer;
  iob->buffer = this->buffer->copy();

  return iob;
}

openxds::Object*
IOBuffer::clone() const
{
  return dynamic_cast<Object*>( this->duplicate() );
}

String*
IOBuffer::toString() const
{
  return this->buffer->toString();
}

//const Address&
//IOBuffer::getAddress() const
//{
//  return *this->address;
//}

//const Descriptor&
//IOBuffer::getDescriptor() const
//{
//  return *this->descriptor;
//}

//const Device&
//IOBuffer::getDevice() const
//{
//  return this->address->getFileSystem().getDevice();
//}

//bool
//IOBuffer::equals( const IOBuffer& buf ) const
//{
//	bool ret = false;
//	String* this_buf = this->toString();
//	String* other_buf = buf.toString();
//
//	if ( 0 == this_buf->compareTo( *other_buf ) )
//	{
//		ret = true;
//	}
//
//	delete this_buf;
//	delete other_buf;
//
//	return ret;
//}
