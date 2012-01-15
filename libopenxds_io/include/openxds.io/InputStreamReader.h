/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_INPUTSTREAMREADER_H
#define OPENXDS_IO_INPUTSTREAMREADER_H

#include <openxds.io/Reader.h>
#include <openxds.io.h>

namespace openxds {
	namespace io {

class InputStreamReader : public openxds::io::Reader
{
private:
	bool isReference;
	InputStream* istream;

public:
	         InputStreamReader( const InputStream& istream );
	         InputStreamReader( InputStream* istream );
	virtual ~InputStreamReader();

	virtual void    close();
	virtual long readInto( char* cbuf, long off, long len ) throw (openxds::io::exceptions::IOException*);
};

};};

#endif
