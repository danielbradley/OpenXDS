/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/io/WouldBlockException.h>

#include <openxds/base/String.h>
#include <openxds/io/IOException.h>

using namespace openxds::base;
using namespace openxds::io;

static const String EXCEPTION_TYPE( "WouldBlockException" );

WouldBlockException::WouldBlockException()
{
}

WouldBlockException::WouldBlockException( const String* aMessage )
: IOException( aMessage )
{
}

WouldBlockException::WouldBlockException( const String& aMessage )
: IOException( aMessage )
{
}

WouldBlockException::WouldBlockException( const StringBuffer& aMessage )
: IOException( aMessage )
{
}

WouldBlockException::~WouldBlockException()
{
}
