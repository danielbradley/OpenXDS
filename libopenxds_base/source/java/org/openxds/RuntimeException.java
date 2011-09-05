package org.openxds;


@SuppressWarnings("serial")
public class RuntimeException extends java.lang.RuntimeException
implements org.openxds.IException
{
	private static final String EXCEPTION_TYPE = "org.openxds.exceptions.RuntimeException";

	protected IException chainedException = null;
	
	public RuntimeException()
	{}
	
	public RuntimeException( java.lang.String msg )
	{
		super( msg );
	}
	
	public RuntimeException( IException anException, java.lang.String msg )
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
		return copyRuntimeException();
	}
	
	public RuntimeException copyRuntimeException()
	{
		if ( hasChainedException() )
		{
			return new RuntimeException( this.chainedException.copy(), this.getMessage() );
		}
		else
		{
			return new RuntimeException( this.getMessage() );
		}
	}
}