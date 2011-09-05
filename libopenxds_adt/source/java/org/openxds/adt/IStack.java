package org.openxds.adt;

import org.openxds.exceptions.NoSuchElementException;

public interface IStack<E>
{
	/**
	 * Places the passed element on the top of the stack.
	 * 
	 * @param anElement, is placed onto top of stack.
	 */
	public void    push( E anElement );

	/**
	 * Returns the top element of the stack.
	 * 
	 * @return the removed element.
	 * @throws NoSuchElementException, if the stack is empty.
	 */
	public E pop() throws NoSuchElementException;
	
	/**
	 * Return a reference to the top element of the stack, but don't remove it.
	 * 
	 * @return the top element of the stack.
	 * @throws NoSuchElementException, if the stack is empty.
	 */
	public E top() throws NoSuchElementException;

	/**
	 * @return number of elements in the stack.
	 */
	public int     size();
	
	/**
	 * Indicates whether the stack contains any elements.
	 * 
	 * @return true, if the stack is empty; false otherwise.
	 */
	public boolean isEmpty();
}
