/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENOCL_IO_UNDELETABLEPRINTWRITER_H_
#define _OPENOCL_IO_UNDELETABLEPRINTWRITER_H_

#include <openxds/io/PrintWriter.h>
#include <openxds/io/File.h>
#include <openxds/io/FileDescriptor.h>
#include <openxds/io/OutputStream.h>

#include <openxds/base.h>
#include <openxds/io.h>

namespace openxds {
  namespace io {

class UndeletablePrintWriter
: public openxds::base::Object, public Printer, public Writer
{
public:
  UndeletablePrintWriter();
  virtual ~UndeletablePrintWriter()
      throw (IOException*, openxds::base::RuntimeException*);

  virtual void close();

  virtual void print( const openxds::base::String* s ) const
               throw (IOException*);
  virtual void print( const char* characters ) const
               throw (IOException*);
  virtual void print( const char* characters, unsigned int count ) const
               throw (IOException*);
  virtual void println() const;
  virtual void println( const openxds::base::String* s ) const
               throw(IOException*);
  virtual void println( const char* characters ) const
               throw (IOException*);
  virtual void println( const char* characters, unsigned int count ) const
               throw (IOException*);

  // Writer Implementations
  virtual void flush() const throw (IOException*);
  
  
  virtual void write( const char* characters,
                      unsigned int offset,
                      unsigned int count ) const
      throw (IOException*);

  virtual void write( char character ) const
      throw (IOException*);

  virtual void write( const openxds::base::String* str,
                      unsigned int offset,
                      unsigned int count ) const
      throw (IOException*);

  virtual openxds::base::Object* clone() const;

private:
  static const FileDescriptor FD;
  static const File FILE;
  static const OutputStream OS;
};

};};

#endif
