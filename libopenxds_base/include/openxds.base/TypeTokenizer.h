/*
 *  Copyright (C) 1997-2015 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_TYPETOKENIZER_H
#define OPENXDS_BASE_TYPETOKENIZER_H

#include <openxds.base.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds/Object.h>

namespace openxds {
	namespace base {

class TypeTokenizer : public openxds::Object
{
public:
	TypeTokenizer( const openxds::base::String& str );
	~TypeTokenizer();

	openxds::base::String* nextToken() throw (openxds::exceptions::NoSuchElementException*);

	bool hasMoreTokens();

	//	public virtual constant methods (Cloneable)
	virtual openxds::Object* clone() const;

protected:
	void init();
	openxds::base::String* parseNextToken();
	
private:
	openxds::base::String* source;
	int position;
	openxds::base::String* next;
};

};};

#endif
