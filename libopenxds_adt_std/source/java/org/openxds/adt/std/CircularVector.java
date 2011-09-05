package org.openxds.adt.std;

import org.openxds.exceptions.IndexOutOfBoundsException;
import org.openxds.adt.IVector;

/**
 * Vector implemented using a circular array.
 * Insertions to rank 0 and rank size() are O(1); otherwise O(n).
 * Other operations are O(1).
 */
public class CircularVector<E> implements IVector<E>
{
	static final int DEFAULT_CAPACITY = 1;
	
	E[] V = null;
	int f = 0;
	int b = 0;
	int N = 0;
	
	public CircularVector()
	{
		V = elementArray(DEFAULT_CAPACITY);
		N = DEFAULT_CAPACITY;
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
		return (size() == (N - 1));
	}
	
	/**
	 * O(1)
	 */
	public int size()
	{
		return (N - f + b) % N;
	}

	/**
	 * O(1)
	 */
	public E set( int r, E e ) throws IndexOutOfBoundsException
	{
		if ( (r < 0) || (size() <= r) ) throw new IndexOutOfBoundsException( r );
		
		int i = (f + r) % N;
		E   t = V[i];
		V[i]  = e;
		return t;
	}

	/**
	 * O(1)
	 */
	public E get( int r ) throws IndexOutOfBoundsException
	{
		if ( (r < 0) || (size() <= r) ) throw new IndexOutOfBoundsException( r );

		int i = (f + r) % N;
		return V[i];
	}
	
	/**
	 * O(1) if r is 0 or size(); O(n) otherwise.
	 */
	public void add( int r, E e ) throws IndexOutOfBoundsException
	{
		int n = size();
		if ( (r < 0) || (n < r) ) throw new IndexOutOfBoundsException( r );

		if ( isFull() ) enlarge();

		if ( 0 == r )
		{
			f = (N + f - 1) % N;
			V[f] = e;
		}
		else
		{
			for ( int i = r; i < n; i++ )
			{
				e = set( r, e );
			}
			V[b] = e;
			b = (b + 1) % N;
		}
	}

	/**
	 * O(1) if r is 0 or size(); O(n) otherwise.
	 */
	public E removeFrom( int r ) throws IndexOutOfBoundsException
	{
		int n = size();
		if ( (r < 0) || (n <= r) ) throw new IndexOutOfBoundsException( r );

		if ( 0 == r )
		{
			E e = V[f];
			V[f] = null;
			f   = (f + 1) % N;
			return e;
		}
		else
		{
			E e = null;		//	Get the last element;
			for ( int i = n-1; i >= r; i-- )
			{
				e = set( i, e );	//	Replace elements until we reach r.
			}
			b = (N + b - 1) % N;
			V[b] = null;
			return e;
		}
	}
	
	/**
	 * O(n), but amortised to O(1).
	 */
	private void enlarge()
	{
		int n = size();
		int N2 = N * 2;
		E[] V2 = elementArray( N2 );
		
		for ( int i=0; i < n; i++ )
		{
			V2[i] = this.get(i);
		}
		
		f = 0;
		b = n;
		N = N2;
		V = V2;
	}

	@SuppressWarnings("unchecked")
	private E[] elementArray( int size )
	{
		return (E[]) new Object[size];
	}
}
