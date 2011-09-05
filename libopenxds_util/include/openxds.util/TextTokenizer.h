/*
 *  Copyright (C) 2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_UTIL_TEXTTOKENIZER_H
#define OPENXDS_UTIL_TEXTTOKENIZER_H

#include <openxds.util/ITextTokenizer.h>
#include <openxds.io/PushbackReader.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.io.h>
#include <openxds.adt.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds/Interface.h>
#include <openxds.base.h>

namespace openxds {
	namespace util {

class TextTokenizer : public openxds::util::ITextTokenizer
{
private:
	openxds::io::PushbackReader*         reader;
	openxds::adt::ISequence<ITextToken>* tokenQueue;

public:
	         TextTokenizer( openxds::io::Reader* aReader );
	virtual ~TextTokenizer();

	virtual       ITextToken*     nextToken() throw (openxds::io::exceptions::IOException*,openxds::exceptions::NoSuchElementException*);
	virtual const ITextToken& peekNextToken() throw (openxds::io::exceptions::IOException*,openxds::exceptions::NoSuchElementException*);
	virtual       bool        hasMoreTokens() throw (openxds::io::exceptions::IOException*);
	virtual       void        pushback( ITextToken* token );
};

};};

#endif
