/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_EXCEPTIONS_IOEXCEPTION_H
#define OPENXDS_IO_EXCEPTIONS_IOEXCEPTION_H

#include "openxds.io.h"

#include <openxds.base.h>
#include <openxds/Exception.h>

namespace openxds {
	namespace io {
		namespace exceptions {

class IOException : public openxds::Exception
{
public:
  IOException() {};
  IOException( const char* aMessage ) : Exception( aMessage ) {}
//  IOException( int errno );
  virtual ~IOException() {}
  
  virtual const char* getType() const { return "IOException"; }
};

};};};

#endif
