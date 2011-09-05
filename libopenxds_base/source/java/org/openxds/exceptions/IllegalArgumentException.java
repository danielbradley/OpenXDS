package org.openxds.exceptions;

import org.openxds.IException;

@SuppressWarnings("serial")
public class IllegalArgumentException extends SemanticException
implements org.openxds.IException
{
	private static final String EXCEPTION_TYPE = "org.openxds.exceptions.IllegalArgumentException";

	public IllegalArgumentException()
	{}
	
	public IllegalArgumentException( java.lang.String msg )
	{
		super( msg );
	}

	public IllegalArgumentException( IException anException, java.lang.String msg )
	{
		super( anException, msg );
	}
	
	public java.lang.String getType()
	{
		return EXCEPTION_TYPE;
	}

	public IException copy()
	{
		return copyIllegalArgumentException();
	}
	
	public IllegalArgumentException copyIllegalArgumentException()
	{
		if ( hasChainedException() )
		{
			return new IllegalArgumentException( this.chainedException.copy(), this.getMessage() );
		}
		else
		{
			return new IllegalArgumentException( this.getMessage() );
		}
	}
}