/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/PushbackReader.h>
#include <openxds.io/InputStream.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.adt.std/Stack.h>
#include <openxds.base/Character.h>

using namespace openxds::adt;
using namespace openxds::adt::std;
using namespace openxds::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

PushbackReader::PushbackReader( Reader* aReader ) : Reader()
{
	this->pushstack = new Stack<Character>();
	this->reader    = aReader;
}

PushbackReader::~PushbackReader()
{
	delete this->pushstack;
	delete this->reader;
}

void
PushbackReader::unread( char c )
{
	this->pushstack->push( new Character( c ) );
}

long
PushbackReader::readInto( char* cbuf, long off, long len )
throw (IOException*)
{
	while ( !this->pushstack->isEmpty() )
	{
		if ( off == len ) break;
		
		Character* ch = this->pushstack->pop();
		{
			cbuf[off] = ch->getValue();
			off++;
		}
		delete ch;
	}
	
	if ( off == len )
	{
		return len;
	} else {
		return this->reader->readInto( cbuf, off, len );
	}
}

void
PushbackReader::close()
{
	this->reader->close();
}
