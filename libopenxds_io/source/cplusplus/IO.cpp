/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.io/IO.h"

#include "openxds.io/File.h"
#include "openxds.io/InputStream.h"
#include "openxds.io/OutputStream.h"
#include "openxds.io/PrintWriter.h"

#include "openxds.io.exceptions/IOException.h"

using namespace openxds::io;

InputStream& IO::IN  = *createIn();
PrintWriter& IO::OUT = *createOut();
PrintWriter& IO::ERR = *createErr();

InputStream&
IO::in()
{
  return IO::IN;
}

PrintWriter&
IO::out()
{
  return IO::OUT;
}

PrintWriter&
IO::err()
{
  return IO::ERR;
}

PrintWriter*
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

PrintWriter*
IO::createErr()
{
	File* file = new File( File::STANDARD_ERROR );
	OutputStream* err = new OutputStream( file );
	return new PrintWriter( err );
}
