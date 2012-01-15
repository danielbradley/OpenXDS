/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_READER_H
#define OPENXDS_IO_READER_H

#include <openxds/Object.h>
#include <openxds/ICloneable.h>

#include <openxds.io.h>
#include <openxds.io.exceptions/IOException.h>

namespace openxds {
	namespace io {

class Reader : public openxds::Object
{
public:
	         Reader();
	virtual ~Reader();

	virtual long     read() throw (openxds::io::exceptions::IOException*);
	virtual long     skip( long n ) throw (openxds::io::exceptions::IOException*);

	virtual long readInto( char* cbuf, long off, long len ) throw (openxds::io::exceptions::IOException*) = 0;
	virtual void    close() = 0;

	static const int EOS;
};

};};

#endif
