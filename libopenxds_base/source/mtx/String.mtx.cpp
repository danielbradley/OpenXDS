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
<tr><td><b>               </b></td> <td>new <a href='#String'                  >String         </a></td>                                                                                                 </tr>
<tr><td><b>               </b></td> <td>new <a href='#String(int)'             >String         </a></td> <td><b>int          </b> number   </td>                                                         </tr>
<tr><td><b>               </b></td> <td>new <a href='#String(char*,long,long)' >String         </a></td> <td><b>const char*  </b> chars    </td> <td><b>long</b> offset</td> <td><b>long</b> length</td> </tr>
<tr><td><b>               </b></td> <td>new <a href='#String(char*)'           >String         </a></td> <td><b>const char*  </b> chars    </td>                                                         </tr>
<tr><td><b>               </b></td> <td>new <a href='#String(String&)'         >String         </a></td> <td><b>const String&</b> aString  </td>                                                         </tr>

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
<!-- tr><td><b>bool           </b></td> <td><a href='#matches'                 >matches            </a></td> <td><b>const String&</b> aString  </td>                                                                                             </tr -->
<!-- tr><td><b>bool           </b></td> <td><a href='#isNumber'                >isNumber           </a></td>                                                                                                                                     </tr -->
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

Returns
|
a new instance of an empty string.
|

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

~
String( const char* chars, long offset, long length );
~

Parameters
|
/chars/, a string of characters;

/offset/, an offset into /chars/;

/length/, a length of chars from the specified offset.

|

Returns
|
a new instance of String whose contents represents at most /length/ number of characters from the specified /offset/.
|

Implementation

~source/cplusplus/String.cpp~
String::String( const char* chars, long offset, long length )
{
	this->_data = new_StdString_start_length( chars, offset, length );
	this->chars = this->getChars();
}
~

~html~
<a name='String(char*)'></a>
<hr>
~

~
String( const char* chars );
~

Parameters
|
/chars/, a string of characters.
|

Returns
|
a new instance of String whose contents is identicial to the passed /chars/.
|

Implementation

~source/cplusplus/String.cpp~
String::String( const char* string ) : Object()
{
	this->_data = new_StdString( string );
	this->chars = this->getChars();
}
~


~html~
<a name='String(String&)'></a>
<hr>
~

~
String( const String& string );
~

Parameters
|
/string/, that should be copied.
|

Returns
|
a new instance of String whose content is identical to the passed /string/.
|

Implementation

~source/cplusplus/String.cpp~
String::String( const String& aString ) : Object()
{
	this->_data = StdString_copy( (StdString*) aString._data ); 
	this->chars = this->getChars();
}
~

~html~
<a name='String(int)'></a>
<hr>
~

~
String( int number );
~

Parameters
|
/number/, to be represented in string form.
|

Returns
|
a new instance of String whose contents represents the /number/ passed in string form.
|

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

~html~
<a name='~String'></a>
<hr>
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

..		Methods

~html~
<a name='clone'></a>
<hr>
~

...			clone

~
Object* clone() const;
~

Returns
|
A new instance of String typed as an Object that is a clone (copy) of this String.
|

Implementation

~source/cplusplus/String.cpp~
Object* String::clone() const
{
	return new String( *this );
}
~




~html~
<a name='asString'></a>
<hr>
~

...			asString

~
String* asString() const;
~

Returns
|
A new instance of String that is a copy of /this/ String.
|

Implementation

~source/cplusplus/String.cpp~
String* String::asString() const
{
	String* str = new String( *this );
	return str;
}
~




~html~
<a name='equals'></a>
<hr>
~

...			equals

~
bool equals( const Object& object ) const;
~

Returns
|
TRUE, if the content of /this/ object is identical to the content of the passed /object/; otherwise FALSE.
|

Implementation

~source/cplusplus/String.cpp~
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
~

!
This method is deprecated.
~source/cplusplus/String.cpp~
/*
 *	Deprecated
 */
bool String::equals( const Object* obj ) const
{
	return this->equals( *obj );
}
~
!




!
~source/cplusplus/String.cpp~
//----------------------------------------------------------------------------- 
// Public Methods Implemented For Objects
//-----------------------------------------------------------------------------
~
!




~html~
<a name='equals'></a>
<hr>
~

...			chatAt

~
char charAt( long index ) const throw (IndexOutOfBoundsException*);
~

Returns
|
The character that is located at the specified /index/ of the string.
|

Throws
|
/IndexOutOfBoundsException/, if the /index/ is beyond the end of the string.
|

Implementation

~source/cplusplus/String.cpp~
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
~




~html~
<a name='compareTo'></a>
<hr>
~

...			compareTo

~
int compareTo( const String& string ) const;
~

Parameters
|
/string/, to compare to /this/ string.
|

Returns
|
0 if strings are identical; a negative number if the first non-identical character of /this/ is less than the corresponding character; otherwise a positive number.
|

Implementation

~source/cplusplus/String.cpp~
int
String::compareTo( const String& anotherString ) const
{
	return StdString_compare( (StdString*) this->_data, StdString_getChars( (StdString*) anotherString._data ) );
}
~

!
Deprecated
~source/cplusplus/String.cpp~
int String::compareTo( const String* anotherString ) const
{
	return compareTo( *anotherString );
}
~
!




~html~
<a name='substring'></a>
<hr>
~

...			substring

~
String* substring( long start, long end ) const;
~

Parameters
|
/start/, the index of the first character of the substring;

/end/, the index of the last character of the substring.
|

Returns
|
a new instance of String whose contents is the characters at the indices from /start/ through to /end/; an empty string if /end/ < /start/. 
|

Throws
|
/IndexOutOfBoundsException/, if /end/ is beyond the bounds of the string.
|

Note
|
This differs from the Java implementation of substring, which returns the characters at the indices from /start/ through to (/end/ - 1).
|

Implementation

~source/cplusplus/String.cpp~
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
~




~html~
<a name='getBytes'></a>
<hr>
~

...			getBytes

~
const byte*const getBytes() const;
~

Returns
|
the underlying C charstring representation typecast to bytes.
|

Implementation

~source/cplusplus/String.cpp~
const byte*const String::getBytes() const
{
	return (const byte*const) StdString_getChars( (StdString*) this->_data );
}
~




~html~
<a name='getChars'></a>
<hr>
~

...			getChars

~
const char* getChars() const;
~

Returns
|
the underlying C charstring representation.
|

Implementation

~source/cplusplus/String.cpp~
const char* String::getChars() const
{
	return StdString_getChars( (StdString*) this->_data );
}
~




~html~
<a name='getLength'></a>
<hr>
~

...			getLength

~
long getLength() const;
~

Returns
|
the number of characters stored in the string.
|

Implementation

~source/cplusplus/String.cpp~
long String::getLength() const
{
	return StdString_getLength( (StdString*) this->_data );
}
~




~html~
<a name='contentEquals'></a>
<hr>
~

...			contentEquals

~
bool contentEquals( const String& string ) const;
~

Parameters
|
/string/, to compare to /this/ string.
|

Returns
|
TRUE, if the content of /this/ string is identical to the content of the other /string/; otherwise FALSE.
|

Implementation

~source/cplusplus/String.cpp~
bool
String::contentEquals( const String& str ) const
{
	return (0 == this->compareTo( str ));
}
~




~html~
<a name='contains'></a>
<hr>
~

...			contains

~
bool contains( const String& token ) const;
~

Parameters
|
/token/, that may existing within /this/ string.
|

Returns
|
TRUE, if /this/ string contains the passed /token/ as a substring; otherwise FALSE.
|

Implementation

~source/cplusplus/String.cpp~
bool
String::contains( const String& token ) const
{
	return StdString_contains( (StdString*) this->_data, token.getChars() );
}
~




~html~
<a name='startsWith'></a>
<hr>
~

...			startsWith

~
bool startsWith( const String& prefix ) const;
~

Parameters
|
/prefix/, to compare against the start of /this/ string.
|

Returns
|
TRUE, if /this/ string begins with the passed /prefix/.
|

Implementation

~source/cplusplus/String.cpp~
bool
String::startsWith( const String& prefix ) const
{
	return StdString_startsWith( (StdString*) this->_data, prefix.getChars() );
}
~




~html~
<a name='endsWith'></a>
<hr>
~

...			endsWith

~
bool endsWith( const String& suffix ) const;
~

Parameters
|
/suffix/, to compare against the end of /this/ string.
|

Returns
|
TRUE, if /this/ string ends with the passed /suffix/.
|

Implementation

~source/cplusplus/String.cpp~
bool
String::endsWith( const String& suffix ) const
{
	return StdString_endsWith( (StdString*) this->_data, suffix.getChars() );
}
~


!
~source/cplusplus/String.cpp~
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
!
