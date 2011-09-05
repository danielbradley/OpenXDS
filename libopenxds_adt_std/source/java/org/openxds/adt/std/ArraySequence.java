package org.openxds.adt.std;

import org.openxds.exceptions.ImplementationException;
import org.openxds.exceptions.IndexOutOfBoundsException;
import org.openxds.exceptions.NoSuchElementException;

import org.openxds.adt.IPIterator;
import org.openxds.adt.IPosition;
import org.openxds.adt.ISequence;

/**
 * Sequence implemented using a circular array.
 */
public class ArraySequence<E> implements ISequence<E>
{
	class Node<F> implements IPosition<F>
	{
		public Node( Object o, Object e ) {
			this.owner   = o;
			this.element = e;
		}
		
		public void setElement( E anElement )
		{
			this.element = anElement;
		}
		
		@SuppressWarnings("unchecked")
		public F getElement() {
			return (F) this.element;
		}
		
		Object  owner;
		Object  element;
		int     index;
	}

	int       N = 1;
	int       f = 0;
	int       b = 0;

	Node<E>[]    elements = createNodeArray( N );
	
	public ArraySequence()
	{}

	/**
	 * Time-complexity O(1).
	 */
	public E set( int rank, E anElement ) throws IndexOutOfBoundsException
	{
		checkRank( rank, 0 );
		
		int     i = (f + rank) % N;
		Node<E> n = this.elements[i];
		
		E ret = n.getElement();
		n.setElement( anElement );
		
		return ret;
	}

	/**
	 * Time-complexity O(n).
	 */
	public void add( int rank, E anElement ) throws IndexOutOfBoundsException
	{
		checkRank( rank, 1 );

		if ( this.isFull() ) this.resize();
		
		if ( 0 == rank )
		{
			this.insertFirst( anElement );
		}
		else
		{
			int n = size();
		
			for ( int r=rank; r < n; r++ )
			{
				anElement = this.set( r, anElement );
			}
		
			this.elements[b] = new Node<E>( this, anElement );
			this.elements[b].index = b;
			b = (b + 1) % N;
		}
	}
	
	/**
	 * Time-complexity O(1) if rank = 0; O(n) otherwise
	 */
	public E removeFrom( int rank ) throws IndexOutOfBoundsException
	{
		checkRank( rank, 0 );
		
		E ret = null;

		if ( 0 == rank )
		{
			try
			{
				ret = this.removeFirst();
			} catch ( NoSuchElementException ex )
			{
				throw new IndexOutOfBoundsException( 0 );
			}
		}
		else
		{
			int n = size();

			ret = this.get( rank );
		
			for ( int r=rank + 1; r < n; r++ )
			{
				this.set( r-1, this.get( r ) );
			}

			this.elements[b] = null;
			b = (N + b - 1) % N;
		}
		
		return ret;
	}

	/**
	 * Time-complexity O(1).
	 */
	public E get( int rank ) throws IndexOutOfBoundsException
	{
		checkRank( rank, 0 );

		int i = (f + rank) % N;
		return this.elements[i].getElement();
	}

	/**
	 * O(1)
	 */
	public int size()
	{
		return (elements.length - f + b) % N;
	}
	
	/**
	 * O(1)
	 */
	public boolean isEmpty()
	{
		return (f == b);
	}
	
	/**
	 * O(1)
	 */
	public boolean isFull()
	{
		return (size() == (elements.length - 1));
	}

	//	List methods
	
	/**
	 * O(1)
	 */
	public IPosition<E> insertFirst( E anElement )
	{
		if ( isFull() ) resize();	// O(1) amortised.
		
		this.f = (N + f - 1) % N;
		this.elements[f] = new Node<E>( this, anElement );
		this.elements[f].index = f;
		
		return this.elements[f];
	}
	
	/**
	 * O(1)
	 */
	public IPosition<E> insertLast( E anElement )
	{
		// full sequence handled by add.
		int r = size();
		return carefulAdd( r, anElement );	// O(1), when adding to back.
	}

	/**
	 * O(n)
	 */
	public IPosition<E> insertBefore( IPosition<E> p, E anElement )
	{
		// full sequence handled by add.
		
		int r = rankOf( p );
		return carefulAdd( r, anElement );
	}

	/**
	 * O(n)
	 */
	public IPosition<E> insertAfter( IPosition<E> p, E anElement )
	{
		// full sequence handled by add.
		
		int r = rankOf( p );
		return carefulAdd( r + 1, anElement );
	}

	/**
	 * O(1)
	 */
	public E replace( IPosition<E> p, E anElement )
	{
		try
		{
			return set( rankOf( p ), anElement );
		}
		catch ( IndexOutOfBoundsException ex )
		{
			throw new ImplementationException( ex, "Unexpected IndexOutOfBoundsException caught" );
		}
	}

	/**
	 * O(n)
	 */
	public E remove( IPosition<E> p )
	{
		try
		{
			return removeFrom( rankOf( p ) );
		}
		catch ( IndexOutOfBoundsException ex )
		{
			throw new ImplementationException( ex, "Unexpected IndexOutOfBoundsException caught" );
		}
	}

	/**
	 * O(1)
	 */
	public IPosition<E> first() throws NoSuchElementException
	{
		return atRank(0);
	}

	/**
	 * O(1)
	 */
	public IPosition<E> last() throws NoSuchElementException
	{
		return atRank(size()-1);
	}

	/**
	 * O(1)
	 */
	public E getFirst() throws NoSuchElementException
	{
		return atRank(0).getElement();
	}

	/**
	 * O(1)
	 */
	public E getLast() throws NoSuchElementException
	{
		return atRank(size()-1).getElement();
	}

	/**
	 * O(1)
	 */
	public IPosition<E> prev( IPosition<E> p ) throws NoSuchElementException
	{
		int r = rankOf( p );
		
		if ( 0 == r ) throw new NoSuchElementException();
		
		return atRank( r - 1 );
	}

	/**
	 * O(1)
	 */
	public IPosition<E> next( IPosition<E> p ) throws NoSuchElementException
	{
		int r = rankOf( p ) + 1;

		if ( size() == r ) throw new NoSuchElementException();
		
		return atRank( r );
	}

	//	Implement bridge methods
	
	/**
	 * O(1)
	 */
	public IPosition<E> atRank( int rank ) throws IndexOutOfBoundsException
	{
		checkRank( rank, 0 );
		
		int i = (f + rank) % N;

		return this.elements[i];
	}

	/**
	 * O(1)
	 */
	public int rankOf( IPosition<E> p )
	{
		Node<E> node = cast( p );
		int i  = node.index;
		int r = (N + i - f) % N;
		return r;
	}
	
	/**
	 * O(1)
	 */
	private void checkRank( int rank, int margin ) throws IndexOutOfBoundsException
	{
		int size = size() + margin;
		if ( rank >= size ) throw new IndexOutOfBoundsException( rank );
	}
	
	public boolean validateIndices()
	{
		boolean result = true;
		int n = this.size();
		
		//	First make sure that each node has the right index.
		for ( int i=0; i < N; i++ )
		{
			if ( null != this.elements[i] ) result &= (i == this.elements[i].index);
		}
		
		//	Check each ranked object.
		for ( int r=0; r < n; r++ )
		{
			int i = f + r;
			result &= (i == this.elements[i].index );
		}
		
		//	Check unused ranks
		for ( int r=n; r < N; r++ )
		{
			int i = f + r;
			result &= (null == this.elements[i] );
		}
		
		return result;
	}
	
	private void resize()
	{
		int new_capacity = 2 * N;
		Node<E>[] A = createNodeArray( new_capacity );
		int n = this.size();
		
		for ( int r=0; r < n; r++ )
		{
			int i = (f + r) % N;
			A[r] = this.elements[i];
			A[r].index = r;
		}
		
		this.N = new_capacity;
		this.elements = A;
		this.f = 0;
		this.b = n;
	}
	
	private Node<E> cast( IPosition<E> p )
	{
		Node<E> n = (Node<E>) p;
		if ( n.owner != this ) throw new IllegalArgumentException();
		return n;
	}
	
	@SuppressWarnings("unchecked")
	private Node<E>[] createNodeArray( int size )
	{
		return new Node[size];
	}

	/**
	 * O(1)
	 */
	public void addFirst(E anElement)
	{
		this.insertFirst( anElement );
	}

	/**
	 * O(1)
	 */
	public void addLast(E anElement)
	{
		this.insertLast( anElement );
	}

	/**
	 * O(1)
	 */
	public E removeFirst() throws NoSuchElementException
	{
		E ret = this.get( 0 );
		this.elements[f] = null;
		this.f = (f + 1) % N;
		return ret;
	}

	/**
	 * O(1)
	 */
	public E removeLast() throws NoSuchElementException
	{
		return this.remove( last() );	//	O(1) removing last.
	}
	
	/**
	 * O(n)
	 */
	public IPIterator<E> positions()
	{
		try
		{
			PositionIterator<E> it = new PositionIterator<E>();
			int n = this.size();
			for ( int r=0; r < n; r++ )
			{
				IPosition<E> p = this.atRank( r );
				it.addPosition( p );
			}
			return it;
		}
		catch ( IndexOutOfBoundsException ex )
		{
			throw new ImplementationException( ex, "Unexpected IndexOutOfBoundsException caught" );
		}
	}

	/**
	 * Time-complexity O(n).
	 */
	public IPosition<E> carefulAdd( int rank, E anElement )
	{
		IPosition<E> p = null;
		try
		{
			this.add( rank, anElement );			
			p = atRank( rank );
		}
		catch ( IndexOutOfBoundsException ex )
		{
			throw new ImplementationException( ex, "Unexpected IndexOutOfBoundsException caught" );
		}
		return p;
	}

}
