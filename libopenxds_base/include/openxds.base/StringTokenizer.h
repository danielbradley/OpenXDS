/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_STRINGTOKENIZER_H
#define OPENXDS_BASE_STRINGTOKENIZER_H

#include <openxds.base.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds/Object.h>

namespace openxds {
	namespace base {

class StringTokenizer : public openxds::Object
{
public:
	StringTokenizer( const openxds::base::String& str );
	~StringTokenizer();

	void setBreakOnCaps( bool value );
	void setKeepQuotes( bool value );
	void setRespectQuotes( bool value );

	openxds::base::String* nextToken() throw (openxds::exceptions::NoSuchElementException*);

	void setDelimiter( char c );
	void setDelimiters( const openxds::base::String& asciiValues );
	bool hasMoreTokens();

	//	public virtual constant methods (Cloneable)
	virtual openxds::Object* clone() const;

	//	public constant methods
	char getLastDelimiter() const;

protected:
	void init();
	openxds::base::String* parseNextToken();
	
private:
	char delimiter;
	openxds::base::String* delimiters;

	openxds::base::String* source;
	int position;
	openxds::base::String* next;

	char lastDelimiter;
	char nextDelimiter;
	
	bool breakOnCaps;
	bool keepQuotes;
	bool respectQuotes;
};

};};

#endif
