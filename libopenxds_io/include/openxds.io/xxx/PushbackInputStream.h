/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENOCL_IO_PUSHBACKINPUTSTREAM_H_
#define _OPENOCL_IO_PUSHBACKINPUTSTREAM_H_

#include <openxds/io/InputStream.h>

#include <openxds/io.h>
#include <openxds/util.h>

namespace openxds {
  namespace io {

class PushbackInputStream : public InputStream
{
public:
  /*
   *  @deprecated.
   */
  PushbackInputStream( InputStream* istream );
  PushbackInputStream( const InputStream& istream );
  virtual ~PushbackInputStream();

  virtual int read() throw (IOException*);
  virtual unsigned int
      read( byte* buf, unsigned int offset, unsigned int nrToRead )
      throw (IOException*);

  virtual void unread( byte value ) throw (IOException*);
  virtual void unread( const byte* buf,
                       unsigned int offset,
                       unsigned int nrToUnread )
      throw (IOException*);

  virtual void close();  
private:
  bool isReference;
  InputStream* istream;

  openxds::util::CircularByteBuffer* buffer;
};

};}; // end of openxds::io namespace scope.

#endif // _OPENOCL_IO_PUSHBACKINPUTSTREAM_H_
