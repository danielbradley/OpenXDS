package org.openxds.adt.std;

import org.openxds.adt.IStack;
import org.openxds.exceptions.NoSuchElementException;

/**
 * Stack implementation using an in-built singly linked list.
 * All operations are O(1).
 */
public class LinkedListStack<E> implements IStack<E>
{
	private class Node<F>
	{
		F       element;
		Node<F> next;
	}

	Node<E> head;
	int     size;
	
	public LinkedListStack()
	{}

	/**
	 * O(1)
	 */
	public void push( E anElement )
	{
		Node<E> node = new Node<E>();
		node.element = anElement;
		node.next    = this.head;
		this.head    = node;
		this.size++;
	}
	
	/**
	 * O(1)
	 */
	public E pop() throws NoSuchElementException
	{
		if ( 0 == size ) throw new NoSuchElementException();
		
		E tmp = this.head.element;
		this.head = this.head.next;
		this.size--;
		
		return tmp;
	}
	
	/**
	 * O(1)
	 */
	public E top() throws NoSuchElementException
	{
		if ( 0 == size ) throw new NoSuchElementException();

		return this.head.element;
	}

	/**
	 * O(1)
	 */
	public int size()
	{
		return this.size;
	}

	/**
	 * O(1)
	 */
	public boolean isEmpty()
	{
		return (0 == this.size);
	}
}
