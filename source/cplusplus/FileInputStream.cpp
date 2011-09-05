/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/FileInputStream.h>
#include <openxds.io/File.h>

//#include <openxds/base/String.h>
//#include <openxds/io/FileNotFoundException.h>
//#include <openxds/io/IO.h>
//#include <openxds/io/IOException.h>

using namespace openxds::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

FileInputStream::FileInputStream( void* stream )
throw (IOException*) : InputStream( new File( stream ) )
{}

FileInputStream::FileInputStream( const File& inputFile )
throw (FileNotFoundException*)
: InputStream( inputFile ) 
{
	this->open();
}

FileInputStream::FileInputStream( File* inputFile )
throw (FileNotFoundException*)
: InputStream( inputFile )
{
	this->open();
}

FileInputStream::~FileInputStream()
{
}

void
FileInputStream::open()
throw (IOException*)
{
	File* f = dynamic_cast<File*>( &this->getIEndPoint() );
	if ( null == f ) {
	throw new IOException( "invalid IOEndPoint" );
	}

	f->open( "rb" );
}
