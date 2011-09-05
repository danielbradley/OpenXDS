/*
 *  Copyright (C) 2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_UTIL_ITEXTTOKENIZER_H
#define OPENXDS_UTIL_ITEXTTOKENIZER_H

#include <openxds.util.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds/Interface.h>
#include <openxds.base.h>

namespace openxds {
	namespace util {

class ITextTokenizer : public openxds::Interface
{
public:
	virtual ~ITextTokenizer() {};

	virtual       ITextToken*     nextToken() throw (openxds::io::exceptions::IOException*,openxds::exceptions::NoSuchElementException*) = 0;
	virtual const ITextToken& peekNextToken() throw (openxds::io::exceptions::IOException*,openxds::exceptions::NoSuchElementException*) = 0;
	virtual       bool        hasMoreTokens() throw (openxds::io::exceptions::IOException*) = 0;
	virtual       void        pushback( ITextToken* token ) = 0;
};

};};

#endif
