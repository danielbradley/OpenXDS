package org.openxds.adt;

public interface IMap<K,V>
{
	/**
	 * Inserts a new entry in the map mapping aKey to aValue.
	 * 
	 * @param aKey
	 * @param aValue
	 * @return the pre-existing value in the map; otherwise null.
	 */
	public V put( K aKey, V aValue );

	/**
	 * Removes the entry associated with the passed key from the map.
	 * 
	 * @param aKey
	 * @return the value mapped to from key if the entry exists; otherwise null.
	 */
	public V remove( K aKey );
	
	/**
	 * Return the value associated with the passed key.
	 * 
	 * @param aKey
	 * @return the associated value if it exists; otherwise null.
	 */
	public V get( K aKey );
	
	/**
	 * @return an iterator of all keys in this map.
	 */
	public IIterator<K> keys();

	/**
	 * @return an iterator of all values in this map.
	 */
	public IIterator<V> values();
	
	/**
	 * @return the number of entries in this map.
	 */
	public int size();

	/**
	 * @return true, if the map contains no entries; false otherwise.
	 */
	public boolean isEmpty();
}
