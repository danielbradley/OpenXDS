package org.openxds;


@SuppressWarnings("serial")
public class Exception extends java.lang.Exception
implements org.openxds.IException
{
	private static final String EXCEPTION_TYPE = "org.openxds.exceptions.Exception";

	protected IException chainedException = null;
	
	public Exception()
	{}
	
	public Exception( java.lang.String msg )
	{
		super( msg );
	}
	
	public Exception( IException anException, java.lang.String msg )
	{
		super( msg );
		this.chainedException = anException;
	}

	public java.lang.String getMessage()
	{
		return super.getMessage();
	}
	
	public IException retrieveChainedException()
	{
		return this.chainedException;
	}
	
	public boolean hasChainedException()
	{
		return (null != this.chainedException);
	}
	
	public java.lang.String getType()
	{
		return EXCEPTION_TYPE;
	}
	
	public IException copy()
	{
		return copyException();
	}
	
	public Exception copyException()
	{
		if ( hasChainedException() )
		{
			return new Exception( this.chainedException.copy(), this.getMessage() );
		}
		else
		{
			return new Exception( this.getMessage() );
		}
	}
}