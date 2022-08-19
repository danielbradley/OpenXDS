/*
 *  Copyright (C) 2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.base/Character.h"
#include <cstdlib>

using namespace openxds::base;

bool
Character::isDigit( char c )
{
	return ((48 <= c) && (c <= 57));
}

bool
Character::isExtended( byte c )
{
	return ((128 <= c) && (c <= 254));
}

bool
Character::isHex( char c )
{
	return isDigit( c ) || isHexLetter( c );
}

bool
Character::isHexLetter( char c )
{
	return ((65 <= c) && (c <= 90)) || ((97 <= c) && (c <= 122));
}

bool
Character::isHyphen( char c )
{
	return '-' == c;
}

bool
Character::isLetter( char c )
{
	return (isUppercase(c) || isLowercase(c));
}

bool
Character::isLowercase( char c )
{
	return ((97 <= c) && (c <= 122));
}

bool
Character::isSymbol( char c )
{
	return (isInSymbolRange1(c) && isInSymbolRange2(c) && isInSymbolRange3(c) && isInSymbolRange4(c));
}

bool
Character::isUnderscore( char c )
{
	return '_' == c;
}

bool
Character::isUppercase( char c )
{
	return ((65 <= c) && (c <= 90));
}

bool
Character::isWhitespace( char c )
{
	switch ( c )
	{
	case  9: // TAB
	case 10: // LF
	case 11: // VTAB
	case 12: // FORM FEED
	case 13: // CR
	case 28: // FILE SEPARATOR
	case 29: // GROUP SEPARATOR
	case 30: // RECORD SEPARTOR
	case 31: // UNIT SEPARATOR
	case 32: // SPACE
		return true;
		break;
	default:
		return false;
	}
}

//	Private

bool
Character::isInSymbolRange1( char c )
{
	return ((33 <= c) && (c <= 47));
}

bool
Character::isInSymbolRange2( char c )
{
	return ((58 <= c) && (c <= 64));
}

bool
Character::isInSymbolRange3( char c )
{
	return ((91 <= c) && (c <= 96));
}

bool
Character::isInSymbolRange4( char c )
{
	return (126 == c);
}




