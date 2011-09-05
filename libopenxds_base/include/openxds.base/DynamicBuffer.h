/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_DYNAMICBUFFER_H
#define OPENXDS_BASE_DYNAMICBUFFER_H

#include "openxds.base.h"
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds/Object.h>

namespace openxds {
	namespace base {

class DynamicBuffer : public openxds::Object
{
private:
	void* head;
	void* tail;
	long  size;

public:
	         DynamicBuffer();
	virtual ~DynamicBuffer();

	virtual byte       read() throw (openxds::exceptions::NoSuchElementException*);
	virtual void    unwrite() throw (openxds::exceptions::NoSuchElementException*);
	virtual void     unread( byte value );
	virtual void      write( byte value );

	virtual bool    isEmpty() const;
	virtual bool isNotEmpty() const;

//	virtual openxds::base::ByteBuffer* toByteBuffer() const;
	virtual DynamicBuffer* copy() const;
	virtual openxds::base::String* toString() const;


};

};};

#endif
