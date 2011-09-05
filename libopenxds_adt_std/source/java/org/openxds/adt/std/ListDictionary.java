package org.openxds.adt.std;

import org.openxds.adt.*;

/**
 * Unsorted List implementation of the Dictionary ADT.
 * 
 * Space complexity is O(n), where n is the number of entries inserted.
 */
public class ListDictionary<K, V> implements IDictionary<K, V>
{
	private class Entry implements IEntry<K,V>
	{
		K key;
		V value;
		IPosition<Entry> location;
		
		public Entry( K aKey, V aValue ) { key = aKey; value = aValue; }
		
		public K getKey() { return key; }
		public V getValue() { return value; }
	}
	
	List<Entry> list = new List<Entry>();
	IComparitor<K> comparitor;
	
	public ListDictionary( IComparitor<K> aComparitor )
	{
		this.comparitor = aComparitor;
	}

	/**
	 * Time-complexity is O(1)
	 */
	public IEntry<K,V> insert(K key, V value)
	{
		Entry e = new Entry( key, value );
		e.location = this.list.insertLast( e );
		return e;
	}

	/**
	 * Time-complexity is O(1), as the entry is location aware.
	 */
	public IEntry<K,V> remove( IEntry<K,V> anEntry )
	{
		Entry e = (Entry) anEntry;
		Entry e_removed = this.list.remove( e.location );
		return e_removed;
	}

	/**
	 * Time-complexity is O(n), as the list must be searched for the first key.
	 */
	public IEntry<K,V> find(K key)
	{
		Entry e = null;
		
		IPIterator<Entry> it = this.list.positions();
		while ( it.hasNext() )
		{
			IPosition<Entry> p = it.next();
			if ( 0 == this.comparitor.compare( p.getElement().key, key ) )
			{
				e = p.getElement();
				break;
			}
		}
		
		return e;
	}

	/**
	 * Time-complexity is O(n), as the whole list must be traversed.
	 */
	public IEIterator<K,V> findAll( K key )
	{
		EntryIterator<K,V> eit = new EntryIterator<K,V>();
		
		IPIterator<Entry> it = this.list.positions();
		while ( it.hasNext() )
		{
			IEntry<K,V> e = it.next().getElement();
			if ( 0 == this.comparitor.compare( e.getKey(), key ) )
			{
				eit.addEntry( e );
			}
		}
		return eit;
	}
	
	/**
	 * Time-complexity is O(n), as the whole list must be traversed.
	 */
	public IEIterator<K,V> entries()
	{
		EntryIterator<K,V> eit = new EntryIterator<K,V>();
		
		IPIterator<Entry> it = this.list.positions();
		while ( it.hasNext() )
		{
			IEntry<K,V> e = it.next().getElement();
			eit.addEntry( e );
		}
		return eit;
	}

	/**
	 * Time-complexity is O(1).
	 */
	public boolean isEmpty()
	{
		return this.list.isEmpty();
	}

	/**
	 * Time-complexity is O(1).
	 */
	public int size()
	{
		return list.size();
	}
}
