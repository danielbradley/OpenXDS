package org.openxds.exceptions;

import org.openxds.IException;
import org.openxds.RuntimeException;

@SuppressWarnings("serial")
public class SemanticException extends RuntimeException
implements org.openxds.IException
{
	private static final String EXCEPTION_TYPE = "SemanticException";

	public SemanticException()
	{}
	
	public SemanticException( java.lang.String msg )
	{
		super( msg );
	}

	public SemanticException( IException anException, java.lang.String msg )
	{
		super( anException, msg );
	}
	
	public java.lang.String getType()
	{
		return EXCEPTION_TYPE;
	}

	public IException copy()
	{
		return copySemanticException();
	}
	
	public SemanticException copySemanticException()
	{
		if ( hasChainedException() )
		{
			return new SemanticException( this.chainedException.copy(), this.getMessage() );
		}
		else
		{
			return new SemanticException( this.getMessage() );
		}
	}
}