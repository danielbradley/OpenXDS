/*
 *  Copyright (C) 2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_CHARACTER_H
#define OPENXDS_BASE_CHARACTER_H

#include "openxds.base.h"
#include "openxds/Object.h"

namespace openxds {
	namespace base {

class Character : public Object
{
private:
	int c;

public:
	Character( int c ) { this->c = c; }
	
	int getValue() { return this->c; }

	static bool      isDigit( char c );
	static bool   isExtended( byte c );
	static bool        isHex( char c );
	static bool  isHexLetter( char c );
	static bool     isHyphen( char c );
	static bool     isLetter( char c );
	static bool  isLowercase( char c );
	static bool     isSymbol( char c );
	static bool isUnderscore( char c );
	static bool  isUppercase( char c );
	static bool isWhitespace( char c );

private:
	static bool isInSymbolRange1( char c );
	static bool isInSymbolRange2( char c );
	static bool isInSymbolRange3( char c );
	static bool isInSymbolRange4( char c );
};

};};

#endif
