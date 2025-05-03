/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_PRINTER_H
#define OPENXDS_IO_PRINTER_H

#include <openxds.io.exceptions/IOException.h>
#include <openxds.io.h>
#include <openxds.base.h>
#include <openxds/Interface.h>

namespace openxds {
	namespace io {

class Printer : public openxds::Interface
{
public:
  virtual ~Printer();

  /*
   *  @deprecated.
   */
  virtual void print( const openxds::base::String* s ) const = 0;
  virtual void print( const openxds::base::String& s ) const = 0;
  virtual void print( openxds::base::String* s ) const = 0;
  virtual void print( const char* characters ) const = 0;
  virtual void print( const char* characters, long count ) const = 0;
  //virtual void printf( const char* format, ... ) const = 0;

  /*
   *  @deprecated.
   */
  virtual void println( const openxds::base::String* s ) const = 0;
  virtual void println( const openxds::base::String& s ) const = 0;
  virtual void println( openxds::base::String* s ) const = 0;
  virtual void println( const char* characters ) const = 0;
  virtual void println( const char* characters, long count ) const = 0;
  virtual void println() const = 0;
  virtual void printlnDos() const = 0;
  virtual void printlnMac() const = 0;
  virtual void printlnUnix() const = 0;

  virtual void flush() const = 0;
  virtual openxds::Object* clone() const = 0;

  //print( int i ) = 0;
  ///print( long l );
  //print( double d );
  //print( char c );
  //print( char* c );
  //print( unsigned int i );

};

};};

#endif
