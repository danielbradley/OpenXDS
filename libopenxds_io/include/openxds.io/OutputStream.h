/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_OUTPUTSTREAM_H
#define OPENXDS_IO_OUTPUTSTREAM_H

#include <openxds.io.h>
#include <openxds.io.exceptions/IOException.h>
#include <openxds.io.exceptions.h>
#include <openxds/Object.h>

namespace openxds {
	namespace io {

class OutputStream : public openxds::Object
{
public:
  OutputStream( IEndPoint& io );
  OutputStream( IEndPoint* io );

  virtual ~OutputStream();

  virtual bool open();
  virtual void close() const;
  virtual void flush() const throw (openxds::io::exceptions::IOException*);

  virtual void
      write( const byte value ) const throw (openxds::io::exceptions::IOException*);
  virtual void
      write( const byte* buf,
             long offset,
             long nrToWrite ) const throw (openxds::io::exceptions::IOException*);

	virtual void
		write( const char* format, ... ) const throw (openxds::io::exceptions::IOException*);

  virtual openxds::Object* clone() const;

	      IEndPoint& getIOEndPoint();
	const IEndPoint& getIOEndPoint() const;

protected:
  OutputStream();

private:
  bool isReference;
  IEndPoint* ioEndPoint;

  //const IOEndPoint* ioEndPoint;
  //const IOEndPoint* theirs;
  //IOEndPoint* ours;
};

};}; // end of openxds::io namespace scope.

#endif // _OPENOCL_IO_OUTPUTSTREAM_H_
