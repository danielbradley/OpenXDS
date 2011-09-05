/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_DIRECTORY_H
#define OPENXDS_IO_DIRECTORY_H

#include "openxds.io.exceptions/FileAlreadyExistsException.h"
#include "openxds.io.exceptions/FileNotFoundException.h"
#include "openxds.io.exceptions/IOException.h"
#include "openxds.io/Path.h"
#include "openxds.io.h"

#include <openxds.security.exceptions/AccessException.h>
#include <openxds.adt.h>
#include <openxds.base.h>
#include <openxds/Object.h>
#include <openxds.core.io.h>

namespace openxds {
	namespace io {

class Directory : public openxds::Object
{
public:
	Directory( const char* location );
//	Directory( const openxds::base::String& path );
//	Directory( const openxds::io::Path& path );
	virtual ~Directory();
//	
//	void open()
//		throw ( openxds::security::exceptions::AccessException*,
//		        openxds::io::exceptions::FileNotFoundException*,
//		        openxds::io::exceptions::IOException* );
//
	void create( bool recursive = false )
		throw (	openxds::security::exceptions::AccessException*,
		        openxds::io::exceptions::FileAlreadyExistsException*,
				openxds::io::exceptions::IOException* );
	
	void remove( bool recursive = false )
		throw ( openxds::security::exceptions::AccessException*,
		        openxds::io::exceptions::FileNotFoundException*,
		        openxds::io::exceptions::IOException* );
//
//	Directory* parent() const;
	openxds::adt::IList<openxds::base::String>* retrieveFileList() const;
//
//	openxds::util::Sequence* filenamesStartingWith( const openxds::base::String& pattern ) const;
//	openxds::util::Sequence* search( const openxds::base::String& pattern ) const;
//
	const Path& getPath() const;

	bool exists() const;

private:
	Path* path;
	openxds::core::io::IDirectory* core;
};

};};

#endif
