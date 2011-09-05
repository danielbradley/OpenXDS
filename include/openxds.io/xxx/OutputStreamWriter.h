/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENOCL_IO_OUTPUTSTREAMWRITER_H_
#define _OPENOCL_IO_OUTPUTSTREAMWRITER_H_

#include <openxds/base/Object.h>
#include <openxds/io/Writer.h>

#include <openxds/base.h>
#include <openxds/io.h>

namespace openxds {
  namespace io {

class OutputStreamWriter : public openxds::base::Object, public Writer
{
public:
  OutputStreamWriter( const OutputStream& ostream );
  OutputStreamWriter( OutputStream* ostream );
  virtual ~OutputStreamWriter() throw (IOException*);

  virtual void close();
  virtual void flush() const;
  virtual void write( const char* characters,
                      unsigned int offset,
                      unsigned int count ) const
      throw (IOException*);

  virtual void write( char characters ) const
      throw (IOException*);

  virtual void write( const openxds::base::String* str,
                      unsigned int offset,
                      unsigned int count ) const
      throw (IOException*);

  virtual openxds::base::Object* clone() const;

  virtual void print( const openxds::base::String* s ) const throw (IOException*);
  virtual void print( const char* characters, unsigned int count ) const throw (IOException*);
  virtual void println() const;
  virtual void println( const openxds::base::String* s ) const throw (IOException*);
  virtual void println( const char* characters, unsigned int count ) const throw (IOException*);


  //print( int i ) = 0;
  ///print( long l );
  //print( double d );
  //print( char c );
  //print( char* c );
  //print( unsigned int i );
private:
  bool isReference;
  OutputStream* os;
};

};};

#endif
