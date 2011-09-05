/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.base/String.h"

#include "openxds.exceptions/IndexOutOfBoundsException.h"

#include <openxds.core.adt.std/StdString.h>
#include <openxds.core.base/Math.h>

#include <cstdlib>
#include <cstdarg>
#include <cstdio> // These should be removed once exceptions are implemented.
#include <cstring>
#include <new>
//#include <cmath>
#include <errno.h>

/**
 *  This tells the compiler that class String has been declared
 *  within the particular namespace. <p>
 */  
using namespace openxds;
using namespace openxds::base;
using namespace openxds::exceptions;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;

const bool String::debug = false;
//static const char* NULLSTRING = "null";

//static int hashCode1( const char* buf, int len );
static int hashCode2( const char* buf, int len );

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

/******************************************************************************
 *  Creates an empty String. <p>
 */
String::String() : Object()
{
	this->_data = new_StdString( "" );
}

String::String( const char* chars, long offset, long length )
{
	this->_data = new_StdString_start_length( chars, offset, length );
}

String::String( const char* string ) : Object()
{
	this->_data = new_StdString( string );
}

String::String( const String& aString ) : Object()
{
	this->_data = StdString_copy( (StdString*) aString._data ); 
}

String::String( int number ) : Object()
{
	char *value = new char[ 128 ];
	sprintf( value, "%i", number);
	
	this->_data = new_StdString( value );
	
	delete value;
}

String::~String()
{
	free_StdString( (StdString*) this->_data );
}

//-----------------------------------------------------------------------------
// Virtual Methods from Object
//-----------------------------------------------------------------------------

Object* String::clone() const
{
	return new String( *this );
}

String* String::asString() const
{
	String* str = new String( *this );
	return str;
}

bool String::equals( const Object* obj ) const
{
  return this->equals( *obj );
}

bool String::equals( const Object& obj ) const
{
	const String& cast = dynamic_cast<const String&>( obj );
	if ( null == &cast )
	{
		return false;
	} else {
		return ( 0 == this->compareTo( cast ) );
	}
} 

bool
String::equals( const String& aString ) const
{
	return ( 0 == this->compareTo( aString ) );
}
  
//----------------------------------------------------------------------------- 
// Public Methods Implemented For Objects
//-----------------------------------------------------------------------------

char String::charAt( long index ) const
throw (IndexOutOfBoundsException*)
{
	if ( index >= this->getLength() )
	{
		throw new IndexOutOfBoundsException( (int) index );
	} else {
		return StdString_charAt( (StdString*) this->_data, (int) index );
	}
}

int String::compareTo( const String* anotherString ) const
{
	return compareTo( *anotherString );
}

int
String::compareTo( const String& anotherString ) const
{
	return StdString_compare( (StdString*) this->_data, StdString_getChars( (StdString*) anotherString._data ) );
}

//int String::compareTo( const char StdString[] ) const
//{
//  return strcmp(this->data, StdString);
//}

/**
 *  Returns the characters between start and end. <p>
 *
 *  Note: this is different to the Java String object
 *        which returns start --> end - 1.
 */
String*
String::substring( long start, long end ) const
throw (IndexOutOfBoundsException*)
{
	long lastIndex = this->getLength() - 1;
	if ( end > lastIndex )
	{
		throw new IndexOutOfBoundsException( end );
	}
	if ( start > end )
	{
		return new String();
		//throw new IndexOutOfBoundsException( start );
	}
	long count = (end - start) + 1;

	return new String( StdString_getChars( (StdString*) this->_data ), start, count );
}

const byte*const String::getBytes() const
{
	return (const byte*const) StdString_getChars( (StdString*) this->_data );
}

const char* String::getChars() const
{
  return StdString_getChars( (StdString*) this->_data );
}

long String::getLength() const
{
	return StdString_getLength( (StdString*) this->_data );
}

bool
String::contentEquals( const String& str ) const
{
	return (0 == this->compareTo( str ));
}

bool
String::contains( const String& token ) const
{
	return StdString_contains( (StdString*) this->_data, token.getChars() );
}

bool
String::startsWith( const String& prefix ) const
{
	return StdString_startsWith( (StdString*) this->_data, prefix.getChars() );
}

//bool
//String::endsWith( const String& suffix ) const
//{
//	return StdString_endsWith( this->data, suffix.getChars() );
//}
//
//bool
//String::matches( const String& pattern ) const
//{
//	return StdString_matches( this->data, pattern.getChars() );
//}
//
//bool
//String::isNumber() const
//{
//	bool is_number = false;
//
//	if ( 0 < this->getLength() )
//	{	
//		try
//		{
//			this->getValue();
//			is_number = true;
//		} catch ( Exception* ex ) {
//			delete ex;
//		}
//	}
//	return is_number;
//}
//
////-----------------------------------------------------------------------------
//// Protected Methods
////-----------------------------------------------------------------------------
//
//void String::setLength( int length )
//{
//  this->length = length;
//}
//
//void String::setSize( int size )
//{
//  this->size = size;
//}
//
////-----------------------------------------------------------------------------
//// Static Private Methods
////-----------------------------------------------------------------------------
//
//char* String::copy( const char* src )
//{
//  //int len = strlen( src );
//  //char* dest = new char[len + 1];
//  //return strncpy( dest, src, len );
//
//	unsigned int len = strlen( src );
//	char* dest = new char[len + 1];	Debug::returnedMemory();
//	stringCopy( dest, src, len + 1 );
//	return dest;
//}
//
//char* String::copy( const char* src, unsigned int count )
//{
//	char* dest = new char[count+1];		Debug::returnedMemory();
//	stringCopy( dest, src, count + 1 );
//	return dest;
//}
//
//void
//String::stringCopy(char* dest, const char* src, unsigned int n )
//{
//	bool pad = false;
//	int nn = n;
//	int i;
//	for( i=0; i < (nn-1); i++ )
//	{
//		if ( pad )
//		{
//			dest[i] = '\0';
//		} else {
//			dest[i] = src[i];
//			if ( '\0' == src[i] ) {
//				pad = true;
//			}
//		}
//	}
//	dest[i] = '\0';
//}
//
///*
//bool
//String::isNumberStatic( const char* string, long double* value )
//{
//	if ( null != string )
//	{
//		*value = strtold( string, (char**) NULL );
//		int i = (int) *value;
//		switch ( i )
//		{
//		case 0:
//			if ( string[0] != '0' )
//			{
//				return false;
//			}
//			// Intentional fall through
//		default:
//			return true;
//		}
//	} else {
//		return false;
//	}
//}
//*/
