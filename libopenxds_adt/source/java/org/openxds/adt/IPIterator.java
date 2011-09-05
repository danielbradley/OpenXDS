package org.openxds.adt;

import org.openxds.exceptions.NoSuchElementException;

public interface IPIterator<E>
{
	/**
	 * Reset the iterator so that a call to next will return the first position.
	 */
	public boolean hasNext();

	/**
	 * @return the next position if it exists, otherwise throw a NoSuchElementException.
	 * @throws NoSuchElementExeception, if no position can be returned.
	 */
	public IPosition<E> next() throws NoSuchElementException;

	/**
	 * @return true if another position can be returned, false otherwise.
	 */
	public void reset();
}
