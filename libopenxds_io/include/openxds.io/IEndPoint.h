/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_IENDPOINT_H
#define OPENXDS_IO_IENDPOINT_H

#include "openxds.io.exceptions/IOException.h"
#include <openxds/Interface.h>
#include <openxds.base.h>

//#undef EOF

namespace openxds {
	namespace io {

class IEndPoint : public openxds::Interface
{
public:
	static const unsigned int XEOF = OPENXDS_IO_EOF;

	virtual ~IEndPoint() {};

	virtual long read( byte* buffer, long bufferSize ) const
		throw (openxds::io::exceptions::IOException*) = 0;

	virtual long write( const byte* buffer, long count ) const
		throw (openxds::io::exceptions::IOException*) = 0;

//  virtual void
//      applyACL( const openxds::security::AccessControlList& acl )
//      throw (openxds::security::AccessException*, IOException*) = 0;

//  virtual void
//  control( int command, const openxds::base::String* args[] )
//      throw (openxds::io::exceptions::IOException*) = 0;
//
//  virtual unsigned int
//  seek( unsigned int offset, unsigned int whence ) = 0;

	virtual void flush() const throw (openxds::io::exceptions::IOException*) = 0;
	virtual void close() = 0;

//  virtual IEndPoint* duplicate() const
//      throw (openxds::io::exceptions::IOException*) = 0;

	virtual openxds::Object* clone() const = 0;

//  virtual const Address& getAddress() const = 0;
  //virtual const Descriptor& getDescriptor() const = 0;
//  virtual const Device& getDevice() const = 0;

};

};};

#endif

