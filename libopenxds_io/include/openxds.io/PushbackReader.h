/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_PUSHBACKREADER_H
#define OPENXDS_IO_PUSHBACKREADER_H

#include <openxds/Object.h>
#include <openxds/ICloneable.h>

#include <openxds.io.h>
#include <openxds.io/Reader.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.adt.h>

namespace openxds {
	namespace io {

class PushbackReader : public openxds::io::Reader
{
public:
	         PushbackReader( Reader* aReader );
	virtual ~PushbackReader();

	virtual long readInto( char* cbuf, long off, long len ) throw (openxds::io::exceptions::IOException*);
	virtual void   unread( char c );
	virtual void    close();

private:
	openxds::adt::IStack<openxds::base::Character>* pushstack;
	openxds::io::Reader*        reader;

};

};};

#endif
