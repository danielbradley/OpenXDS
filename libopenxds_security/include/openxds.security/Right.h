/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_RIGHT_H
#define OPENXDS_SECURITY_RIGHT_H

#include "openxds.security.h"
#include <openxds.base/Object.h>
#include <openxds.base.h>

namespace openxds {
	namespace security {

typedef struct {
	unsigned short familyDefiner;
	unsigned short family;
} ExtensibleFamily;

class Right : public openxds::base::Object
{
public:
	Right( const openxds::base::String& aFamilyName, const openxds::base::String& aRight );
	~Right();  

	const openxds::base::String& getFamilyName() const;
	const openxds::base::String& getRight() const;

	bool equals( const openxds::base::Object& obj ) const;

	Right* copy() const;

private:
	explicit Right( const Right& aRight );
	ExtensibleFamily family;
	openxds::base::String* familyName;
	openxds::base::String* right;
};

};};

#endif
