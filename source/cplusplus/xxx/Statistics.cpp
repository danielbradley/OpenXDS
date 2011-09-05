/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/io/Statistics.h>

#include <openxds/base/Object.h>
#include <openxds/base/StringBuffer.h>
#include <openxds/base/String.h>
#include <openxds/io/Address.h>
#include <openxds/security/AccessControlList.h>
#include <openxds/security/Principal.h>

using namespace openxds::base;
using namespace openxds::io;

Statistics::Statistics()
{
	this->address = null;
	this->owner = null;
	this->acl = null; 
}

Statistics::~Statistics()
{
	if ( this->address ) delete this->address;
	if ( this->owner ) delete this->owner;
	if ( this->acl ) delete this->acl;
}

const Address&
Statistics::getAddress() const
{
  return *this->address;
}

void
Statistics::setAddress( Address* anAddress )
{
  this->address = anAddress;
}

/*
void
Statistics::setLinks( unsigned int numberOfLinks )
{
  this->links = numberOfLinks;
}
*/

bool
Statistics::equals( const Object& anObject ) const
{
  bool equal = false;

  const Statistics* stat = dynamic_cast<const Statistics*>( &anObject );
  if ( null != stat ) {
    if ( this->address->equals( *stat->address ) ) {
      equal = true;
    }
  }

  return equal;
}

/*
Object*
Statistics::clone() const
{
  Statistics* stat = new Statistics();
  stat->setAddress( (Address*) this->address->clone() );

  stat->links = this->links;

  stat->owner = (openxds::security::Principal*) this->owner->clone();
  stat->acl = (openxds::security::AccessControlList*) this->acl->clone();

  stat->size = this->size;
  stat->blockSize = this->blockSize;
  stat->blocks = this->blocks;

  return stat;
}
*/

String*
Statistics::toString() const
{
  StringBuffer sb;

  if ( null != this->address )
  {
    String* addr = this->address->toString();
    sb.append( *addr );
    sb.append( '\n' );
    delete addr;
  }

  if ( null != this->owner )
  {
    String* own = owner->toString();
    sb.append( *own );
    delete own;
    sb.append( '\n' );
  }

  String sz1( "size: " );
  String sz2( this->size );
  sb.append( sz1 );
  sb.append( sz2 );
  sb.append( '\n' );

  String bs1( "block size: " );
  String bs2( this->blockSize );
  sb.append( bs1 );
  sb.append( bs2 );
  sb.append( '\n' );

  String bks1( "blocks: " );
  String bks2( this->blocks );
  sb.append( bks1 );
  sb.append( bks2 );
  sb.append( '\n' );

  return sb.toString();
}
