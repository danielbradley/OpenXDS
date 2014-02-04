/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.io/InputStream.h"

#include <openxds.exceptions/ImplementationException.h>
#include <openxds.base/Runtime.h>
#include <openxds.io/IEndPoint.h>
#include <openxds.io.exceptions/IOException.h>

using namespace openxds::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

//const int InputStream::EOS;

InputStream::InputStream()
{
  this->endPoint = null;
}

InputStream::InputStream( const IEndPoint& io )
{
	this->isReference = true;
	this->endPoint = const_cast<IEndPoint*>( &io );
}

InputStream::InputStream( IEndPoint* io )
{
	this->isReference = false;
	this->endPoint = const_cast<IEndPoint*>( io );
}

/**
 *
 *  Object - -> IOEndPoint
 *       |    /
 *       |   /
 *       File
 *
 *  Need to perform a dynamic cast here as we are
 *  casting the object returned from io->clone()
 *  across the heirarchy to IOEndPoint. <p>
 *
 *  Note: Removed because I felt it safe to not
 *        clone objects being passed in. If somebody
 *        wants these semantics these can easily
 *        clone the object themselves. <p>
 *
 * InputStream::InputStream( const IOEndPoint* io )
 * {
 *   //  Note: dynamic cast is needed here because
 *   //  we are casting across the inheritance
 *   //  hierarchy from Object* to IOEndPoint
 *   //
 *   //          Interface
 *   //              |
 *   //  Object IOEndPoint
 *   //     |   /
 *   //     File
 * 
 *   this->ioEndPoint = dynamic_cast<IOEndPoint*>( io->clone() );
 * }
 *
 */

InputStream::~InputStream()
{
	if ( (false == this->isReference) && (null != this->endPoint) )
	{
		delete this->endPoint;
	}
}

void
InputStream::close()
{
	if ( false == this->isReference )
	{
		this->endPoint->close();
	}
}

long
InputStream::read() const
throw (IOException*)
{
	int ret = EOS;

	byte buf[1];
	long nrRead = this->endPoint->read( buf, 1 );

	switch ( nrRead )
	{
	case OPENXDS_IO_EOF:
		break;
	default:
		ret = buf[0];
	}
	return ret;
}

long
InputStream::read( byte* buf,
                   long offset,
                   long nrToRead ) const
throw (IOException*)
{
	long nrRead = this->endPoint->read( buf, nrToRead );

	if ( IEndPoint::XEOF == nrRead )
	{
		return OPENXDS_IO_EOS;
	} else {
		return nrRead;
	}
}

IEndPoint&
InputStream::getIEndPoint() const
{
	return *this->endPoint;
}
