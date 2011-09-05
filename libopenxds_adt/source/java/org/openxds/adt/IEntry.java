package org.openxds.adt;

public interface IEntry<K, V>
{
	/**
	 * @return the key identifying this entry.
	 */
	public K getKey();
	
	/**
	 * @return the value stored in this entry.
	 */
	public V getValue();
}
