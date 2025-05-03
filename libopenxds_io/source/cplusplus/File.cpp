/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

//#include <openxds/base/ImplementationException.h>
//#include <openxds/base/String.h>
//#include <openxds/base/System.h>
//#include <openxds/io/Address.h>
////#include <openxds/io/Descriptor.h>
//#include <openxds/io/Device.h>
//#include <openxds/io/FileAddress.h>
//#include <openxds/io/FileAlreadyExistsException.h>
////#include <openxds/io/FileDescriptor.h>
////#include <openxds/io/FileDescriptorPSA.h>
//#include <openxds/io/FileNotFoundException.h>
//#include <openxds/io/IOException.h>
////#include <openxds/io/IOPSA.h>
////#include <openxds/io/FilePSA.h>
//#include <openxds/io/Path.h>
//#include <openxds/io/RaceConditionException.h>
//#include <openxds/io/Statistics.h>
////#include <openxds/io/StatPSA.h>
//#include <openxds/security/AccessException.h>
//
//#include <openxds/io_constants.h>
//#include <openxds/io/psa/File.h>
//#include <openxds/io/psa/Path.h>

#include "openxds.io/File.h"
#include "openxds.io/Path.h"
#include "openxds.io.exceptions/IOException.h"
#include <openxds.base/Runtime.h>
#include <openxds.exceptions/ImplementationException.h>
#include <openxds.core.io/File.h>


using namespace openxds::base;
using namespace openxds::core::io;
using namespace openxds::exceptions;
using namespace openxds::io;
using namespace openxds::io::exceptions;
using namespace openxds::security::exceptions;

//
//  Public Constants
//

const int File::READ_ONLY  = OPENXDS_IO_READ_ONLY;
const int File::WRITE_ONLY = OPENXDS_IO_WRITE_ONLY;
const int File::READ_WRITE = OPENXDS_IO_READ_WRITE;

//
//  Private Constants
//

const int File::ACCESS_ALLOWED = OPENXDS_IO_ACCESS_ALLOWED;
const int File::ACCESS_DENIED  = OPENXDS_IO_ACCESS_DENIED;
const int File::FILE_NOT_FOUND = OPENXDS_IO_FILE_NOT_FOUND;
const int File::IO_EXCEPTION   = OPENXDS_IO_IO_EXCEPTION;

File::File( const char* location )
{
	this->path = new Path( location );
	this->native = new_File( this->path->getPreferred().getChars() );
	this->openState = null;
//	this->fileAddress = null;
}

File::File( const String& location )
{
	this->path = new Path( location );
	this->native = new_File( this->path->getPreferred().getChars() );
	this->openState = null;
//	this->fileAddress = null;
}

File::File( const Path& path )
{
	this->path = new Path( path );
	this->native = new_File( this->path->getPreferred().getChars() );
	this->openState = null;
//	this->fileAddress = null;
}

File::File( Path* path )
{
	this->path = path;
	this->native = new_File( this->path->getPreferred().getChars() );
	this->openState = null;
//	this->fileAddress = null;
}

static Path* createFromNative( const IPath* native_path )
{
	return new Path( native_path->getCommon( native_path ) );
}

File::File( flags standardStream )
{
	this->native       = File_GetFileForStandardDescriptor( standardStream );
	this->path         = createFromNative( this->native->getPath( this->native ) );
	this->openState = null;
//	this->fileAddress = null;
}

File::File( void* stream )
throw (IOException*)
{
	this->native = File_GetFileForStream( stream );
	if ( this->native )
	{
		this->path = createFromNative( this->native->getPath( this->native ) );
		this->openState = null;
//		this->fileAddress = null;
	} else {
		throw new IOException( "invalid stream" );
	}
}

File::~File()
{
  //  This shouldn't be needed as it is handled by the
  //  deletion of the file descriptor itself.
  //
  //  if ( this->isOpen() )
  //  {
  //    this->close();
  //  }
  if ( this->native ) this->native = this->native->free( this->native );
  if ( this->openState ) delete this->openState;
  if ( this->path ) delete this->path;
//  if ( this->fileAddress ) delete this->fileAddress;
} 

//
// *  This attempts to initialize the inode information for this
// *  file by calling stat. This is designed to fail silently,
// *  indicating the reason in the "state" member. <p>
// *
void
File::initialize()
{
}

//-----------------------------------------------------
//  IOEndPoint Methods
//-----------------------------------------------------

//void
//File::applyACL( const AccessControlList& acl )
//throw (AccessException*, IOException*)
//{
//  throw new ImplementationException( "Not Implemented" );
//}
//
//void
//File::control( int command, const openxds::base::String* args[] )
//throw (IOException*)
//{
//  throw new ImplementationException( "Not Implemented" );
//}
//
//unsigned int
//File::seek( unsigned int offset, unsigned int whence )
//throw (IOException*)
//{
//  throw new ImplementationException( "Not Implemented" );
//}
//
//IOEndPoint*
//File::duplicate() const
//throw (IOException*)
//{
//  throw new ImplementationException( "Not Implemented" );
//}
//
//const Address&
//File::getAddress() const
//{
//  return *this->fileAddress;
//}

//const Descriptor&
//File::getDescriptor() const
//{
//  return *this->fd;
//}

//const Device&
//File::getDevice() const
//{
//  return this->fileAddress->getDevice();
//}

//-----------------------------------------------------
//  File Methods
//-----------------------------------------------------

const String&
File::getCanonicalName() const
{
  return this->path->getCanonical();
}

//void
//File::create( int FLAGS, int MODE )
//throw ( AccessException*,
//        FileAlreadyExistsException*,  
//        IOException*,
//        RaceConditionException* )
//{
//	if ( 0 == File_create( (IFile*) this->native ) )
//	{
//		throw new IOException();
//	}
//}

bool
File::open( const char* access )
throw ( AccessException*,
        FileNotFoundException*,
        IOException*,
        RaceConditionException* )
{
	bool status = false;

	if ( this->native->open( this->native, access ) )
	{
		delete this->openState;
		this->openState = new String( access );
		status = true;
	} else {
		//IO::err().printf( "Could not open: %s for mode: %s\n", this->getCanonicalName().getChars(), access );
		//throw new IOException();
	}
	
	return status;
}

//void
//File::open( int FLAGS )
//throw ( AccessException*,
//        FileNotFoundException*,
//        IOException*,
//        RaceConditionException* )
//{
//	throw new ImplementationException( "Not Implemented" );
//	//File_open( (IFile*) this->native, access );
//}

void
File::flush() const
throw (IOException*)
{
	this->native->flush( this->native );
}

void
File::close()
{
	if ( this->native )
	{
		if ( this->native->close( this->native ) )
		{
			delete this->openState;
			this->openState = null;
		}
		else
		{
			//	Removed throwing of exception, what can the user code do about a file not closing?
			//	Is this a user code issue?
		}
	}
}

bool
File::remove()
{
	bool status = false;
	if ( this->native->deleteFile( this->native ) )
	{
		status = true;
	}
	return status;
}

long
File::read( byte* buffer, long bufferSize ) const
throw (IOException*)
{
	long nr_read = this->native->read( this->native, buffer, bufferSize );

	if ( 0 == nr_read )
	{
		if ( !this->native->isEOF( this->native ) )
		{
			throw new IOException();
		} else {
			nr_read = OPENXDS_IO_EOF;
		}
	}

	return nr_read;
}

long
File::write( const byte* buffer, long bufferSize ) const
throw (IOException*)
{
	return this->native->write( this->native, buffer, bufferSize );
}

//AccessControlList*
//File::retrieveACL() const
//throw (IOException*)
//{
//  return this->stat->acl;
//}

//const FileDescriptor& File::getFileDescriptor() const
//{
//  return *this->fd;
//}

bool File::exists() const
{
	return this->native->exists( this->native );
}

bool File::canExecute() const
{
  return false;
}

bool File::isOpen() const
{
	return this->native->isOpen( (IFile*) this->native );
}

// *
// *  Note: This method may return a File object with
// *  updated information. <p>
// *
openxds::Object*
File::clone() const
{
	File* f = new File( this->getCanonicalName() );
//	if ( this->isOpen() && this->openState )
//	{
//		f->open( this->openState->getChars() );
//	}
	return f;
}
