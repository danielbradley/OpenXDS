/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_IADDRESS_H
#define OPENXDS_IO_IADDRESS_H

#include <openxds/Interface.h>
#include <openxds.base.h>

namespace openxds {
	namespace io {

class IAddress : public openxds::ICloneable
{
public:
	virtual ~IAddress() {};

	virtual bool                     equals( const IAddress& address ) const = 0;
	virtual openxds::Object*          clone() const = 0; 
	virtual openxds::base::String* toString() const = 0;
};

};};

#endif
