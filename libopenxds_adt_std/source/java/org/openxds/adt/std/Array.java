package org.openxds.adt.std;

/**
 * Abstracts the use of arrays in Java to get around not being able
 * to cleanly allocate a generic array.
 */
public class Array<E>
{
	private Object[] A;
	public int length;
	
	/**
	 * O(n)
	 */
	public Array( int N )
	{
		this.length = N;
		this.A = newArray( N );
	}

	/**
	 * O(1)
	 */
	public void set( int index, E e )
	{
		this.A[index] = e;
	}

	/**
	 * O(1)
	 */
	@SuppressWarnings("unchecked")
	public E get( int index )
	{
		return (E) A[index];
	}

	/**
	 * O(n)
	 */
	public void enlarge()
	{
		Object[] B = newArray( 2 * this.length );
		int n = this.length;
		for ( int i=0; i < n; i++ )
		{
			B[i] = A[i];
		}
		this.length *= 2;
		this.A = B;
	}
	
	/**
	 * O(n)
	 */
	@SuppressWarnings("unchecked")
	private E[] newArray( int N )
	{
		return (E[]) new Object[N];
	}
}
