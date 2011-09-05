package org.openxds.adt;

import org.openxds.exceptions.NoSuchElementException;

public interface IList<E>
{
	/**
	 * Inserts the element into a new position at the front of the list.
	 * 
	 * @param anElement, to be stored in the list.
	 * @return a reference to the newly created position storing the element.
	 */
	public IPosition<E> insertFirst( E anElement );

	/**
	 * Inserts the element into a new position at the end of the list.
	 * 
	 * @param anElement, to be stored in the list.
	 * @return a reference to the newly created position storing the element.
	 */
	public IPosition<E> insertLast( E anElement );

	/**
	 * Inserts the element into a new position before the position specified.
	 * 
	 * @param anElement, to be stored in the list.
	 * @return a reference to the newly created position storing the element.
	 */
	public IPosition<E> insertBefore( IPosition<E> p, E anElement );

	/**
	 * Inserts the element into a new position after the position specified.
	 * 
	 * @param anElement, to be stored in the list.
	 * @return a reference to the newly created position storing the element.
	 */
	public IPosition<E> insertAfter( IPosition<E> p, E anElement );

	/**
	 * Replaces the element stored at the specified position.
	 * 
	 * @param anElement, to be stored in the list.
	 * @return the existing element at the position specified.
	 */
	public E replace( IPosition<E> p, E anElement );

	/**
	 * Removes the specified position from the list.
	 * 
	 * @param p, the position to remove from the list.
	 * @return the element stored at the position specified.
	 */
	public E remove( IPosition<E> p );

	/**
	 * @return a reference to the first position in the list.
	 * @throws NoSuchElementException
	 */
	public IPosition<E> first() throws NoSuchElementException;

	/**
	 * @return a reference to the first position in the list.
	 * @throws NoSuchElementException
	 */
	public IPosition<E> last() throws NoSuchElementException;
	
	/**
	 * @return a reference to the position before the specified position.
	 * @throws NoSuchElementException
	 */
	public IPosition<E> prev( IPosition<E> p ) throws NoSuchElementException;

	/**
	 * @return a reference to the position after the specified position.
	 * @throws NoSuchElementException
	 */
	public IPosition<E> next( IPosition<E> p ) throws NoSuchElementException;
	
	/**
	 * @return a position iterator.
	 */
	public IPIterator<E> positions();
	
	/**
	 * @return the number of positions in this list.
	 */
	public int size();
	
	/**
	 * @return true if empty, otherwise false.
	 */
	public boolean isEmpty();
}
