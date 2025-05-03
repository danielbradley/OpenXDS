/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_PRINTWRITER_H_
#define OPENXDS_IO_PRINTWRITER_H_

#include <openxds.io/Printer.h>
#include <openxds.io/Writer.h>
#include <openxds.io.h>
#include <openxds.base.h>
#include <openxds/Object.h>

namespace openxds {
	namespace io {

class PrintWriter : public openxds::Object, public Printer, public Writer
{
private:
  bool          isReference;
  OutputStream& os;

public:

  PrintWriter( OutputStream& ostream );
  PrintWriter( OutputStream* ostream );
  virtual ~PrintWriter();

  // Printer Implementations

  /*
   *  @deprecated.
   */
  virtual void print( const openxds::base::String* s ) const throw (openxds::io::exceptions::IOException*);
  virtual void print( const openxds::base::String& s ) const throw (openxds::io::exceptions::IOException*);
  virtual void print( openxds::base::String* s ) const throw (openxds::io::exceptions::IOException*);
  virtual void print( const char* characters ) const throw (openxds::io::exceptions::IOException*);
  virtual void print( const char* characters, long count ) const throw (openxds::io::exceptions::IOException*);
  virtual void printf( const char* format, ... ) const;
  virtual void println() const;
  virtual void printlnDos() const;
  virtual void printlnMac() const;
  virtual void printlnUnix() const;

  /*
   *  @deprecated.
   */
  virtual void println( const openxds::base::String* s ) const throw (openxds::io::exceptions::IOException*);
  virtual void println( const openxds::base::String& s ) const throw (openxds::io::exceptions::IOException*);
  virtual void println( openxds::base::String* s ) const throw (openxds::io::exceptions::IOException*);
  virtual void println( const char* characters ) const throw (openxds::io::exceptions::IOException*);
  virtual void println( const char* characters, long count ) const throw (openxds::io::exceptions::IOException*);


  // Writer Implementations
  
  virtual void close() throw (openxds::io::exceptions::IOException*);
  virtual void flush() const throw (openxds::io::exceptions::IOException*);
  
  virtual void write( const char* characters, long offset, long count ) const
      throw (openxds::io::exceptions::IOException*);
  virtual void write( char character ) const
      throw (openxds::io::exceptions::IOException*);
  virtual void write( const openxds::base::String* str, long offset, long count ) const
      throw (openxds::io::exceptions::IOException*);

  virtual openxds::Object* clone() const;

  virtual       openxds::io::OutputStream& getOutputStream();
  virtual const openxds::io::OutputStream& getOutputStream() const;



  //print( int i ) = 0;
  ///print( long l );
  //print( double d );
  //print( char c );
  //print( char* c );
  //print( unsigned int i );
};

};};

#endif
