package org.openxds.adt.std;

import org.openxds.adt.IList;
import org.openxds.adt.IPosition;
import org.openxds.adt.IPIterator;

import java.util.NoSuchElementException;

/**
 * List implemented using an in-built doubly linked list.
 * All operations are O(1).
 */
public class List<E> implements IList<E>, IPIterator<E>
{
	private class Node implements IPosition<E>
	{
		Node( List<E> l, E e )
		{
			this.owner = l;
			this.element = e;
		}
		
		public E getElement()
		{
			return element;
		}
		
		List<E> owner;
		Node    prev;
		Node    next;
		E       element;
	}
	
	Node head = new Node( this, null );
	Node tail = new Node( this, null );
	int size;

	Node current = this.head;	// Used for iterator functionality.

	public List()
	{
		this.head.next = this.tail;
		this.tail.prev = this.head;
		this.size = 0;
	}
	
	/**
	 * O(1)
	 */
	public IPosition<E> insertFirst( E anElement )
	{
		return insertAfter( this.head, anElement );
	}
	
	/**
	 * O(1)
	 */
	public IPosition<E> insertLast( E anElement )
	{
		return insertBefore( this.tail, anElement );
	}

	/**
	 * O(1)
	 */
	public IPosition<E> insertBefore( IPosition<E> p, E anElement )
	{
		Node n = cast( p );
		Node u = n.prev;
		return insertAfter( u, anElement );
	}

	/**
	 * O(1)
	 */
	public IPosition<E> insertAfter( IPosition<E> p, E anElement )
	{
		Node u = cast( p );
		Node v = new Node( this, anElement );
		Node w = u.next;
		
		v.prev = u;
		v.next = w;
		
		u.next = v;
		w.prev = v;
		
		this.size++;

		return v;
	}

	/**
	 * O(1)
	 */
	public E replace( IPosition<E> p, E anElement )
	{
		Node node = cast( p );
		E ret = node.element;
		node.element = anElement;
		return ret;
	}
	
	/**
	 * O(1)
	 */
	public E remove( IPosition<E> p )
	{
		Node node = cast( p );
		
		node.prev.next = node.next;
		node.next.prev = node.prev;
		
		this.size--;
		
		return node.element;
	}

	/**
	 * O(1)
	 */
	public IPosition<E> first() throws NoSuchElementException
	{
		return this.next( this.head );
	}
	
	/**
	 * O(1)
	 */
	public IPosition<E> last() throws NoSuchElementException
	{
		return this.prev( this.tail );
	}
	
	/**
	 * O(1)
	 */
	public IPosition<E> prev( IPosition<E> p ) throws NoSuchElementException
	{
		Node n = cast( p );
		if ( n.prev == this.head ) throw new NoSuchElementException();
		
		return n.prev;
	}
	
	/**
	 * O(1)
	 */
	public IPosition<E> next( IPosition<E> p ) throws NoSuchElementException
	{
		Node n = cast( p );
		if ( n.next == this.tail ) throw new NoSuchElementException();
		
		return n.next;
	}
	
	/**
	 * Returns an iterator that is a polymorphic view of this class.
	 * i.e. a dynamic iterator.
	 * 
	 * O(1)
	 */
	public IPIterator<E> positions()
	{
		this.reset();
		return this;
	}
	
	/**
	 * O(1)
	 */
	public int size()
	{
		return size;
	}
	
	/**
	 * O(1)
	 */
	public boolean isEmpty()
	{
		return (this.head.next == this.tail);
	}
	
	/**
	 * O(1)
	 */
	public void reset()
	{
		this.current = this.head;
	}
	
	/**
	 * O(1)
	 */
	public boolean hasNext()
	{
		return ( this.tail != this.current.next );
	}
	
	/**
	 * O(1)
	 */
	public IPosition<E> next() throws NoSuchElementException
	{
		if ( this.tail == this.current.next ) throw new NoSuchElementException();
		this.current = this.current.next;
		return this.current;
	}

	private Node cast( IPosition<E> p )
	{
		Node n = (Node) p;
		if ( n.owner != this ) throw new IllegalArgumentException();
		return n;
	}
}
