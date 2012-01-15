/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.io/LineParser.h"
#include "openxds.io/InputStream.h"
#include "openxds.io.exceptions/IOException.h"

#include <openxds.adt.std/Sequence.h>
#include <openxds.base/Runtime.h>
#include <openxds.base/StringBuffer.h>

using namespace openxds::adt;
using namespace openxds::adt::std;
using namespace openxds::base;
using namespace openxds::exceptions;
using namespace openxds::io;
using namespace openxds::io::exceptions;

LineParser::LineParser( const InputStream& in )
{
  this->isReference = true;
  this->inputStream = (InputStream*) &in;
  this->lineNumber = -1;
  this->finished = false;
	this->tokens = null;
	this->delimiter = ' ';
}

LineParser::LineParser( InputStream* in )
{
  this->isReference = false;
  this->inputStream = in;
  this->lineNumber = -1;
  this->finished = false;
	this->tokens = null;
	this->delimiter = ' ';

}

LineParser::~LineParser()
{
  if ( false == this->isReference ) {
    delete this->inputStream;
  }
	if ( null != this->tokens )
	{
  		delete this->tokens;
	}
}

String*
LineParser::readLine()
{
  String* ret = null;
  StringBuffer* s = new StringBuffer();

  long c;
  bool loop = true;
  while( loop )
  {
    c = this->inputStream->read();

    switch ( c )
    {
    case '\n':
      loop = false;
      break;
    case 13: // Carriage Return
      loop = false;
      break;
    case OPENXDS_IO_EOS: // InputStream::EOS
      this->finished = true;
      loop = false;
      break;
    default:
      s->append( c );
    }
  }
  ret = s->asString();
  delete s;
  this->lineNumber++;
  
  return ret;
}

void
LineParser::parseLine()
{
	if ( null != this->tokens )
	{
		delete this->tokens;
	}
	this->tokens = new Sequence<String>();
	
	StringBuffer* s = new StringBuffer();

	long c;
	bool loop = true;
	bool quoted = false;

	while( loop )
	{
		try
		{
			c = this->inputStream->read();

			switch ( c )
			{
			case '\n':
				if ( quoted )
				{
					s->append( c );
					continue;
				}
				loop = false;
				this->tokens->addLast( s->asString() );
				delete s;
				this->lineNumber++;
				break;
			case 13: // Carriage Return
				if ( quoted )
				{
					s->append( c );
					continue;
				}
				break;
			case '\"':
				quoted = !quoted;
				break;
			case OPENXDS_IO_EOS: // InputStream::EOS
				loop = false;
				if ( s->getLength() > 0 )
				{
					this->tokens->addLast( s->asString() );
					this->lineNumber++;
				}
				delete s;
				this->finished = true;
				break;
			default:
				if ( (c == this->delimiter) && ( !quoted ) && ( s->getLength() > 0 ) )
				{
					this->tokens->addLast( s->asString() );
					delete s;
					s = new StringBuffer();
				}
				else if ( c != this->delimiter )
				{
					s->append( c );
				}
				else if ( quoted )
				{
					s->append( c );
				}
			}
		} catch ( IOException* ex ) {
			delete ex;
			loop = false;
			if ( s->getLength() > 0 )
			{
				this->tokens->addLast( s->asString() );
				this->lineNumber++;
			}
			delete s;
			this->finished = true;
		}
	}
}

void
LineParser::setDelimiter( char aDelimiter )
{
	this->delimiter = aDelimiter;
}

const String&
LineParser::getToken( unsigned int posn ) const
throw (NoSuchElementException*)
{
	return dynamic_cast<const String&>( this->tokens->get( posn ) );
}

int
LineParser::getLineNumber() const
{
  return this->lineNumber;
}

bool
LineParser::hasFinished() const
{
  return finished;
}

//Object*
//LineParser::clone() const
//{
//  LineParser* lp = new LineParser( (InputStream*) inputStream->clone() );
//  lp->lineNumber = this->lineNumber;
//  lp->finished = this->finished;
// return lp;
//}
