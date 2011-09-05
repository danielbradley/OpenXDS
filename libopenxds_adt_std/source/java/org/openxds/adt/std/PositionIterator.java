package org.openxds.adt.std;

import org.openxds.adt.IList;
import org.openxds.adt.IPosition;
import org.openxds.adt.IPIterator;

import org.openxds.exceptions.NoSuchElementException;

/**
 * Position iterator implemented using a List ADT.
 */
public class PositionIterator<E> implements IPIterator<E> {

	private IList<IPosition<E>> positions = new List<IPosition<E>>();
	private IPIterator<IPosition<E>> it = null;
	
	public PositionIterator()
	{}
	
	/**
	 * O(1)
	 */
	public boolean hasNext()
	{
		if ( null == this.it ) this.it = positions.positions();	// positions is O(1).
		
		return this.it.hasNext();
	}

	/**
	 * O(1)
	 */
	public IPosition<E> next() throws NoSuchElementException
	{
		if ( ! this.hasNext() ) throw new NoSuchElementException();
		
		return this.it.next().getElement();
	}
	
	/**
	 * O(1)
	 */
	public void reset()
	{
		this.it.reset();
	}
	
	/**
	 * O(1)
	 */
	protected void addPosition( IPosition<E> p )
	{
		this.positions.insertLast( p );
	}
}
