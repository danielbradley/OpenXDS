/*
 *  Copyright (C) 2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_UTIL_ITEXTTOKEN_H
#define OPENXDS_UTIL_ITEXTTOKEN_H

#include <openxds/Interface.h>
#include <openxds.base.h>

namespace openxds {
	namespace util {


class ITextToken : public openxds::Interface
{
public:
	enum ITokenType
	{
		_ESCAPED,
		_NUMBER,
		_SPACE,
		_SYMBOL,
		_TAB,
		_NEWLINE,
		_WHITESPACE,
		_WORD
	};

	/**
	 * An escaped sequence starts with the escape character '\' and has a trailing escaped char.
	 */
	static const ITokenType ESCAPED    = _ESCAPED;

	/**
	 * A number starts with a digit and may contain digits, commas and periods.
	 * 
	 * NUMBER ::= DIGIT, ( DIGIT | '.' | ',' )
	 */
	static const ITokenType NUMBER     = _NUMBER;

	/**
	 * A space corresponds to the character code '0x20' (32).
	 */
	static const ITokenType SPACE      = _SPACE;

	/**
	 * A symbol can be any non-alphanumeric character not including whitespace.
	 */
	static const ITokenType SYMBOL     = _SYMBOL;

	/**
	 * A tab corresponds to the character code '0x9' (9)
	 */
	static const ITokenType TAB        = _TAB;

	/**
	 * A new line can be either:
	 * 
	 *  Linux/Unix  LF    '0xA', (10)
	 *  Mac OS      CR    '0xD'  (13)
	 *  DOS/Windows CR,LF '0xD','0xA'
	 */
	static const ITokenType NEWLINE    = _NEWLINE;

	/**
	 * Non-visual characters that are not TABS, NEWLINES or SPACES.
	 */
	static const ITokenType WHITESPACE = _WHITESPACE;

	/**
	 * A word can start with any alpha-numeric character and contain any alpha-numeric
	 * character or the apostrophe - '0x27', (39)
	 */
	static const ITokenType WORD       = _WORD;

	virtual ~ITextToken() {};

	virtual ITokenType                      getTokenType() const = 0;
	virtual const openxds::base::String&  getTokenString() const = 0;
	virtual const openxds::base::String&        getValue() const = 0;
	virtual const openxds::base::String& getEscapedValue() const = 0;
};

};};

#endif
