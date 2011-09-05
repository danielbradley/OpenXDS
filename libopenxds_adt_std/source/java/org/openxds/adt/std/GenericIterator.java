package org.openxds.adt.std;

import org.openxds.adt.*;
import org.openxds.exceptions.NoSuchElementException;

/**
 * Generic iterator implemented using a list.
 * All operations are O(1).
 */
public class GenericIterator<E> implements IIterator<E> {

	private List<E> items = new List<E>();
	private IPIterator<E> it = null;

	/**
	 * O(1)
	 */
	public boolean hasNext()
	{
		if ( null == it ) it = this.items.positions();
		return it.hasNext();
	}

	/**
	 * O(1)
	 */
	public E next() throws NoSuchElementException
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
	public void addElement( E anElement )
	{
		this.items.insertLast( anElement );
	}
}
