/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds/security/Right.h"
#include "openxds/security/RightsList.h"

#include <openxds/base/Iterator.h>
#include <openxds/util/List.h>

//Debug
#include <cstdio>

using namespace openxds::base;
using namespace openxds::util;
using namespace openxds::security;

RightsList::RightsList()
{
  this->list = new List();
}

RightsList::RightsList( const RightsList& aRightsList )
{
	this->list = new List();
	Iterator* it = aRightsList.rights();
	while ( it->hasNext() )
	{
		const Right& aRight = dynamic_cast<const Right&>( it->next() );
		this->list->append( aRight.copy() );
	}
	delete it;
}

RightsList::~RightsList()
{
	delete this->list;
}

void
RightsList::add( const Right& aRight )
{
  this->list->append( aRight.copy() );
}

Iterator*
RightsList::rights() const
{
	return this->list->iterator();
}

RightsList*
RightsList::copy() const
{
	return new RightsList( *this );
}

/** 

SecurityAttribute* attr;

RightsList* list = acl->get( attr );

Right read( "unix", "r" );
Right write( "unix", "w" );

if ( list->contains( &read ) )
{
  list->remove( read );
}
list->add( &right );


*/
