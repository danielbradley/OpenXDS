/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/security/Right.h>

#include <openxds/base/String.h>

#include <cstdio>

using namespace openxds::base;
using namespace openxds::security;

Right::Right( const String& aFamilyName, const String& aRight )
{
	this->family.familyDefiner = 0;
	this->family.family        = 0;
	this->familyName = new String( aFamilyName );
	this->right      = new String( aRight );
}

Right::Right( const Right& aRight )
{
	this->family.familyDefiner = aRight.family.familyDefiner;
	this->family.family        = aRight.family.family;
	this->familyName = new String( *aRight.familyName );
	this->right      = new String( *aRight.right );
}

Right::~Right()
{
  delete this->familyName;
  delete this->right;
}

const String&
Right::getFamilyName() const
{
	return *this->familyName;
}

const String&
Right::getRight() const
{
	return *this->right;
}

bool
Right::equals( const Object& obj ) const
{
	bool result = false;
  
	const Right* r = dynamic_cast<const Right*>( &obj );
	if ( null != r )
	{
		if ( this->getFamilyName().equals( r->getFamilyName() ) )
		{
			if ( this->getRight().equals( r->getRight() ) )
			{
				result = true;
			}
		}
	}
	return result;
}

Right*
Right::copy() const
{
	return new Right( *this );
}

