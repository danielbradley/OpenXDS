package org.openxds.adt;

public interface IComparitor<K>
{
	/**
	 * Returns an integer less than zero, equal to zero, or greater than zero;
	 * if a is less than b, a equals b, or a is greater than b, respectively.
	 * 
	 * @param a
	 * @param b
	 * @return an integer representing the difference between a and b.
	 */
	public int compare( K a, K b );
}
