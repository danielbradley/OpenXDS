package org.openxds.exceptions;

import org.openxds.IException;
import org.openxds.RuntimeException;

@SuppressWarnings("serial")
public class ImplementationException extends RuntimeException
implements org.openxds.IException
{
	private static final String EXCEPTION_TYPE = "ImplementationException";

	public ImplementationException()
	{}
	
	public ImplementationException( java.lang.String msg )
	{
		super( msg );
	}

	public ImplementationException( IException anException, java.lang.String msg )
	{
		super( anException, msg );
	}
	
	public java.lang.String getType()
	{
		return EXCEPTION_TYPE;
	}

	public IException copy()
	{
		return copyImplementationException();
	}
	
	public ImplementationException copyImplementationException()
	{
		if ( hasChainedException() )
		{
			return new ImplementationException( this.chainedException.copy(), this.getMessage() );
		}
		else
		{
			return new ImplementationException( this.getMessage() );
		}
	}
}