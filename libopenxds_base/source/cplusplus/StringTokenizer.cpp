/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.base/String.h>
#include <openxds.base/StringBuffer.h>
#include <openxds.base/StringTokenizer.h>
#include <openxds.exceptions/NoSuchElementException.h>

using namespace openxds::base;
using namespace openxds::exceptions;

StringTokenizer::StringTokenizer( const String& str )
{
	this->delimiter = ' ';
	this->delimiters = null;

	this->source = new String( str );
	this->position = 0;
	this->next = (String*) null;
	this->lastDelimiter = '\0';
	this->lastDelimiters = new StringBuffer();
	this->nextDelimiters = new StringBuffer();
	
	this->breakOnCaps = false;
	this->keepQuotes = false;
	this->respectQuotes = true;
}

StringTokenizer::~StringTokenizer()
{
	delete this->source;
	delete this->delimiters;
	delete this->lastDelimiters;
	delete this->nextDelimiters;
}

void
StringTokenizer::setBreakOnCaps( bool value )
{
	this->breakOnCaps = value;
}

void
StringTokenizer::setKeepQuotes( bool value )
{
	this->keepQuotes = value;
}

void
StringTokenizer::setRespectQuotes( bool value )
{
	this->respectQuotes = value;
}

bool
StringTokenizer::hasMoreTokens()
{
	bool ret = (null != this->next);
	if ( !ret )
	{
		this->next = parseNextToken();
		ret = (null != this->next);
	}
	return ret;
}

String*
StringTokenizer::nextToken()
throw (NoSuchElementException*)
{
  String* ret = (String*) null;

  //  Calls "hasMoreTokens()" to ensure that "next"
  //  is not null.

  if ( false == this->hasMoreTokens() )
  {
    throw new NoSuchElementException();
  }

  //  Removes the reference so that "hasNext()" will
  //  parse the next token.

  ret = this->next;
  this->next = (String*) null;
  return ret;
}

char
StringTokenizer::getLastDelimiter() const
{
	return this->lastDelimiter;
}

const String*
StringTokenizer::getLastDelimiters() const
{
	return this->lastDelimiters->asString();
}

//Sequence* 
//StringTokenizer::tokenize() const
//{
//	Sequence* tokens = new Sequence();
//	
//	//
//	//	Tokenize this->text into tokens that are store in this->tokens
//	//
//	{
//		StringTokenizer st( *this->source );
//		st.setBreakOnCaps( this->breakOnCaps );
//
//		st.setDelimiter( this->delimiter );
//		if ( this->delimiters )
//		{
//			st.setDelimiters( *this->delimiters );
//		}
//
//		while( st.hasMoreTokens() )
//		{
//			const String& de = st.getLastDelimiters();
//			if ( 0 < de.getLength() )
//			{
//				tokens->add( new String( de ) );
//			}
//			String* token = st.nextToken();
//			tokens->add( token );
//		}
//		String* str = new String( st.getLastDelimiters() );
//		if ( str && !str->equals( "" ) )
//		{
//			tokens->add( str );
//		} else {
//			delete str;
//		}
//	}
//	return tokens;
//}

void
StringTokenizer::init()
{
	//	Called from hasMoreTokens as delimiters need to be set first.
	//
	//	Skip over any delimiters at start of
	//	String and append them to lastDelimiter and nextDelimiter.
	//
	//	Appending to nextDelimiter as well will mean that if hasMoreTokens
	//	is called (causing nextDelimiter to overwrite lastDelimiter)
	//	lastDelimiter will still contain the appropriate chars. 
	//

	delete this->lastDelimiters;
	delete this->nextDelimiters;
	
	this->lastDelimiters = new StringBuffer();
	this->nextDelimiters = new StringBuffer();

	char ch[2] = { 0, 0 };
	int i = this->position;
	int del = this->delimiter;
	int max = (int) this->source->getLength();
	for ( ; i < max; i++ )
	{
		ch[0] = this->source->charAt( i );

		if ( this->delimiters && !this->delimiters->contains( ch ) )
		{
			break;
		}
		else if ( !this->delimiters && ( ch[0] != del ) )
		{
			break;
		}
		this->lastDelimiters->append( ch[0] );
		this->nextDelimiters->append( ch[0] );
	}
	this->position = i;
}

String*
StringTokenizer::parseNextToken()
{
	delete this->lastDelimiters;
	this->lastDelimiters = this->nextDelimiters;
	this->nextDelimiters = new StringBuffer();
	
	String* ret = (String*) null;
	StringBuffer* s = new StringBuffer();

	int del = this->delimiter;
	int i;
	int max = (int) this->source->getLength();
	char ch[2] = { 0, 0 };

	bool quoted = false;
	for ( i=this->position; i < max; i++ )
	{
		ch[0] = this->source->charAt( i );

		if ( ('\"' == ch[0]) && !quoted )
		{
			quoted = true;
			if ( this->keepQuotes ) { s->append( ch[0] ); }
		}
		else if ( ('\"' == ch[0]) && quoted )
		{
			quoted = false;
			if ( this->keepQuotes ) { s->append( ch[0] ); }
		}
		else if ( quoted )
		{
			s->append( ch[0] );
		}
		else if ( this->delimiters && this->delimiters->contains( ch ) )
		{
			i++;
			this->lastDelimiter = ch[0];
			this->nextDelimiters->append( ch[0] );
			break;
		}
		else if ( !this->delimiters && ( ch[0] == del ) )
		{
			i++;
			this->lastDelimiter = ch[0];
			this->nextDelimiters->append( ch[0] );
			break;
		}
		else if ( this->breakOnCaps && (this->position != i) && ('A' <= ch[0]) && (ch[0] <= 'Z') )
		{
			this->lastDelimiter = ch[0];
			break;
		}
		else
		{
			s->append( ch[0] );
		}
	}

	//
	//	Skip over any repeating delimiters
	//
	for (; i < max; i++ )
	{
		ch[0] = this->source->charAt( i );

		if ( this->delimiters && !this->delimiters->contains( ch ) )
		{
			break;
		}
		else if ( !this->delimiters && ( ch[0] != del ) )
		{
			break;
		}
		this->lastDelimiter = ch[0];
		this->nextDelimiters->append( ch[0] );
	}
	this->position = i;

	if ( s->getLength() > 0 )
	{
		ret = s->asString();
	}
	delete s;
	return ret;
}

void
StringTokenizer::setDelimiter( char c )
{
	delete this->delimiters;
	this->delimiters = null;
	this->delimiter = c;

	this->init();
}

void
StringTokenizer::setDelimiters( const String& asciiValues )
{
	delete this->delimiters;
	this->delimiters = new String( asciiValues );

	this->init();
}

openxds::Object*
StringTokenizer::clone() const
{
  StringTokenizer* st = new StringTokenizer( *this->source );
  st->delimiter = this->delimiter;
  st->position = this->position;
  st->next = new String( *this->next );
  return st;
}
