package org.openxds.base;

import org.openxds.ICloneable;
import org.openxds.Object;
import org.openxds.exceptions.IndexOutOfBoundsException;

public class String extends Object implements ICloneable
{
	private java.lang.String _data = null;
	
	public String()
	{
		this._data = new java.lang.String();
	}
	
	public String( char[] c )
	{
		this._data = new java.lang.String( c );
	}
	
	public String( int offset, int length, char[] c )
	{
		java.lang.String s = new java.lang.String( c );
		this._data = s.substring( offset, offset + length );
	}
	
	public String( String aString )
	{
		this._data = new java.lang.String( aString._data );
	}

	public String( java.lang.String aJavaString )
	{
		this._data = new java.lang.String( aJavaString );
	}

	public String( int anInteger )
	{
		java.lang.Integer anInt = new java.lang.Integer( anInteger );
		this._data = anInt.toString();
	}

	public Object clone()
	{
		return new String( this );
	}
	
	public String asString()
	{
		return new String( this );
	}

	public java.lang.String asJavaString()
	{
		return this._data;
	}
	
	public boolean equals( String aString )
	{
		return (0 == this.compareTo( aString ) );
	}
	
	public char charAt( int index ) throws IndexOutOfBoundsException
	{
		return this._data.charAt( index );
	}
	
	public int compareTo( String aString )
	{
		return this._data.compareTo( aString._data );
	}
	
	public String substring( int start, int end ) throws IndexOutOfBoundsException
	{
		java.lang.String _str = this._data.substring( start, end + 1 );
		return new String( _str );
	}
	
	public byte[] getBytes()
	{
		return this._data.getBytes();
	}
}
