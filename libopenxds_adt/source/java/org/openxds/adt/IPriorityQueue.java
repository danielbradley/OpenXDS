package org.openxds.adt;

import org.openxds.exceptions.NoSuchElementException;

public interface IPriorityQueue<K, V>
{
	/**
	 * Inserts a new entry into the priority queue mapping aKey to aValue.
	 * 
	 * @param aKey
	 * @param aValue
	 * @return the new entry associated with the new mapping
	 */
	public IEntry<K,V> insert( K aKey, V aValue );

	/**
	 * Remove the entry with the highest priority.
	 * The highest priority depends upon the type of comparator passed to the constructor.
	 * 
	 * @return the entry with the highest priority
	 * @throws NoSuchElementException if the priority queue is empty.
	 */
	public IEntry<K,V> removeMin() throws NoSuchElementException;

	/**
	 * Returns the entry with the highest priority, but does not remove it.
	 * 
	 * @return the appropriate entry.
	 * @throws NoSuchElementException if the priority queue is empty.
	 */
	public IEntry<K,V> min() throws NoSuchElementException;

	/**
	 * Replace the current comparator with a different comparator.
	 * 
	 * @param c, the new comparator
	 */
	public void setComparitor( IComparitor<K> c );

	/**
	 * @return the number of entries in the priority queue.
	 */
	public int size();
	
	/**
	 * @return true, if the priority queue is empty; false otherwise.
	 */
	public boolean isEmpty();
}
