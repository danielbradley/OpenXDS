package org.openxds.adt.std;

import org.openxds.exceptions.ImplementationException;
import org.openxds.exceptions.IndexOutOfBoundsException;
import org.openxds.exceptions.NoSuchElementException;

import org.openxds.adt.IDeque;
import org.openxds.adt.IVector;
import org.openxds.adt.std.CircularVector;

/**
 * Deque implemented using a circular vector.
 * All operations are O(1).
 */
public class CircularDeque<E> implements IDeque<E>
{
	private IVector<E> elements = new CircularVector<E>();
	
	/**
	 * O(1)
	 */
	public void addFirst( E anElement )
	{
		try
		{
			this.elements.add( 0, anElement);
		}
		catch ( IndexOutOfBoundsException ex )
		{
			throw new ImplementationException( ex, "Unexpected IndexOutOfBoundsException caught" );
		}
	}
	
	/**
	 * O(1)
	 */
	public void addLast( E anElement )
	{
		try
		{
			this.elements.add( this.elements.size(), anElement );
		}
		catch ( IndexOutOfBoundsException ex )
		{
			throw new ImplementationException( ex, "Unexpected IndexOutOfBoundsException caught" );
		}
	}

	/**
	 * O(1)
	 */
	public E removeFirst() throws NoSuchElementException
	{
		return this.elements.removeFrom( 0 );
	}

	/**
	 * O(1)
	 */
	public E removeLast() throws NoSuchElementException
	{
		return this.elements.removeFrom( this.elements.size() - 1 );
	}
	
	/**
	 * O(1)
	 */
	public E getFirst() throws NoSuchElementException
	{
		return this.elements.get( 0 );
	}
	
	/**
	 * O(1)
	 */
	public E getLast() throws NoSuchElementException
	{
		return this.elements.get( this.elements.size() - 1 );
	}
	
	/**
	 * O(1)
	 */
	public int size()
	{
		return this.elements.size();
	}
	
	/**
	 * O(1)
	 */
	public boolean isEmpty()
	{
		return this.elements.isEmpty();
	}
}
