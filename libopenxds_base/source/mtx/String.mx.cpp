.	String

..		Usage

Linkage:

~
-lopenxds_base
~

To use the class:

~
#include <openxds.base/String.h>

using namespace openxds::base;
~

!
~!include/openxds.base/String.h~
#ifndef OPENXDS_BASE_STRING_H
#define OPENXDS_BASE_STRING_H

#include <openxds/Object.h>

#include <openxds.base.h>
#include <openxds/ICloneable.h>
#include <openxds.base_exceptions.h>

namespace openxds {
	namespace base {
		
		class String : public Object, public ICloneable
		{
		public:
			
			//-------------------------------------------------------------------------
			// Constructors
			//-------------------------------------------------------------------------
			
			String();
			String( int number );
			String( const char* chars, long offset, long length );
			String( const char* chars );
			explicit String( const String& aString );
			virtual ~String();
			
			//---------------------------------------------------------------------------
			// Virtual Methods from Object
			//---------------------------------------------------------------------------
			
			virtual Object* clone() const;
			virtual String* asString() const; 
			
			/**
			 *  @deprecated
			 */
			virtual bool equals( const Object* obj ) const;
			
			virtual bool equals( const Object& obj ) const;
			virtual bool equals( const String& aString ) const;
			
			//-------------------------------------------------------------------------
			// Public Methods
			//-------------------------------------------------------------------------
			
			/**
			 *  Returns the character at the specified position. <p>
			 *
			 *  @param index, the index of the character to return.
			 *  @param bogus, a bogus parameter that doesn't exist.
			 *  @returns the character at index.
			 */
			char charAt( long index ) const throw (openxds::exceptions::IndexOutOfBoundsException*);
			
			/**
			 *  @deprecated
			 */
			int  compareTo( const String *anotherString ) const;
			
			int compareTo( const String& anotherString ) const;
			
			//int  compareTo( const char charString[] ) const;
			
			String* substring( long start, long end ) const
			throw (openxds::exceptions::IndexOutOfBoundsException*);
			
			const byte*const getBytes() const;
			const char* getChars() const;
			
			/**
			 *  Returns the length of the string (not counting '\0'). <p>
			 */
			long getLength() const;
			long getSize() const;
			
			
			double getValue() const throw (Exception*);
			int getValueAsInt() const throw (Exception*);
			long getValueAsLong() const throw (Exception*);
			long long getValueAsLongLong() const throw (Exception*);
			
			static char *copy( const char* src );
			static char *copy( const char* src, unsigned int count );
			
			bool contentEquals( const String& str ) const;
			bool contains( const String& token ) const;
			bool startsWith( const String& prefix ) const;
			bool endsWith( const String& suffix ) const;
			bool matches( const String& pattern ) const;
			bool isNumber() const;
			
		protected:
			static void stringCopy( char* dest, const char* src, unsigned int n );
			
			void initialize( const char* chars );
			
			const char* chars;
			void*       _data;
			
		private:
			static const bool debug;
		};
		
	};};

#endif
~
!

..		Method Summary

~html~
<table>
<thead>
<tr>
<th>Returns</th><th>Method-name</th><th colspan='3'>Parameters</th><th>Throws</th>
</tr>
</thead>
<tbody>
<tr><td><b>               </b></td> <td><a href='#String'                  >String             </a></td>                                                                                                 </tr>
<tr><td><b>               </b></td> <td><a href='#String(int)'             >String             </a></td> <td><b>int          </b> number   </td>                                                         </tr>
<tr><td><b>               </b></td> <td><a href='#String(char*,long,long)' >String             </a></td> <td><b>const char*  </b> chars    </td> <td><b>long</b> offset</td> <td><b>long</b> length</td> </tr>
<tr><td><b>               </b></td> <td><a href='#String(char*)'           >String             </a></td> <td><b>const char*  </b> chars    </td>                                                         </tr>
<tr><td><b>               </b></td> <td><a href='#String(String)'          >String             </a></td> <td><b>const String&</b> aString  </td>                                                         </tr>

<tr><td><b>Object*        </b></td> <td><a href='#clone'                   >clone              </a></td>                                                                                                 </tr>
<tr><td><b>String*        </b></td> <td><a href='#asString'                >asString           </a></td>                                                                                                 </tr>
<tr><td><b>bool           </b></td> <td><a href='#equals(Object)'          >equals             </a></td> <td><b>const Object&</b> anObject </td>                                                         </tr>
<tr><td><b>bool           </b></td> <td><a href='#equals'                  >equals             </a></td> <td><b>const String&</b> aString  </td>                                                         </tr>

<tr><td><b>char           </b></td> <td><a href='#charAt'                  >charAt             </a></td> <td><b>long         </b> index    </td> <td><b>    </b>       </td> <td><b>    </b>       </td> <td>IndexOutOfBoundsException*</td> </tr>

<tr><td><b>long           </b></td> <td><a href='#compareTo'               >compareTo          </a></td> <td><b>const String&</b> aString  </td>                                                         </tr>
<tr><td><b>String*        </b></td> <td><a href='#substring'               >substring          </a></td> <td><b>long         </b> start    </td> <td><b>long</b> end   </td> <td><b>    </b>       </td> <td>IndexOutOfBoundsException*</td> </tr>

<tr><td><b>const byte*    </b></td> <td><a href='#getBytes'                >getBytes           </a></td>                                                                                                 </tr>
<tr><td><b>const char*    </b></td> <td><a href='#getChars'                >getChars           </a></td>                                                                                                 </tr>
<tr><td><b>long           </b></td> <td><a href='#getLength'               >getLength          </a></td>                                                                                                 </tr>
<tr><td><b>long           </b></td> <td><a href='#getSize'                 >getSize            </a></td>                                                                                                 </tr>

<tr><td><b>double         </b></td> <td><a href='#getValue'                >getValue           </a></td> <td><b>             </b>          </td> <td><b>    </b>       </td> <td><b>    </b>       </td> <td>IndexOutOfBoundsException*</td> </tr>
<tr><td><b>int            </b></td> <td><a href='#getValueAsInt'           >getValueAsInt      </a></td> <td><b>             </b>          </td> <td><b>    </b>       </td> <td><b>    </b>       </td> <td>IndexOutOfBoundsException*</td> </tr>
<tr><td><b>long           </b></td> <td><a href='#getValueAsLong'          >getValue           </a></td> <td><b>             </b>          </td> <td><b>    </b>       </td> <td><b>    </b>       </td> <td>IndexOutOfBoundsException*</td> </tr>
<tr><td><b>long long      </b></td> <td><a href='#getValueAsLongLong'      >getValueAsLongLong </a></td> <td><b>             </b>          </td> <td><b>    </b>       </td> <td><b>    </b>       </td> <td>IndexOutOfBoundsException*</td> </tr>

<tr><td><b>bool           </b></td> <td><a href='#contentEquals'           >contentEquals      </a></td> <td><b>const String&</b> aString  </td>                                                                                             </tr>
<tr><td><b>bool           </b></td> <td><a href='#contains'                >contains           </a></td> <td><b>const String&</b> aString  </td>                                                                                             </tr>
<tr><td><b>bool           </b></td> <td><a href='#startsWith'              >startsWith         </a></td> <td><b>const String&</b> aString  </td>                                                                                             </tr>
<tr><td><b>bool           </b></td> <td><a href='#endsWith'                >endsWith           </a></td> <td><b>const String&</b> aString  </td>                                                                                             </tr>
<tr><td><b>bool           </b></td> <td><a href='#matches'                 >matches            </a></td> <td><b>const String&</b> aString  </td>                                                                                             </tr>
<tr><td><b>bool           </b></td> <td><a href='#isNumber'                >isNumber           </a></td>                                                                                                                                     </tr>
</tbody>
</table>
~

!
~!source/cplusplus/String.cpp~
/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */
~

!
~source/cplusplus/String.cpp~
#include "openxds.base/String.h"
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
~
!

..		Constructors

~html~
<a name='String'></a>
<hr>
~

...			String

~
String();
~

Implementation

~source/cplusplus/String.cpp~
String::String() : Object()
{
	this->_data = new_StdString( "" );
	this->chars = this->getChars();
}
~

~html~
<a name='String(char*,long,long)'></a>
<hr>
~

...			String

~
String( const char* chars, long offset, long length );
~

Implementation

~source/cplusplus/String.cpp~
String::String( const char* chars, long offset, long length )
{
	this->_data = new_StdString_start_length( chars, offset, length );
	this->chars = this->getChars();
}
~

~html~
<a name='String'></a>
<hr>
~

...			String

~
String( const char* string );
~

Implementation

~source/cplusplus/String.cpp~
String::String( const char* string ) : Object()
{
	this->_data = new_StdString( string );
	this->chars = this->getChars();
}
~


~html~
<a name='String'></a>
<hr>
~

...			String

~
String( const String& aString );
~

Implementation

~source/cplusplus/String.cpp~
String::String( const String& aString ) : Object()
{
	this->_data = StdString_copy( (StdString*) aString._data ); 
	this->chars = this->getChars();
}
~

~html~
<a name='String'></a>
<hr>
~

...			String

~
String( int number );
~

Implementation

~source/cplusplus/String.cpp~
String::String( int number ) : Object()
{
	char *value = new char[ 128 ];
	sprintf( value, "%i", number);
	
	this->_data = new_StdString( value );
	
	delete value;
	this->chars = this->getChars();
}
~

..		Destructor

~
 ~String();
~

Implementation

~source/cplusplus/String.cpp~
String::~String()
{
	free_StdString( (StdString*) this->_data );
}
~

~source/cplusplus/String.cpp~
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

bool
String::endsWith( const String& suffix ) const
{
	return StdString_endsWith( (StdString*) this->_data, suffix.getChars() );
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
~





..		Methods

~html~
<a name='insert'></a>
<hr>
~

...			insert

~
IEntry<E>* insert( const char* key, E* element );
~

Parameters
|
/key/, to associate the /value/ with in the dictonary.

/element/, to be stored in the dictionary.
|

Returns
|
A new /entry/ that corresponds to the underlying position in the dictionary.
|



