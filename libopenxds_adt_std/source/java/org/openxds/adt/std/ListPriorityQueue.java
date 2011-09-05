package org.openxds.adt.std;

import org.openxds.adt.*;

/**
 * Priority Queue implemented using an Unsorted List.
 * 
 * Space complexity is O(n).
 */
public class ListPriorityQueue<K,V> implements IPriorityQueue<K, V>
{
	class Entry implements IEntry<K,V>
	{
		IPriorityQueue<K,V> o;
		K k;
		V v;

		Entry( IPriorityQueue<K,V> anOwner, K aKey, V aValue )
		{
			this.o = anOwner;
			this.k = aKey;
			this.v = aValue;
		}
		
		public K getKey() { return k; }
		public V getValue() { return v; }
	}
	
	IList<IEntry<K,V>> entries = new List<IEntry<K,V>>();
	IComparitor<K> comparitor;

	public ListPriorityQueue( IComparitor<K> aComparitor )
	{
		this.comparitor = aComparitor;
	}

	/**
	 * Time-complexity O(n), as entire list may be searched.
	 */
	public IEntry<K,V> insert( K aKey, V aValue )
	{
		if ( null == this.comparitor ) throw new IllegalStateException();

		IEntry<K,V> entry = new Entry( this, aKey, aValue );

		IPIterator<IEntry<K,V>> it = this.entries.positions();
		while ( it.hasNext() )
		{
			IPosition<IEntry<K,V>> p = it.next();
			K k = p.getElement().getKey();
			
			if ( this.comparitor.compare( aKey, k ) < 0 )
			{
				this.entries.insertBefore( p, entry );
				return entry;
			}
		}
		this.entries.insertLast( entry );
		return entry;
	}
	
	/**
	 * Time-complexity O(1).
	 */
	public IEntry<K,V> removeMin()
	{
		IEntry<K,V> entry = this.entries.remove( this.entries.first() );
		return entry;
	}
	
	/**
	 * Time-complexity O(1).
	 */
	public IEntry<K,V> min()
	{
		IEntry<K,V> entry = this.entries.first().getElement();
		return entry;
	}

	/**
	 * Time-complexity O(1).
	 */
	public void setComparitor( IComparitor<K> c )
	{
		this.comparitor = c;
	}

	/**
	 * Time-complexity O(1).
	 */
	public int size()
	{
		return this.entries.size();
	}
	
	/**
	 * Time-complexity O(1).
	 */
	public boolean isEmpty()
	{
		return this.entries.isEmpty();
	}
}
