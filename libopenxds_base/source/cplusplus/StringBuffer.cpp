/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.base/StringBuffer.h>

//#include "openxds.base/FormattedString.h"
#include "openxds.base/Math.h"
#include "openxds.base/String.h"

#include "openxds.exceptions/IndexOutOfBoundsException.h"

using namespace openxds;
using namespace openxds::base;
using namespace openxds::exceptions;

const static int DEFAULT_CAPACITY = 256;
const static int GROWTH_RATE = 2;

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

/******************************************************************************
 *  Creates an empty String. <p>
 */
StringBuffer::StringBuffer()
{
	//Debug::entering( "StringBuffer", "StringBuffer", "" );
	{
		this->initialize( DEFAULT_CAPACITY );
		this->tmp = (String*) null;
	}
	//Debug::leaving();
}

StringBuffer::~StringBuffer()
{
	//Debug::entering( "StringBuffer", "~StringBuffer", "" );

	delete this->data;

	if ( null != this->tmp )
	{
		delete this->tmp;
	}
	
	//Debug::leaving();
}

void
StringBuffer::clear()
{
	delete this->data;
	if ( null != this->tmp )
	{
		delete this->tmp;
		this->tmp = (String*) null;
	}
	this->initialize( DEFAULT_CAPACITY );
}


void
StringBuffer::initialize( int initialCapacity )
{
	//Debug::entering( "StringBuffer", "initialize", "..." );

	this->capacity = initialCapacity;
	this->length = 0;
	this->data = new char[initialCapacity];
	this->data[this->length] = '\0';

	//Debug::leaving();
}

void
StringBuffer::append( long character )
{
	//	//Debug::entering( "StringBuffer", "append", "int" );

	if ( this->isFull() )
	{
		this->expand();
	}

	this->data[this->length] = character;
	this->length++;
	this->data[this->length] = '\0';

	//	//Debug::leaving();
}

void
StringBuffer::append( const char* aCString )
{
	//	//Debug::entering( "StringBuffer", "append", "const char*" );
	{
		String s( aCString );
		this->append( s );
	}
	//	//Debug::leaving();
} 

static byte hexValue( char c )
{
	byte r = 0;
	switch ( c )
	{
	case '0': r = 0; break;
	case '1': r = 1; break;
	case '2': r = 2; break;
	case '3': r = 3; break;
	case '4': r = 4; break;
	case '5': r = 5; break;
	case '6': r = 6; break;
	case '7': r = 7; break;
	case '8': r = 8; break;
	case '9': r = 9; break;
	case 'A': r = 10; break;
	case 'B': r = 11; break;
	case 'C': r = 12; break;
	case 'D': r = 13; break;
	case 'E': r = 14; break;
	case 'F': r = 15;
	case 'a': r = 10; break;
	case 'b': r = 11; break;
	case 'c': r = 12; break;
	case 'd': r = 13; break;
	case 'e': r = 14; break;
	case 'f': r = 15;
	}
	return r;
}

void
StringBuffer::appendHex( const char* aCString )
{
	byte value = 0;
	if ( ((aCString[0] == '%') && aCString[1] && aCString[2] ) )
	{
		value = hexValue( aCString[1] ) << 4;
		value += hexValue( aCString[2] );
	}
	else if ( aCString[0] && aCString[1] )
	{
		value = hexValue( aCString[0] ) << 4;
		value += hexValue( aCString[1] );
	}
	//this->append( FormattedString( "%c", value ) );
	//FIXME
}

void
StringBuffer::append( const String& aString )
{
	//	//Debug::entering( "StringBuffer", "append", "const String&" );

	long last = aString.getLength();
	for ( long i=0; i < last; i++ )
	{
 		this->append( aString.charAt( i ) );
	}

	//	//Debug::leaving();
}

//void
//StringBuffer::append( const Object& anObject )
//{
//	//	//Debug::entering( "StringBuffer", "append", "const Object&" );
//
//	String* s = anObject.asString();
//	this->append( *s );
//	delete s;
//
//	//	//Debug::leaving();
//}

void
StringBuffer::insertCharAt( int index, unsigned int value )
throw (IndexOutOfBoundsException*)
{
	if ( index == Math::between( index, 0, this->length ) )
	{
		this->shuffleDown( index );
		this->data[index] = value;
	} else {
		throw new IndexOutOfBoundsException( index );
	}
}

void
StringBuffer::removeCharAt( int index )
throw (IndexOutOfBoundsException*)
{
	if ( index == Math::between( index, 0, this->length - 1 ) )
	{
		this->shuffleUp( index );
	} else {
		throw new IndexOutOfBoundsException( index );
	}
}

void
StringBuffer::removeLast()
{
	if ( this->length )
	{
		this->length--;
		this->data[this->length] = '\0';
	}
}

int
StringBuffer::remove( char ch )
{
	int c = 0;
	int n = this->getLength();
				
	for ( int i=n-1; i >= 0; i-- )
	{
		if ( ch == this->data[i] )
		{
			this->removeCharAt( i );
			c++;
		}
	}
	return c;
}

int
StringBuffer::replace( char ch, char chx )
{
	int c = 0;
	int n = this->getLength();
				
	for ( int i=0; i < n; i++ )
	{
		if ( ch == this->data[i] )
		{
			this->data[i] = chx;
			c++;
		}
	}
	return c;
}

Object*
StringBuffer::clone() const
{
	StringBuffer* sb = new StringBuffer();
	sb->append( this->data );
	return sb;
}
	
String*
StringBuffer::asString() const
{
	//Debug::entering( "StringBuffer", "toString", "" );
	String* str = new String( (const char*) this->data );
	//Debug::leaving();
	return str;
}

const String&
StringBuffer::getContent() const
{
	StringBuffer* thisRW = (StringBuffer*) this;
	if ( null != thisRW->tmp )
	{
		delete thisRW->tmp;
	}
	thisRW->tmp = this->asString();

	return *this->tmp;
}

char
StringBuffer::charAt( int index ) const
throw (IndexOutOfBoundsException*)
{  
	if( index >= this->getLength() )
	{
		throw new IndexOutOfBoundsException( index );
	} else {
	return this->data[index];
	}
}

const char*
StringBuffer::getChars() const
{
  return this->data;
}

int
StringBuffer::getLength() const
{
  return this->length;
}

bool
StringBuffer::isFull() const
{
  if ( (this->length + 1) < this->capacity )
  { 
    return false;
  } else {
    return true;
  }
}

void
StringBuffer::expand()
{
	//Debug::entering( "StringBuffer", "expand", "..." );

	int newCapacity = this->capacity * GROWTH_RATE;
	char* newBuffer = new char[newCapacity];
	char* oldBuffer = this->data;

	for ( int i=this->length; i > 0; i-- )
	{
		newBuffer[i] = oldBuffer[i];
	}
	newBuffer[0] = oldBuffer[0];

	this->data = newBuffer;
	this->capacity = newCapacity;

	delete oldBuffer;

	//Debug::leaving();
}

void
StringBuffer::shuffleUp( int index )
{
	for ( int i=index; i < this->length; i++ )
	{
		this->data[i] = this->data[i+1];
	}
	this->length--;
}

void
StringBuffer::shuffleDown( int index )
{
	if ( this->isFull() )
	{
		this->expand();
	}

	//	By increasing length at start, first copy of loop copies
	//	null terminator of string.

	this->length++;
	int len = this->length;
	for ( int i=len; i > index; i-- )
	{
		this->data[i] = this->data[i-1];
	}
}

