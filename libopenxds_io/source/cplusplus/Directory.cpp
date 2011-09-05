/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

//#include "openxds.io/File.h"
//#include "openxds.io/psa/Directory.h"
//#include "openxds.io/psa/Path.h"
//#include "openxds.io/psa/SuperDirectory.h"

//#include <openxds/base/Iterator.h>
//#include <openxds/base/StringBuffer.h>
//#include <openxds/util/Sequence.h>

#include "openxds.io/Directory.h"
#include "openxds.io/Path.h"
#include <openxds.adt.std/Sequence.h>
#include <openxds.base/Runtime.h>
#include <openxds.core.io/Directory.h>
#include <openxds.core.adt/IPIterator.h>
#include <openxds.core.adt/ISequence.h>

using namespace openxds::adt;
using namespace openxds::adt::std;
using namespace openxds::base;
using namespace openxds::core::io;
using namespace openxds::io;
using namespace openxds::io::exceptions;
using namespace openxds::security::exceptions;
//using namespace openxds::io::psa;
//using namespace openxds::util;

Directory::Directory( const char* location )
{
	this->path = new Path( location );
	this->core = new_Directory( this->path->getOriginal().getChars() );
//	this->corenativeSuper = null;
//	this->native = null;
//	this->init();
}

//Directory::Directory( const String& location )
//{
//	this->path = new Path( location );
//	this->nativeSuper = null;
//	this->native = null;
//	this->init();
//}

//Directory::Directory( const Path& aPath )
//{
//	this->path = new Path( aPath );
//	this->nativeSuper = null;
//	this->native = null;
//	this->init();
//}

Directory::~Directory()
{
	this->core = this->core->free( this->core );
	delete this->path;
}

//void
//Directory::init()
//{
//	if ( !this->native )
//	{
//		switch ( this->path->getType() )
//		{
//		case Path::FS_DIRECTORY_SUPER:
//			this->nativeSuper = new_SuperDirectory();
//			break;
//		default:
//			this->native = new_Directory( this->path->getAbsolute().getChars() );
//		}
//	}
//}
//
//void
//Directory::open()
//throw (	AccessException*, FileNotFoundException*, IOException* )
//{
//	if ( this->native && (0 == Directory_refresh( (IDirectory*) this->native )) )
//	{
//		if ( Directory_exists( (IDirectory*) this->native ) )
//		{
//			throw new IOException();
//		} else {
//			throw new FileNotFoundException();
//		}
//	}
//}
//

void
Directory::create( bool recursive )
throw (	AccessException*, FileAlreadyExistsException*, IOException* )
{
	if ( recursive )
	{
		if ( ! this->core->createAll( this->core ) ) throw new IOException();
	}
	else
	{
		if ( ! this->core->createDir( this->core ) ) throw new IOException();
	}

//	if ( this->native && !Directory_exists( (IDirectory*) this->native ) )
//	{
//		if ( 0 == Directory_create( (IDirectory*) this->native ) )
//		{
//			if ( recursive )
//			{
//				Directory* d = this->parent();
//				d->create( recursive );
//				
//				if ( 0 == Directory_create( (IDirectory*) this->native ) )
//				{
//					throw new IOException( "Could not create directory" );
//				}
//				delete d;
//			} else {
//				throw new IOException( "Could not create directory" );
//			}
//		}
//	} else {
//		throw new FileAlreadyExistsException();
//	}
}

void
Directory::remove( bool recursive )
throw (	AccessException*, FileNotFoundException*, IOException* )
{
	if ( ! this->core->deleteDir( this->core ) )
	{
		throw new IOException();
	}

//	if ( !this->native )
//	{
//		throw new IOException();
//	}
//	else if ( (0 == Directory_delete( (IDirectory*) this->native )) )
//	{
//		if ( recursive )
//		{
//			const Path& path = this->getPath();
//		
//			Sequence* files = this->retrieveFileList();
//			Iterator* it = files->iterator();
//			while ( it->hasNext() )
//			{
//				const String& file = dynamic_cast<const String&>( it->next() );
//				if ( !file.equals( "." ) && !file.equals( ".." ) )
//				{
//					StringBuffer location;
//					location.append( path );
//					location.append( '/' );
//					location.append( file );
//			
//					if ( Directory_containsDirectory( (IDirectory*) this->native, file.getChars() ) )
//					{
//						Directory d( location.asString() );
//						d.remove( true );
//					}
//					else
//					{
//						File f( location.asString() );
//						f.remove();
//					}
//				}
//		
//				if ( 0 == Directory_delete( (IDirectory*) this->native ) )
//				{
//					throw new IOException();
//				}
//			}
//		}
//	}
}

//Directory*
//Directory::parent() const
//{
//	return new Directory( this->path->getDirname().getChars() );
//}
//
IList<String>*
Directory::retrieveFileList() const
{
	ISequence<String>* file_list = new Sequence<String>();
	{
		const openxds::core::adt::ISequence* files = this->core->getFiles( this->core );
		openxds::core::adt::IPIterator* it = files->positions( files );
		while ( it->hasNext( it ) )
		{
			const openxds::core::adt::IPosition* p = it->next( it );
			{
				const char* file = static_cast<const char*>( p->getElement( p ) );
				file_list->addLast( new String( file ) );
			}
		}
		it->free( it );
	}
	return file_list;
}

//Sequence*
//Directory::filenamesStartingWith( const String& pattern ) const
//{
//	Sequence* files = new Sequence();
//	IList* list = Directory_filenamesStartingWith( (IDirectory*) this->native, pattern.getChars() );
//	unsigned int length = List_count( list );
//	for ( unsigned int i=0; i < length; i++ )
//	{
//		files->add( new String( list->items[i] ) );
//	}
//	free_List( list );
//
//	return files;
//}
//
//Sequence*
//Directory::search( const String& pattern ) const
//{
//	Sequence* files = new Sequence();
//	IList* list = Directory_search( (IDirectory*) this->native, pattern.getChars(), true );
//	unsigned int length = List_count( list );
//	for ( unsigned int i=0; i < length; i++ )
//	{
//		files->add( new String( list->items[i] ) );
//	}
//	free_List( list );
//
//	return files;
//}

const Path&
Directory::getPath() const
{
	return *this->path;
}

bool
Directory::exists() const
{
	return this->core->exists( this->core );
}
