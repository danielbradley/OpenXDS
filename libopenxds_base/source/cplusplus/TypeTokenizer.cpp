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
#include <openxds.base/TypeTokenizer.h>
#include <openxds.exceptions/NoSuchElementException.h>

using namespace openxds::base;
using namespace openxds::exceptions;

TypeTokenizer::TypeTokenizer( const String& str )
{
	this->source = new String( str );
	this->position = 0;
	this->next = (String*) null;
}

TypeTokenizer::~TypeTokenizer()
{
	delete this->source;
}

bool
TypeTokenizer::hasMoreTokens()
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
TypeTokenizer::nextToken()
throw (openxds::exceptions::NoSuchElementException*)
{
	String* ret = (String*) null;

	if ( this->hasMoreTokens() )
	{
		//  Removes the reference so that "hasNext()" will
		//  parse the next token.

		ret = this->next;
		this->next = (String*) null;
	}
	return ret;
}

String*
TypeTokenizer::parseNextToken()
{
	String*       ret = (String*) null;
	StringBuffer* s   = new StringBuffer();

	int i;
	int max = (int) this->source->getLength();
	char ch[2] = { 0, 0 };

	int bracket_depth = 0;

	for ( i=this->position; i < max; i++ )
	{
		ch[0] = this->source->charAt( i );

		if ( (',' == ch[0]) && (0 == bracket_depth) )
		{
			break;
		}
		else
		{
			switch ( ch[0] )
			{
			case '<':
				bracket_depth++;
				break;
				
			case '>':
				bracket_depth--;
				break;
			}
			s->append( ch[0] );
		}
	}

	this->position = i+1;

	if( 0 < s->getLength() )
	{
		ret = s->asString();
	}
	delete s;

	return ret;
}

openxds::Object*
TypeTokenizer::clone() const
{
  TypeTokenizer* st = new TypeTokenizer( *this->source );
  st->position = this->position;
  st->next = new String( *this->next );
  return st;
}
