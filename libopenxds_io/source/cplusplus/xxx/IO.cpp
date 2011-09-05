/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/io/IO.h>

#include <openxds/io/File.h>
//#include <openxds/io/FileDescriptor.h>
#include <openxds/io/InputStream.h>
#include <openxds/io/IOException.h>
#include <openxds/io/OutputStream.h>
#include <openxds/io/OutputStreamWriter.h>
#include <openxds/io/PrintWriter.h>

using namespace openxds::io;

InputStream& IO::IN  = *createIn();
Printer&     IO::OUT = *createOut();
Printer&     IO::ERR = *createErr();

InputStream&
IO::in()
{
  return IO::IN;
}

Printer&
IO::out()
{
  return IO::OUT;
}

Printer&
IO::err()
{
  return IO::ERR;
}

Printer*
IO::createOut()
{
	File* file = new File( File::STANDARD_OUT );
	OutputStream* out = new OutputStream( file );
	return new PrintWriter( out );
}

InputStream*
IO::createIn()
{
	File* file = new File( File::STANDARD_IN );
	return new InputStream( file );
}

Printer*
IO::createErr()
{
	File* file = new File( File::STANDARD_ERROR );
	OutputStream* err = new OutputStream( file );
	return new PrintWriter( err );
}
