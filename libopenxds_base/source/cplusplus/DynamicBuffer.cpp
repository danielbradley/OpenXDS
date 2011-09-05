/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.base/DynamicBuffer.h"
#include "openxds.base/String.h"
#include "openxds.base/StringBuffer.h"

using namespace openxds::base;
using namespace openxds::exceptions;

/**
 *  This class implements a dynamic buffer. Similar to a normal
 *  buffer except that the buffer can dynamically grow. <p>
 *
 *  This is a fairly simple implementation, using a linked list. <p>
 */

typedef struct _Element Element;

struct _Element
{
  byte value;
  Element* next;
};

DynamicBuffer::DynamicBuffer()
{
  this->head = (void*) null;
  this->tail = (void*) null;
  this->size = 0;
}

DynamicBuffer::~DynamicBuffer()
{
  Element* e = (Element*) this->head;
  Element* next;
  while ( e != null )
  {
    next = e->next;
    delete e;
    e = next;
  }
}

byte
DynamicBuffer::read()
throw (NoSuchElementException*)
{
  byte val;

  if ( null == this->head ) {
    throw new NoSuchElementException( "empty buffer" );
  }

  Element* e = (Element*) this->head;

  this->head = (void*) e->next;
  if ( null == e->next ) {      // If buffer is now empty,
    this->tail = (void*) null;          // set tail to null.
  }

  val = e->value;
  delete e;
  return val;
}

void
DynamicBuffer::unread( byte value )
{
  Element* e = new Element;
  e->value = value;
  e->next = (Element*) this->head;
  this->head = (void*) e;

  if ( null == e->next ) {
    this->tail = (void*) e;
  }
}

void
DynamicBuffer::write( byte value )
{
  Element* e = new Element;
  e->value = value;
  e->next = (Element*) null;

  if ( null == this->head )
  {
    this->head = (void*) e;
  } else {
    Element* last = (Element*) this->tail;
    last->next = e;
  }

  this->tail = (void*) e;
}

void
DynamicBuffer::unwrite()
throw (NoSuchElementException*)
{
  if ( null == this->head ) {
    throw new NoSuchElementException();
  }

  Element* e = (Element*) this->head;
  if ( e != (Element*) this->tail )
  {
    while ( e->next != (Element*) this->tail ) {
      e = e->next;
    }
  }

  if ( e != this->tail )
  {
    this->tail = (void*) e;
    e = e->next;
  }

  delete e;
}

//ByteBuffer*
//DynamicBuffer::toByteBuffer() const
//{
//  unsigned int nr = 0;
//  Element* e = (Element*) this->head;
//  while ( null != e )
//  {
//    nr++;
//    e = e->next;
//  }
//
//  ByteBuffer* bb = new ByteBuffer( nr );
//  byte*const buf = bb->getContents();
//
//  e = (Element*) this->head;
//  for ( unsigned int i=0; i < nr; i++ )
//  {
//    buf[i] = e->value;
//    e = e->next;
//  }
//  return bb;
//}

String*
DynamicBuffer::toString() const
{
  StringBuffer sb;

  Element* e = (Element*) this->head;
  while ( null != e )
  {
    sb.append( (char) e->value );
    e = e->next;
  }
  return sb.asString();
}

bool
DynamicBuffer::isEmpty() const
{
  return ( null == this->head );
}

bool
DynamicBuffer::isNotEmpty() const
{
  return ( null != this->head );
}

DynamicBuffer*
DynamicBuffer::copy() const
{
  DynamicBuffer* db = new DynamicBuffer();

  Element* e = (Element*) this->head;
  while ( e != null )
  {
    db->write( e->value );
    e = e->next;
  }
  return db;
}
