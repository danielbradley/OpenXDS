/*
 *  Copyright (C) 2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_UTIL_TEXTTOKEN_H
#define OPENXDS_UTIL_TEXTTOKEN_H

#include "openxds.util/ITextToken.h"
#include <openxds/Object.h>
#include <openxds.base.h>

namespace openxds {
	namespace util {

class TextToken : public openxds::Object, public ITextToken
{
private:
	ITextToken::ITokenType  type;
	openxds::base::String* value;

public:
	         TextToken( const openxds::base::StringBuffer& sb );
	virtual ~TextToken();

	virtual ITokenType                   getTokenType()    const;
	virtual const openxds::base::String& getValue()        const;
	virtual const openxds::base::String& getTokenString()  const;
	virtual const openxds::base::String& getEscapedValue() const;
	
private:
	static const openxds::base::String* Escaped;
	static const openxds::base::String* Number;
	static const openxds::base::String* Space;
	static const openxds::base::String* Symbol;
	static const openxds::base::String* Tab;
	static const openxds::base::String* Newline;
	static const openxds::base::String* Whitespace;
	static const openxds::base::String* Word;

	static const openxds::base::String* EscapedNewline;
	static const openxds::base::String* EscapedTab;
	static const openxds::base::String* EscapedWhitespace;
	
};

};};

#endif
