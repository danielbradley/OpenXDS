/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.util/TextToken.h>
#include <openxds.base/Character.h>
#include <openxds.base/Runtime.h>
#include <openxds.base/StringBuffer.h>
#include <openxds/Object.h>

using namespace openxds::base;
using namespace openxds::util;

const String* TextToken::Escaped    = new String( "ESCAPED" );
const String* TextToken::Number     = new String( "NUMBER" );
const String* TextToken::Space      = new String( "SPACE" );
const String* TextToken::Symbol     = new String( "SYMBOL" );
const String* TextToken::Tab        = new String( "TAB" );
const String* TextToken::Newline    = new String( "NEWLINE" );
const String* TextToken::Whitespace = new String( "WHITESPACE" );
const String* TextToken::Word       = new String( "WORD" );

const String* TextToken::EscapedNewline    = new String( "\\n" );
const String* TextToken::EscapedTab        = new String( "\\t" );
const String* TextToken::EscapedWhitespace = new String( "?" );

TextToken::TextToken( const StringBuffer& sb )
{
	this->value = sb.asString();
	
	char first_character = this->value->charAt( 0 );
	
	if ( '\\' == first_character )
	{
		this->type = ESCAPED;
	}
	else if ( Character::isLetter( first_character ) )
	{
		this->type = WORD;
	}
	else if ( Character::isDigit( first_character ) )
	{
		this->type = NUMBER;
	}
	else if ( Character::isWhitespace( first_character ) )
	{
		switch ( first_character )
		{
		case 0x09:
			this->type = TAB;
			break;
		case 0x0A: // '\n'
		case 0x0D: // '\n'
			this->type = NEWLINE;
			break;
		case 0x20:
			this->type = SPACE;
			break;
		default:
			this->type = WHITESPACE;
		}
	}
	else
	{
		this->type = SYMBOL;
	}
}

TextToken::~TextToken()
{
	delete this->value;
}

ITextToken::ITokenType
TextToken::getTokenType() const
{
	return this->type;
}

const String&
TextToken::getTokenString() const
{
	switch ( this->type )
	{
	case ITextToken::ESCAPED:
		return *Escaped;
	case ITextToken::NUMBER:
		return *Number;
	case ITextToken::SPACE:
		return *Space;
	case ITextToken::SYMBOL:
		return *Symbol;
	case ITextToken::TAB:
		return *Tab;
	case ITextToken::NEWLINE:
		return *Newline;
	case ITextToken::WHITESPACE:
		return *Whitespace;
	case ITextToken::WORD:
		return *Word;
	}
}

const String&
TextToken::getValue() const
{
	return *this->value;
}

const String&
TextToken::getEscapedValue() const
{
	switch ( this->type )
	{
	case NEWLINE:
		return *EscapedNewline;
	case TAB:
		return *EscapedTab;
	case WHITESPACE:
		return *EscapedWhitespace;
	default:
		return *this->value;
	}
}
