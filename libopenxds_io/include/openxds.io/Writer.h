/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_WRITER_H
#define OPENXDS_IO_WRITER_H

#include <openxds/Interface.h>

#include <openxds.base.h>
#include <openxds.io.h>
#include <openxds.io.exceptions/IOException.h>

namespace openxds {
	namespace io {

class Writer : public openxds::Interface
{
public:
	static const int EOL;

	virtual ~Writer() throw (openxds::io::exceptions::IOException*);

	virtual void close() = 0;
	virtual void flush() const = 0;
  
	virtual void write( const char* characters, long offset, long count ) const
		throw (openxds::io::exceptions::IOException*) = 0;
	virtual void write( char character ) const
		throw (openxds::io::exceptions::IOException*) = 0;
	virtual void write( const openxds::base::String* str, long offset, long count ) const
		throw (openxds::io::exceptions::IOException*) = 0;

	virtual openxds::Object* clone() const = 0;
};

};};

#endif
