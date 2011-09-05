package org.openxds.adt.std;

import org.openxds.adt.IList;
import org.openxds.adt.IEntry;
import org.openxds.adt.IEIterator;
import org.openxds.adt.IPIterator;

import org.openxds.exceptions.NoSuchElementException;

/**
 * Entry iterator implemented using a List.
 * All operations are O(1).
 */
public class EntryIterator<K,V> implements IEIterator<K,V>
{
	private IList<IEntry<K,V>> entries = new List<IEntry<K,V>>();
	private IPIterator<IEntry<K,V>> it = null;
	
	public EntryIterator()
	{}
	
	/**
	 * O(1)
	 */
	public boolean hasNext()
	{
		if ( null == it ) it = this.entries.positions();
		
		return it.hasNext();
	}

	/**
	 * O(1)
	 */
	public IEntry<K,V> next() throws NoSuchElementException
	{
		return this.it.next().getElement();
	}
	
	/**
	 * O(1)
	 */
	public void reset()
	{
		this.it.reset();
	}
	
	/**
	 * O(1)
	 */
	protected void addEntry( IEntry<K,V> e )
	{
		this.entries.insertLast( e );
	}
}
