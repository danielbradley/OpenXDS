package org.openxds;

public interface IException extends Interface
{
	public java.lang.String getMessage();
	public IException retrieveChainedException();
	boolean hasChainedException();

	public IException copy();
	public java.lang.String getType();
}