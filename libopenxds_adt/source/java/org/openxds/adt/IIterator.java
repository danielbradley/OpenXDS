package org.openxds.adt;

import org.openxds.exceptions.NoSuchElementException;

public interface IIterator<E>
{
	/**
	 * Reset the iterator so that a call to next will return the first element.
	 */
	public boolean hasNext();

	/**
	 * @return the next element if it exists, otherwise throw a NoSuchElementException.
	 * @throws NoSuchElementExeception, if no element can be returned.
	 */
	public E next() throws NoSuchElementException;

	/**
	 * @return true if another element can be returned, false otherwise.
	 */
	public void reset();
}
