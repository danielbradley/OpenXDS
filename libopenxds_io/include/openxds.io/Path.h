/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_PATH_H
#define OPENXDS_IO_PATH_H

#include "openxds.io.exceptions/IOException.h"

#include <openxds.core.io/Path.h>
#include <openxds.base.h>
#include <openxds/Object.h>


namespace openxds {
	namespace io {

class Path : public openxds::Object
{
public:
	static const int NONE                   = OPENXDS_CORE_IO_TYPE_NONE;
	static const int UNKNOWN                = OPENXDS_CORE_IO_TYPE_UNKNOWN;
	static const int FS                     = OPENXDS_CORE_IO_TYPE_FS;
	static const int FS_DEVICE              = OPENXDS_CORE_IO_TYPE_FS_DEVICE;
	static const int FS_DEVICE_BLOCK        = OPENXDS_CORE_IO_TYPE_FS_DEVICE_BLOCK;
	static const int FS_DEVICE_CHARACTER    = OPENXDS_CORE_IO_TYPE_FS_DEVICE_CHARACTER;
	static const int FS_DIRECTORY           = OPENXDS_CORE_IO_TYPE_FS_DIRECTORY;
	static const int FS_DIRECTORY_SUPER     = OPENXDS_CORE_IO_TYPE_FS_DIRECTORY_SUPER;
	static const int FS_FILE                = OPENXDS_CORE_IO_TYPE_FS_FILE;
	static const int FS_LINK                = OPENXDS_CORE_IO_TYPE_FS_LINK;
	static const int FS_SYMLINK             = OPENXDS_CORE_IO_TYPE_FS_SYMLINK;
	static const int IO                     = OPENXDS_CORE_IO_TYPE_IO;
	static const int IO_FIFO                = OPENXDS_CORE_IO_TYPE_IO_FIFO;
	static const int IO_SOCKET              = OPENXDS_CORE_IO_TYPE_IO_SOCKET;
	static const int NET                    = OPENXDS_CORE_IO_TYPE_NET;

	static const int DIRECTORY              = OPENXDS_CORE_IO_TYPE_FS_DEVICE;
	static const int FILE                   = OPENXDS_CORE_IO_TYPE_FS_FILE;

	         Path( const char* aPath )                  throw (openxds::io::exceptions::IOException*);
	         Path( const openxds::base::String& aPath ) throw (openxds::io::exceptions::IOException*);
	explicit Path( const Path& aPath )                  throw (openxds::io::exceptions::IOException*);
	        ~Path();
			
	Path* childPath( const openxds::base::String& filename ) const;
	
	const openxds::base::String& getOriginal()  const;
	const openxds::base::String& getProtocol()  const;
	const openxds::base::String& getHostname()  const;
	const openxds::base::String& getVolume()    const;
	const openxds::base::String& getAbsolute()  const;
	const openxds::base::String& getViewable()  const;

	const openxds::base::String& getPath()      const;
	const openxds::base::String& getCanonical() const;
	const openxds::base::String& getCondensed() const;
	const openxds::base::String& getPreferred() const;

	const openxds::base::String& getDirectory() const;
	const openxds::base::String& getDirname()   const;
	const openxds::base::String& getBasename()  const;
	const openxds::base::String& getExtension() const;
	
	static Path* getCurrentDirectory();
	static char  getFileSeparator();

	int getType() const;
	bool exists() const;

private:
	openxds::base::String* original;
	openxds::base::String* protocol;
	openxds::base::String* hostname;
	openxds::base::String* volume;
	openxds::base::String* absolute;
	openxds::base::String* viewable;

	openxds::base::String* path;
	openxds::base::String* canonical;
	openxds::base::String* condensed;

	openxds::base::String* dirname;
	openxds::base::String* basename;
	openxds::base::String* extension;

	openxds::core::io::IPath* core;
};

};};

#endif
