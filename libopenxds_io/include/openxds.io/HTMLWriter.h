/*
 *  Copyright (C) 2013 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_HTMLWRITER_H_
#define OPENXDS_IO_HTMLWRITER_H_

#include <openxds.io/PrintWriter.h>

namespace openxds {
	namespace io {

class HTMLWriter : public PrintWriter
{
public:

	HTMLWriter( openxds::io::OutputStream& ostream );
	HTMLWriter( openxds::io::OutputStream* ostream );

	virtual ~HTMLWriter() throw (openxds::io::exceptions::IOException*);

	virtual void write( const char* characters, long offset, long count ) const throw (openxds::io::exceptions::IOException*);
};

};};

#endif
