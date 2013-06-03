/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.util/TextToken.h>
#include <openxds.util/TextTokenizer.h>
#include <openxds.io/PushbackReader.h>
#include <openxds.adt.std/Sequence.h>
#include <openxds.base/Character.h>
#include <openxds.base/StringBuffer.h>

#include <openxds/Object.h>

using namespace openxds;
using namespace openxds::exceptions;
using namespace openxds::adt;
using namespace openxds::adt::std;
using namespace openxds::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;
using namespace openxds::util;

static ITextToken*     parseNextToken( PushbackReader& reader ) throw (IOException*);
static bool        isSimilarCharacter( char ch1, char chX );
static bool   isApostropheAfterLetter( char ch1, char chX );
static bool        isDigitAfterNumber( char ch1, char chX );
static bool        isSpecialCharacter( char ch1, char chX );

static char APOSTROPHE = '\'';
static char PERIOD     = '.';
static char COMMA      = ',';

TextTokenizer::TextTokenizer( Reader* aReader )
{
	this->reader     = new PushbackReader( aReader );
	this->tokenQueue = new Sequence<ITextToken>();
}

TextTokenizer::~TextTokenizer()
{
	delete this->reader;
	delete this->tokenQueue;
}

ITextToken*
TextTokenizer::nextToken()
throw (IOException*,NoSuchElementException*)
{
	if ( !this->hasMoreTokens() ) throw new NoSuchElementException();
	
	return this->tokenQueue->removeFirst();
}

void
TextTokenizer::pushback( ITextToken* token )
{
	this->tokenQueue->addFirst( token );
}

const ITextToken&
TextTokenizer::peekNextToken()
throw (IOException*,NoSuchElementException*)
{
	if ( ! this->hasMoreTokens() ) throw new NoSuchElementException();
	
	return this->tokenQueue->getFirst();
}

bool
TextTokenizer::hasMoreTokens()
throw (IOException*)
{
	if ( ! this->tokenQueue->isEmpty() ) return true;
	
	ITextToken* token = parseNextToken( *this->reader );
	if ( null != token )
	{
		this->tokenQueue->addLast( token );
		return true;
	} else {
		return false;
	}
}

ITextToken* parseNextToken( PushbackReader& reader ) throw (IOException*)
{
	ITextToken* ret = null;
	
	long ch1 = reader.read();
	
	if ( -1 != ch1 )
	{
		StringBuffer sb;
		sb.append( ch1 );

		long special = 0;
		long chX;
		
		while ( -1 != (chX = reader.read() ) )
		{
			if ( '\\' == ch1 )
			{
				sb.append( chX );
				break;
			}
			else if ( isSimilarCharacter( (char) ch1, (char) chX ) )
			{
				if ( 0 != special )
				{
					sb.append( (char) special );
					special = 0;
				}
				
				sb.append( (char) chX );
			}
			else if ( isApostropheAfterLetter( ch1, chX ) )
			{
				special = chX;
			}
			else if ( isSpecialCharacter( ch1, chX ) )
			{
				if ( 0 != special )
				{
					reader.unread( chX );
					reader.unread( special );
					special = 0;
					break;
				}
				else
				{
					special = chX;
				}
			}
			else
			{
				reader.unread( chX );
				if ( 0 != special )
				{
					reader.unread( special );
					special = 0;
				}
				
				break;
			}
		}
		
		if ( 0 < sb.getLength() )
		{
			ret = new TextToken( sb );
		}
	}

	return ret;
}

static bool isSimilarCharacter( char ch1, char chX )
{
	if ( Character::isLetter( ch1 ) )
	{
		return ( Character::isLetter( chX ) || Character::isLetter( chX ) || Character::isUnderscore( chX ) );
	}
	else if ( Character::isUnderscore( ch1 ) )
	{
		return ( Character::isLetter( chX ) || Character::isLetter( chX ) || Character::isUnderscore( chX ) );
	}
	else if ( Character::isDigit( ch1 ) )
	{
		return ( Character::isDigit( chX ) );
	}
	else if ( Character::isWhitespace( ch1 ) )
	{
		switch ( ch1 )
		{
		case 0x09: // TAB
			return false;
		
		case 0x0A: // NEWLINE
			return false;

		case 0x0D: // CARRIAGE RETURN
			return (0x0A == chX) ? true : false;

		default:
			return ( ch1 == chX );
		}
	}
	else
	{
		return false;
	}
}

static bool isApostropheAfterLetter( char ch1, char chX )
{
	return (Character::isLetter( ch1 ) && (APOSTROPHE == chX));
}

static bool isDigitAfterNumber( char ch1, char chX )
{
	bool decimal_point = ((PERIOD == ch1) || (COMMA == chX));
	return (Character::isDigit( ch1 ) && decimal_point);
}

static bool isSpecialCharacter( char ch1, char chX )
{
	if ( Character::isDigit( ch1 ) )
	{
		return ((PERIOD == chX) || (COMMA == chX));
	}
	else if ( 0x0D == ch1 )
	{
		return (0x0A == chX);
	}
	else
	{
		return false;
	}
}






