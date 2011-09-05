/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_FILEINPUTSTREAM_H
#define OPENXDS_IO_FILEINPUTSTREAM_H

/**
 *  The only files included in the header of an openxds object are:
 *
 *  o  Its superclass. <p>
 *
 *  o  The typedef header for any libraries the class interface uses. <p>
 */
#include "openxds.io.h"
#include "openxds.io/InputStream.h"
#include "openxds.io.exceptions/FileNotFoundException.h"
#include "openxds.io.exceptions/IOException.h"

#include <openxds.base.h>

namespace openxds {
	namespace io {

class FileInputStream : public openxds::io::InputStream
{
public:
	FileInputStream( void* stream )
		throw (openxds::io::exceptions::IOException*);

	FileInputStream( const openxds::io::File& inputFile )
		throw (openxds::io::exceptions::FileNotFoundException*);

	FileInputStream( openxds::io::File* inputFile )
		throw (openxds::io::exceptions::FileNotFoundException*);

	virtual ~FileInputStream();

	virtual void open() throw (openxds::io::exceptions::IOException*);
};

};};

#endif

