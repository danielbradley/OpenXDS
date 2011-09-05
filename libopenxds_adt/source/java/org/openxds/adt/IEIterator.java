package org.openxds.adt;

import org.openxds.exceptions.NoSuchElementException;

public interface IEIterator<K, V>
{
	/**
	 * Reset the iterator so that a call to next will return the first entry.
	 */
	public void reset();

	/**
	 * @return the next entry if it exists, otherwise throw a NoSuchElementException.
	 * @throws NoSuchElementExeception, if no entry can be returned.
	 */
	public IEntry<K,V> next() throws NoSuchElementException;

	/**
	 * @return true if another entry can be returned, false otherwise.
	 */
	public boolean hasNext();

}
