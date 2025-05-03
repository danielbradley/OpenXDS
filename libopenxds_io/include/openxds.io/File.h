/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_FILE_H
#define OPENXDS_IO_FILE_H

#include "openxds.io/IEndPoint.h"
#include "openxds.io.exceptions.h"
#include <openxds.io.exceptions/FileNotFoundException.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.io.exceptions/RaceConditionException.h>
#include "openxds.io.constants.h"
#include "openxds.io.h"
#include <openxds.security.exceptions/AccessException.h>
#include <openxds.core.io.h>
#include <openxds/Object.h>

namespace openxds {
	namespace io {

class File : public openxds::Object, public IEndPoint
{
public:

	static const flags STANDARD_IN  = 0;
	static const flags STANDARD_OUT = 1;
	static const flags STANDARD_ERROR = 2;

	static const int READ_ONLY;
	static const int WRITE_ONLY;
	static const int READ_WRITE;

	 File( const char* location );
	 File( const openxds::base::String& location );
	 File( const Path& path );
	 File( Path* path );
	 File( flags standardStream );
	 File( void* ioStream ) throw (openxds::io::exceptions::IOException*);
	~File();

	void initialize();

	//  IOEndPoint Methods

//	virtual void applyACL( const openxds::security::AccessControlList& acl )
//		throw (openxds::security::AccessException*, IOException*);
//
//	virtual void control( int command, const openxds::base::String* args[] )
//		throw (IOException*);
//
//	virtual unsigned int seek( unsigned int offset, unsigned int whence )
//		throw (IOException*);
//
//	virtual IOEndPoint* duplicate() const
//		throw (IOException*);
//
//	virtual const Address& getAddress() const;
//	//virtual const Descriptor& getDescriptor() const;
//	virtual const Device& getDevice() const;

  // File Methods

	const openxds::base::String& getCanonicalName() const;

  /**
   *  @throws FileAlreadyExistsException
   */
//  void create( int FLAGS, int MODE )
//      throw ( openxds::security::AccessException*,
//                                 FileAlreadyExistsException*,
//                                 IOException*,
//                                 RaceConditionException* );

	bool open( const char* access )
		throw ( openxds::security::exceptions::AccessException*,
			    openxds::io::exceptions::FileNotFoundException*,
                openxds::io::exceptions::IOException*,
                openxds::io::exceptions::RaceConditionException* );

  /**
   *  @throws FileNotFoundException
   */
//	void open( const char* access )
//		throw ( openxds::security::AccessException*,
//                        FileNotFoundException*,
//                        IOException*,
//                        RaceConditionException* );
//
//	void open( int FLAGS ) throw ( openxds::security::AccessException*,
//                                       FileNotFoundException*,
//                                       IOException*,
//                                       RaceConditionException* );

	virtual void flush() const
		throw (openxds::io::exceptions::IOException*);

	virtual void close();

	bool remove();

	long read( byte* buffer, long bufferSize ) const
		throw (openxds::io::exceptions::IOException*);

	long write( const byte* buffer, long count ) const
		throw (openxds::io::exceptions::IOException*);
  
//	openxds::security::AccessControlList*
//		retrieveACL() const 
//		throw (openxds::io::exceptions::IOException*);
  
	//const FileDescriptor& getFileDescriptor() const;

	bool exists() const;  
	bool canExecute() const;
	bool isOpen() const;

	virtual openxds::Object* clone() const;

private:

	static const int ACCESS_ALLOWED;
	static const int ACCESS_DENIED;
	static const int FILE_NOT_FOUND;
	static const int IO_EXCEPTION;

	openxds::core::io::IFile* native;
	openxds::base::String* openState;
	Path* path;

//	FileAddress* fileAddress;
//	Statistics* stat;

	int state;
};

};}; // end of openxds::io namespace scope.

#endif

