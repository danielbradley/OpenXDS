/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_IOBUFFER_H
#define OPENXDS_IO_IOBUFFER_H

#include <openxds.io/IEndPoint.h>
#include <openxds.io.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.base.h>
#include <openxds/Object.h>

namespace openxds {
	namespace io {

class IOBuffer : public openxds::Object, public IEndPoint
{
private:
	openxds::base::DynamicBuffer* buffer;
	bool closed;

public:
	         IOBuffer();
	         IOBuffer( const openxds::base::String& str );
	virtual ~IOBuffer();

	virtual long read( byte* buffer, long bufferSize ) const
		throw (openxds::io::exceptions::IOException*);

	virtual long write( const byte* buffer, long count ) const
		throw (openxds::io::exceptions::IOException*);

//	virtual void
//		applyACL( const openxds::security::AccessControlList& acl )
//		throw (openxds::security::AccessException*, IOException*);

//	virtual void
//		control( int command, const openxds::base::String* args[] )
//		throw (IOException*);

//	virtual unsigned int
//		seek( unsigned int offset, unsigned int whence );

	virtual void flush() const
		throw (openxds::io::exceptions::IOException*);

	virtual void close()
		throw (openxds::io::exceptions::IOException*);

	virtual IEndPoint* duplicate() const
		throw (openxds::io::exceptions::IOException*);

	virtual openxds::Object* clone() const;

	virtual openxds::base::String* toString() const;

//	virtual const Address& getAddress() const;
//	virtual const Device& getDevice() const;

//	bool equals( const IOBuffer& io ) const;


//	FileAddress* address;
//	FileDescriptor* descriptor;
//	Device* device;

};

};};

#endif
