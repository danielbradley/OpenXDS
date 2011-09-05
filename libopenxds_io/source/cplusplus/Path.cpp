/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.io/Path.h"

#include <openxds.base/Runtime.h>
#include <openxds.base/StringBuffer.h>
#include <openxds.core.io/Path.h>

using namespace openxds::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;
using namespace openxds::core::io;

Path::Path( const char* aPath )
throw (IOException*)
{
	this->core     = new_Path( aPath );

	this->original = new String( aPath );

	this->protocol  = null;
	this->hostname  = null;
	this->volume    = null;
	this->absolute  = null;
	this->viewable  = null;

	this->path      = null;
	this->canonical = null;
	this->condensed = null;

	this->dirname   = null;
	this->basename  = null;
	this->extension = null;
}

Path::Path( const String& aPath )
throw (IOException*)
{
	this->core = new_Path( aPath.getChars() );

	this->original = new String( aPath );

	this->protocol  = null;
	this->hostname  = null;
	this->volume    = null;
	this->absolute  = null;
	this->viewable  = null;

	this->path      = null;
	this->canonical = null;
	this->condensed = null;

	this->dirname   = null;
	this->basename  = null;
	this->extension = null;
}

Path::Path( const Path& aPath )
throw (IOException*)
{
	const String& orig = aPath.getOriginal();

	this->core = new_Path( orig.getChars() );

	this->original = new String( orig );

	this->protocol  = null;
	this->hostname  = null;
	this->volume    = null;
	this->absolute  = null;
	this->viewable  = null;

	this->path      = null;
	this->canonical = null;
	this->condensed = null;

	this->dirname   = null;
	this->basename  = null;
	this->extension = null;
}

Path::~Path()
{
	if ( this->core )
	{
		this->core = this->core->free( this->core );
	}

	delete this->original;
	delete this->protocol;
	delete this->hostname;
	delete this->volume;
	delete this->absolute;
	delete this->viewable;

	delete this->path;
	delete this->canonical;
	delete this->condensed;

	delete this->dirname;
	delete this->basename;
	delete this->extension;
}

Path*
Path::childPath( const openxds::base::String& filename ) const
{
	StringBuffer sb;
	sb.append( this->getAbsolute() );
	sb.append( this->getFileSeparator() );
	sb.append( filename );
	
	return new Path( sb.getChars() );
}

const String&
Path::getOriginal() const
{
	return *this->original;
}

const String&
Path::getProtocol() const
{
	if ( !this->protocol )
	{
		const_cast<Path*>( this )->protocol = new String( this->core->getProtocol( (IPath*) this->core ) );
	}
	return *this->protocol;
}

const String&
Path::getHostname() const
{
	if ( !this->hostname )
	{
		const_cast<Path*>( this )->hostname = new String( this->core->getHostname( (IPath*) this->core ) );
	}
	return *this->hostname;
}

const String&
Path::getVolume() const
{
	if ( !this->volume )
	{
		const_cast<Path*>( this )->volume = new String( this->core->getVolume( (IPath*) this->core ) );
	}
	return *this->volume;
}

const String&
Path::getAbsolute() const
{
	if ( !this->absolute )
	{
		const_cast<Path*>( this )->absolute = new String( this->core->getAbsolute( (IPath*) this->core ) );
	}
	return *this->absolute;
}

const String&
Path::getViewable() const
{
	if ( !this->viewable )
	{
		const_cast<Path*>( this )->viewable = new String( this->core->getNativeFormat( (IPath*) this->core ) );
	}
	return *this->viewable;
}

const String&
Path::getPath() const
{
	if ( !this->path )
	{
		const_cast<Path*>( this )->path = new String( this->core->getCommon( (IPath*) this->core ) );
	}
	return *this->path;
}


const String&
Path::getCanonical() const
{
	if ( !this->canonical )
	{
		const_cast<Path*>( this )->canonical = new String( this->core->getCondensed( (IPath*) this->core ) );
	}
	return *this->canonical;
}

const String&
Path::getCondensed() const
{
	if ( !this->condensed )
	{
		const_cast<Path*>( this )->condensed = new String( this->core->getCondensed( (IPath*) this->core ) );
	}
	return *this->condensed;
}

const String&
Path::getPreferred() const
{
	if ( !this->path )
	{
		const_cast<Path*>( this )->path = new String( this->core->getCommon( (IPath*) this->core ) );
	}
	return *this->path;
}

const String&
Path::getDirectory() const
{
	if ( Path::DIRECTORY == this->getType() )
	{
		return this->getAbsolute();
	} else {
		return this->getDirname();
	}
}

const String&
Path::getDirname() const
{
	if ( !this->dirname )
	{
		const_cast<Path*>( this )->dirname = new String( this->core->getDirname( (IPath*) this->core ) );
	}
	return *this->dirname;
}

const String&
Path::getBasename() const
{
	if ( !this->basename )
	{
		const_cast<Path*>( this )->basename = new String( this->core->getBasename( (IPath*) this->core ) );
	}
	return *this->basename;
}

const String&
Path::getExtension() const
{
	if ( !this->extension )
	{
		const_cast<Path*>( this )->extension = new String( this->core->getExtension( (IPath*) this->core ) );
	}
	return *this->extension;
}

Path*
Path::getCurrentDirectory()
{
	Path* path;
	IPath* current = Path_GetCurrentDirectory();
	path = new Path( current->getAbsolute( current ) );
	current->free( current );
	return path;
}

char
Path::getFileSeparator()
{
	return Path_GetFileSeparator();
}

int
Path::getType() const
{
	return this->core->getType( this->core );
}

bool
Path::exists() const
{
	return this->getType();
}
