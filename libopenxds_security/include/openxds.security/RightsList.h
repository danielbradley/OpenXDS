/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_RIGHTSLIST_H
#define OPENXDS_SECURITY_RIGHTSLIST_H

#include "openxds.security.h"
#include <openxds.base/Object.h>
#include <openxds.base.h>
#include <openxds.util.h>

namespace openxds {
	namespace security {

/**
 *  RightsList take const parameters because they copy the
 *  value into their internal state. <p>
 *
 *  This allows Right objects to be static constants. <p>
 */
class RightsList : public openxds::base::Object
{
public:
	RightsList();
	~RightsList();
  
	void add( const Right& aRight );

	bool contains( const Right& aRight ) const;

	openxds::base::Iterator* rights() const;
	RightsList* copy() const;

private:
	explicit RightsList( const RightsList& aRightsList );
	openxds::util::List* list;
};

};};

#endif
