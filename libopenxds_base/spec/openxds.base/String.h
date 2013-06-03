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
			static const String _emptyString;
			static const String& emptyString();
			
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
			
			String* removeWhitespace() const;
			String*             trim() const;
			
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
			bool isOnlyWhitespace() const;
			
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

