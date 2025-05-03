/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.base/String.h"
#include "openxds.base/StringBuffer.h"
#include "openxds.exceptions/IndexOutOfBoundsException.h"

#include <openxds.core.adt.std/StdString.h>
#include <openxds.core.base/Math.h>

#include <cstdlib>
#include <cstdarg>
#include <cstdio> // These should be removed once exceptions are implemented.
#include <cstring>
#include <new>
#include <errno.h>

using namespace openxds;
using namespace openxds::base;
using namespace openxds::exceptions;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;

const bool String::debug = false;
static int hashCode2( const char* buf, int len );


const String String::_emptyString;

const String& String::emptyString()
{
	return String::_emptyString;
}



String::String() : Object()
{
	this->_data = new_StdString( "" );
	this->chars = this->getChars();
}

String::String( char ch )
{
	char chars[2];
	chars[0] = ch;
	chars[1] = '\0';

	this->_data = new_StdString( chars );
	this->chars = this->getChars();
}

String::String( const char* chars, long offset, long length )
{
	this->_data = new_StdString_start_length( chars, offset, length );
	this->chars = this->getChars();
}

String::String( const char* string ) : Object()
{
	this->_data = new_StdString( string );
	this->chars = this->getChars();
}

String::String( const String& aString ) : Object()
{
	this->_data = StdString_copy( (StdString*) aString._data ); 
	this->chars = this->getChars();
}

String::String( int number ) : Object()
{
	char *value = new char[ 128 ];
	snprintf( value, 128, "%i", number);
	
	this->_data = new_StdString( value );
	
	delete[] value;
	this->chars = this->getChars();
}

String::~String()
{
	free_StdString( (StdString*) this->_data );
}

Object* String::clone() const
{
	return new String( *this );
}

String* String::asString() const
{
	String* str = new String( *this );
	return str;
}

bool String::equals( const Object& obj ) const
{
	const Object* tmp = &obj;

	const String* cast = dynamic_cast<const String*>( tmp );
	if ( null == cast )
	{
		return false;
	} else {
		return ( 0 == this->compareTo( *cast ) );
	}
}

/*
 *	Deprecated
 */
bool String::equals( const Object* obj ) const
{
	return this->equals( *obj );
}

bool String::equals( const String& string ) const
{
	return ( 0 == this->compareTo( string ) );
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

int
String::compareTo( const String& anotherString ) const
{
	return StdString_compare( (StdString*) this->_data, StdString_getChars( (StdString*) anotherString._data ) );
}

int String::compareTo( const String* anotherString ) const
{
	return compareTo( *anotherString );
}

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
	}
	long count = (end - start) + 1;
	
	return new String( StdString_getChars( (StdString*) this->_data ), start, count );
}

String*
String::removeWhitespace() const
{
	String* ret = null;
	StdString* str = StdString_removeWhitespace( (StdString*) this->_data );
	{
		const char* chars = StdString_getChars( str );
		ret = new String( chars );
	}
	free_StdString( (StdString*) str );
	
	return ret;
}

String*
String::trim() const
{
	String* ret = null;
	StdString* str = StdString_trim( (StdString*) this->_data );
	{
		const char* chars = StdString_getChars( str );
		ret = new String( chars );
	}
	free_StdString( (StdString*) str );
	
	return ret;
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

bool
String::endsWith( const String& suffix ) const
{
	return StdString_endsWith( (StdString*) this->_data, suffix.getChars() );
}

bool
String::isOnlyWhitespace() const
{
	bool only_whitespace = true;
	long len = this->getLength();
	
	for ( long i=0; i < len; i++ )
	{
		switch ( this->chars[i] )
		{
		case '\t':
		case '\n':
		case ' ':
			break;
		default:
			only_whitespace = false;
			i = len;
			break;
		}
	}
	return only_whitespace;
}

bool
String::isEmpty() const
{
	return (0 == this->getLength());
}

String*
String::htmlEncode( const String& unencoded )
{
	StringBuffer sb;
	{
		long len = unencoded.getLength();
		
		for ( int i=0; i < len; i++ )
		{
			char ch = unencoded.charAt( i );
			
			switch ( ch )
			{
			case '>':
				sb.append( "&gt;" );
				break;
				
			case '<':
				sb.append( "&lt;" );
				break;
				
			default:
				sb.append( ch );
			}
		}
	}
	return sb.asString();
}

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

