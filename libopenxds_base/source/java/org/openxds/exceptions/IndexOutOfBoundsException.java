package org.openxds.exceptions;

import org.openxds.IException;

@SuppressWarnings("serial")
public class IndexOutOfBoundsException extends NoSuchElementException
implements org.openxds.IException
{
	private static final String EXCEPTION_TYPE = "IndexOutOfBoundsException";
	private int index = -1;
	
	public IndexOutOfBoundsException( int index )
	{
		this.index = index;
	}

	public IndexOutOfBoundsException( java.lang.String msg )
	{
		super( msg );
	}

	public IndexOutOfBoundsException( int index, java.lang.String msg )
	{
		super( msg );
		this.index = index;
	}

	public IndexOutOfBoundsException( IException anException, java.lang.String msg )
	{
		super( anException, msg );
	}
	
	public IndexOutOfBoundsException( int index, IException anException, java.lang.String msg )
	{
		super( anException, msg );
		this.index = index;
	}

	public java.lang.String getType()
	{
		return EXCEPTION_TYPE;
	}

	public IException copy()
	{
		return copyIndexOutOfBoundsException();
	}
	
	public IndexOutOfBoundsException copyIndexOutOfBoundsException()
	{
		if ( hasChainedException() )
		{
			return new IndexOutOfBoundsException( -1, this.chainedException.copy(), this.getMessage() );
		}
		else
		{
			return new IndexOutOfBoundsException( -1, this.getMessage() );
		}
	}
	
	public int getIndex()
	{
		return this.index;
	}
}