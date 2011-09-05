/*
 *  Copyright (C) 2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_UTIL_ITOKENIZER_H
#define OPENXDS_UTIL_ITOKENIZER_H

#include <openxds/Interface.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds.base.h>

namespace openxds {
	namespace util {

class ITokenizer : public openxds::Interface
{
public:
	virtual ~ITokenizer() {};

//	virtual       IToken*     nextToken()       throw (openxds::io::exceptions::IOException*,openxds::exceptions::NoSuchElementException*);
//	virtual const IToken& peekNextToken()       throw (openxds::io::exceptions::IOException*,openxds::exceptions::NoSuchElementException*);
//	virtual       bool    hasMoreTokens() const throw (openxds::io::exceptions::IOException*);
};

};};

#endif
