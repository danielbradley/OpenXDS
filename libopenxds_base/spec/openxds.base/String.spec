namespace openxds.base;

spec String extends Object implements Clonable
{
	public #emptyString : String;
	
	public new ();
	public new (  number : int );
	public new ( aString : const string& );
	
	//---------------------------------------------------------------------------
	// Virtual Methods from Object
	//---------------------------------------------------------------------------
			
	public const    clone() : Object*;
	public const asString() : String*;

	public const is(     obj : const Object& );
	public const is( aString : const string& );
	
	public const equals(     obj : const Object& );
	public const equals( aString : const string& );
		
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
	public const    charAt( index : long ) : char;

	public const compareTo( anotherString : const string& ) : int;
	
	public const substring( start : long, end : long ) : string*;

	public const removeWhitespace() : string*;
	public const             trim() : string*;

	public const         getBytes() : const byte[];
	public const         getChars() : const char[];

	public const        getLength() : long;
	public const          getSize() : long;

	public const   getValueAsDouble() : double;
	public const      getValueAsInt() : int;
	public const     getValueAsLong() : long;

	public const contentEquals(     str : const string& ) : bool;
	public const      contains(   token : const string& ) : bool;
	public const    startsWith(  prefix : const string& ) : bool;
	public const      endsWith(  prefix : const string& ) : bool;
	public const       matches( pattern : const string& ) : bool;

	public const         isNumber() : bool;
	public const isOnlyWhitespace() : bool;

			const char* chars;
			void*       _data;
			
		private:
			static const bool debug;
		};
		
	};};

#endif

