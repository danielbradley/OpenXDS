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

FileOutputStream::FileOutputStream( void* stream )
throw (IOException*) : OutputStream( new File( stream ) )
{}

FileOutputStream::FileOutputStream( File& targetFile )
throw (openxds::io::exceptions::IOException*)
: OutputStream( targetFile )
{
	this->open();
}

FileOutputStream::FileOutputStream( File* targetFile )
: OutputStream( targetFile )
{
  this->open();
}

FileOutputStream::~FileOutputStream() throw (IOException*)
{
}

void
FileOutputStream::open()
throw (IOException*)
{
	const File* f = dynamic_cast<const File*>( &this->getIOEndPoint() );
	if ( null == f )
	{
		throw new IOException( "invalid IOEndPoint" );
	}
	((File*) f)->open( "wb" );
}
