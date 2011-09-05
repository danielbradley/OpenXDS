/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/io/FileAlreadyExistsException.h>

#include <openxds/base/String.h>

using namespace openxds::base;
using namespace openxds::io;

static const char* EXCEPTION_TYPE = "Exception";

FileAlreadyExistsException::FileAlreadyExistsException()
{
}

FileAlreadyExistsException::FileAlreadyExistsException( const String* aMessage )
: IOException( aMessage )
{}

FileAlreadyExistsException::FileAlreadyExistsException( const String& aMessage )
: IOException( aMessage )
{}

FileAlreadyExistsException::FileAlreadyExistsException( const StringBuffer& aMessage )
: IOException( aMessage )
{}

FileAlreadyExistsException::~FileAlreadyExistsException()
{
}
