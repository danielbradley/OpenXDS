package org.openxds.adt.std;

import org.openxds.adt.*;
import org.openxds.adt.IIterator;

/**
 * Map implemented using a List ADT.
 * 
 * All operations are O(n) except size() and empty() which are O(1).
 */
public class ListMap<K, V> implements IMap<K, V>
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
	
	public ListMap( IComparitor<K> aComparitor )
	{
		this.comparitor = aComparitor;
	}
	
	/**
	 * Time-complexity O(n), as entire list may be searched for key.
	 */
	public V get(K key)
	{
		V value = null;
		
		IPIterator<Entry> it = this.list.positions();
		while ( it.hasNext() )
		{
			IPosition<Entry> p = it.next();
			Entry e = p.getElement();
			if ( 0 == this.comparitor.compare( e.key, key ) )
			{
				value = e.value;
				break;
			}
		}
		return value;
	}

	/**
	 * Time-complexity O(n), as entire list must be searched for existing key.
	 */
	public V put(K key, V value)
	{
		V old_value = null;

		IPIterator<Entry> it = this.list.positions();
		while ( it.hasNext() )
		{
			IPosition<Entry> p = it.next();
			Entry e = p.getElement();
			if ( 0 == this.comparitor.compare( e.key, key ) )
			{
				old_value = e.value;
				e.value = value;
				break;
			}
		}
		
		if ( null == old_value )
		{
			Entry e = new Entry( key, value );
			e.location = this.list.insertLast( e );
		}
		return old_value;
	}

	/**
	 * Time-complexity O(n), as entire list may be searched for existing key.
	 */
	public V remove(K key)
	{
		V value = null;

		IPIterator<Entry> it = this.list.positions();
		while ( it.hasNext() )
		{
			IPosition<Entry> p = it.next();
			Entry e = p.getElement();
			if ( 0 == this.comparitor.compare( e.key, key ) )
			{
				Entry e_removed = this.list.remove( e.location );
				value = e_removed.value;
				break;
			}
		}
		
		return value;
	}

	/**
	 * Time-complexity O(n).
	 */
	public IIterator<K> keys()
	{
		GenericIterator<K> gi = new GenericIterator<K>();
		IPIterator<Entry> it = this.list.positions();
		while ( it.hasNext() )
		{
			gi.addElement( it.next().getElement().getKey() );
		}
		return gi;
	}

	/**
	 * Time-complexity O(n).
	 */
	public IIterator<V> values()
	{
		GenericIterator<V> gi = new GenericIterator<V>();
		IPIterator<Entry> it = this.list.positions();
		while ( it.hasNext() )
		{
			gi.addElement( it.next().getElement().getValue() );
		}
		return gi;
	}

	/**
	 * O(1)
	 */
	public boolean isEmpty()
	{
		return this.list.isEmpty();
	}

	/**
	 * O(1)
	 */
	public int size()
	{
		return list.size();
	}
}
