/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/FileOutputStream.h>
#include <openxds.io/File.h>

#include <openxds.base/Runtime.h>
#include <openxds/Exception.h>
#include <stdio.h>

using namespace openxds::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

FileOutputStream::FileOutputStream( void* stream ) : OutputStream( new File( stream ) )
{
	this->flags = new String( "w" );
}

FileOutputStream::FileOutputStream( File& targetFile ) : OutputStream( targetFile )
{
	this->flags = new String( "w" );
}

FileOutputStream::FileOutputStream( File* targetFile ) : OutputStream( targetFile )
{
	this->flags = new String( "w" );
}

FileOutputStream::FileOutputStream( File* targetFile, const char* flags ) : OutputStream( targetFile )
{
	this->flags = new String( flags );
}

FileOutputStream::~FileOutputStream()
{
	delete this->flags;
}

bool
FileOutputStream::open()
{
	bool status = false;

	try
	{
		const File* f = dynamic_cast<const File*>( &this->getIOEndPoint() );
		if ( f )
		{
			status = ((File*) f)->open( this->flags->getChars() );
		}
	}
	catch ( IOException* ex )
	{
		delete ex;
	}

	return status;
}
