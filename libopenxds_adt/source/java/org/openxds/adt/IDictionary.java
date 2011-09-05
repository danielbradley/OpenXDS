package org.openxds.adt;

public interface IDictionary<K,V>
{
	/**
	 * Inserts a new entry in the dictionary mapping aKey to aValue.
	 * 
	 * @param aKey
	 * @param aValue
	 * @return an entry corresponding to the new mapping.
	 */
	public IEntry<K,V> insert( K aKey, V aValue );

	/**
	 * Removes the passed entry from the dictionary.
	 * 
	 * @param anEntry
	 * @return the entry that was passed in.
	 */
	public IEntry<K,V> remove( IEntry<K,V> anEntry );
	
	/**
	 * Find the first entry that contains the passed key.
	 * 
	 * @param aKey
	 * @return the first entry if it exists; otherwise null.
	 */
	public IEntry<K,V> find( K aKey );
	
	/**
	 * Return an Entry Iterator containing all the entries that contain
	 * the passed key.
	 * 
	 * @param aKey
	 * @return an Iterator of entries.
	 */
	public IEIterator<K,V> findAll( K aKey );

	/**
	 * Return an Iterator of all of the entries in this dictionary.
	 * 
	 * @return an Iterator of Entries.
	 */
	public IEIterator<K,V> entries();
	
	/**
	 * @return the number of entries in this dictionary.
	 */
	public int size();

	/**
	 * @return true, if the dictionary contains no entries; false otherwise.
	 */
	public boolean isEmpty();
}
