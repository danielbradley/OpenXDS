package org.openxds.adt;

import org.openxds.exceptions.IndexOutOfBoundsException;

/**
 * Interface for a Vector (also known as ArrayList).
 * 
 * A vector is a linear data structure that stores elements in consecutive positions,
 * each indicated by a rank.
 * 
 * When an an element is added to a vector at a particular rank, the rank of the existing element
 * and all following elements is incremented by 1.
 * Similarly, when an element is removed from a vector the rank of all following elements is decremented by 1.
 */
public interface IVector<E>
{
	/**
	 * Inserts an element to be at the specified rank, shifting all elements after this.
	 * 
	 * @param rank, the position the element is inserted into the list.
	 * @param anElement, the element to insert into the list.
	 * @throws IndexOutOfBoundsException, if the rank is greater than the size of the list.
	 */
	public void add( int rank, E anElement ) throws IndexOutOfBoundsException;

	/**
	 * Replaces the element at the specified rank, returning the original element.
	 * 
	 * @param rank, the position in the list that the element is swapped with.
	 * @param anElement, the element swapped into the list.
	 * @return the original element in the list.
	 * @throws IndexOutOfBoundsException, if the rank does not exist in the list.
	 */
	public E set( int rank, E anElement ) throws IndexOutOfBoundsException;

	/**
	 * Removes and returns the element at the specified rank, shifting the elements after this.
	 * 
	 * @param rank, the position in the list that is removed.
	 * @return the element stored at that rank.
	 * @throws IndexOutOfBoundsException, if the rank does not exist in the list.
	 */
	public E removeFrom( int rank ) throws IndexOutOfBoundsException;

	/**
	 * Returns the element at the specified rank, without removing it.
	 * 
	 * @param rank, the position in the list that will be returned.
	 * @return the element at the specified rank.
	 * @throws IndexOutOfBoundsException, if the rank does not existing in the list.
	 */
	public E get( int rank ) throws IndexOutOfBoundsException;
	
	/**
	 * Returns the number of elements in the list.
	 * 
	 * @return the size of the list.
	 */
	public int size();
	
	/**
	 * Returns whether the list is empty or not
	 * 
	 * @return true, if empty; false otherwise.
	 */
	public boolean isEmpty();
}
