package org.openxds.adt.std;

import org.openxds.base.*;
import org.openxds.exceptions.IndexOutOfBoundsException;
import org.openxds.exceptions.NoSuchElementException;
import org.openxds.adt.*;

/**
 * Sequence implemented using a List.
 * 
 * Space-complexity O(n).
 */
public class ListSequence<E> implements ISequence<E>
{
	IList<E> list = new List<E>();

	/**
	 * Time-complexity O(n), as entire list may be searched.
	 */
	public IPosition<E> atRank(int rank) throws IndexOutOfBoundsException
	{
		try
		{
			IPosition<E> p = this.list.first();
			for ( int i=0; i < rank; i++ )
			{
				p = this.list.next( p );
			}
			return p;
		} catch ( NoSuchElementException ex ) {
			throw new IndexOutOfBoundsException( rank );
		}
	}

	/**
	 * Time-complexity O(n), as entire list may be traversed.
	 */
	public int rankOf(IPosition<E> p)
	{
		int r=0;
		try
		{
			while ( true )
			{
				p = this.list.prev( p );
				r++;
			}
		} catch ( NoSuchElementException ex ) {
			;
		}
		return r;
	}

	/**
	 * Time-complexity O(n), as entire list may be traversed.
	 */
	public void add(int rank, E anElement) throws IndexOutOfBoundsException
	{
		switch ( rank )
		{
		case 0:
			this.list.insertFirst( anElement );
			break;
		default:
			IPosition<E> p = this.atRank( rank - 1 );
			this.list.insertAfter( p, anElement);
		}
	}

	/**
	 * Time-complexity O(n), as entire list may be traversed in atRank().
	 */
	public E get(int rank) throws IndexOutOfBoundsException
	{
		return this.atRank( rank ).getElement();	// atRank O(n).
	}

	/**
	 * Time-complexity O(1).
	 */
	public boolean isEmpty()
	{
		return this.list.isEmpty();
	}

	/**
	 * Time-complexity O(n), as entire list may be traversed in atRank().
	 */
	public E removeFrom(int rank) throws IndexOutOfBoundsException
	{
		IPosition<E> p = this.atRank( rank );	// atRank O(n).
		return this.list.remove( p );
	}

	/**
	 * Time-complexity O(n), as entire list may be traversed in atRank().
	 */
	public E set(int rank, E anElement) throws IndexOutOfBoundsException
	{
		IPosition<E> p = this.atRank( rank );	// atRank O(n).
		return this.list.replace( p, anElement );
	}

	/**
	 * Time-complexity O(1).
	 */
	public int size()
	{
		return this.list.size();
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> first() throws NoSuchElementException
	{
		return this.list.first();
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> last() throws NoSuchElementException
	{
		return this.list.last();
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> next(IPosition<E> p) throws NoSuchElementException
	{
		return this.list.next( p );
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> prev(IPosition<E> p) throws NoSuchElementException
	{
		return this.list.prev( p );
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> insertAfter(IPosition<E> p, E anElement)
	{
		return this.list.insertAfter( p, anElement);
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> insertBefore(IPosition<E> p, E anElement)
	{
		return this.list.insertBefore( p, anElement );
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> insertFirst(E anElement)
	{
		return this.list.insertFirst( anElement );
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> insertLast(E anElement)
	{
		return this.list.insertLast( anElement );
	}

	/**
	 * Time-complexity O(1).
	 */
	public E remove(IPosition<E> p)
	{
		return this.list.remove( p );
	}

	/**
	 * Time-complexity O(1).
	 */
	public E replace(IPosition<E> p, E anElement)
	{
		return this.list.replace( p, anElement );
	}

	/**
	 * Time-complexity O(1).
	 */
	public void addFirst(E anElement)
	{
		this.insertFirst( anElement );
	}

	/**
	 * Time-complexity O(1).
	 */
	public void addLast(E anElement)
	{
		this.insertLast( anElement );
	}

	/**
	 * Time-complexity O(1).
	 */
	public E getFirst() throws NoSuchElementException
	{
		return this.first().getElement();
	}

	/**
	 * Time-complexity O(1).
	 */
	public E getLast() throws NoSuchElementException
	{
		return this.last().getElement();
	}

	/**
	 * Time-complexity O(1).
	 */
	public E removeFirst() throws NoSuchElementException
	{
		return this.remove( this.first() );
	}

	/**
	 * Time-complexity O(1).
	 */
	public E removeLast() throws NoSuchElementException
	{
		return this.remove( this.last() );
	}
	
	/**
	 * Time-complexity O(1), as list.positions is O(1).
	 */
	public IPIterator<E> positions()
	{
		return this.list.positions();
	}
}
