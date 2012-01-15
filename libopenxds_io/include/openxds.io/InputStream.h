/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_INPUTSTREAM_H
#define OPENXDS_IO_INPUTSTREAM_H

#include <openxds.io.h>
#include <openxds/Object.h>
#include <openxds/ICloneable.h>
#include <openxds.io.exceptions.h>
#include <openxds.io.exceptions/IOException.h>

namespace openxds {
	namespace io {

class InputStream : public openxds::Object
{
public:
  static const int EOS = -1;

  InputStream( const IEndPoint& io );
  InputStream( IEndPoint* io );
  virtual ~InputStream();

  virtual void close();

  virtual long read() const
      throw (openxds::io::exceptions::IOException*);

  virtual long
      read( byte* buf, long offset, long nrToRead ) const
      throw (openxds::io::exceptions::IOException*);

  //virtual int available();
public:
  //virtual void reset();
  //virtual void skip( long n );

  InputStream();
protected:
  IEndPoint& getIEndPoint() const;

private:
  bool isReference;
  IEndPoint* endPoint;
};

};};

#endif
