package org.openxds.adt;

import org.openxds.exceptions.NoSuchElementException;

/**
 * Interface for a Deque - a double-ended queue.
 * 
 * A Deque (double-ended queue) may have elements inserted or removed from
 * both the front and the back of the queue.
 */
public interface IDeque<E>
{
	/**
	 * Add an element to the front of the queue.
	 * 
	 * @param anElement, is added to front of the queue.
	 */
	public void addFirst( E anElement );
	
	/**
	 * Add an element to the back of the queue.
	 * 
	 * @param anElement, is added to the back of the queue.
	 */
	public void addLast( E anElement );

	/**
	 * Remove the first element from the front of the queue.
	 * 
	 * @return the first element of the queue.
	 * @throws NoSuchElementException, if the queue is empty.
	 */
	public E removeFirst() throws NoSuchElementException;

	/**
	 * Remove the last element from the back of the queue.
	 * 
	 * @return the last element of the queue.
	 * @throws NoSuchElementException, if the queue is empty.
	 */
	public E removeLast() throws NoSuchElementException;
	
	/**
	 * Return a reference to the first element of the queue, but don't remove it.
	 * 
	 * @return the first element of the queue.
	 * @throws NoSuchElementException, if the queue is empty.
	 */
	public E getFirst() throws NoSuchElementException;

	/**
	 * Return a reference to the last element of the queue, but don't remove it.
	 * 
	 * @return the last element of the queue.
	 * @throws NoSuchElementException
	 */
	public E getLast() throws NoSuchElementException;

	/**
	 * @return the number of elements in the queue.
	 */
	public int size();
	
	/**
	 * @return true, if the queue is empty; false otherwise.
	 */
	public boolean isEmpty();
}
