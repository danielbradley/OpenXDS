package org.openxds.exceptions;

import org.openxds.IException;
import org.openxds.RuntimeException;

@SuppressWarnings("serial")
public class NoSuchElementException extends RuntimeException
{
	private static final String EXCEPTION_TYPE = "org.openxds.exceptions.NoSuchElementException";

	public NoSuchElementException()
	{}
	
	public NoSuchElementException( java.lang.String msg )
	{
		super( msg );
	}

	public NoSuchElementException( IException anException, java.lang.String msg )
	{
		super( anException, msg );
	}
	
	public java.lang.String getType()
	{
		return EXCEPTION_TYPE;
	}

	public IException copy()
	{
		return copyNoSuchElementException();
	}
	
	public NoSuchElementException copyNoSuchElementException()
	{
		if ( hasChainedException() )
		{
			return new NoSuchElementException( this.chainedException.copy(), this.getMessage() );
		}
		else
		{
			return new NoSuchElementException( this.getMessage() );
		}
	}
}