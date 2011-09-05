/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_FILEOUTPUTSTREAM_H
#define OPENXDS_IO_FILEOUTPUTSTREAM_H

#include <openxds.io/OutputStream.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.io.h>
#include <openxds/Object.h>

namespace openxds {
	namespace io {

class FileOutputStream : public OutputStream
{
public:
	         FileOutputStream( void* stream     ) throw (openxds::io::exceptions::IOException*);
	         FileOutputStream( File& targetFile ) throw (openxds::io::exceptions::IOException*);
	         FileOutputStream( File* targetFile );
	virtual ~FileOutputStream() throw (openxds::io::exceptions::IOException*);

protected:
	void open() throw (openxds::io::exceptions::IOException*);

};

};}; // end of openxds::io namespace scope.

#endif // _OPENOCL_IO_FILEOUTPUTSTREAM_H_
