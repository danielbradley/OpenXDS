package org.openxds.adt;

import org.openxds.exceptions.IndexOutOfBoundsException;

public interface ISequence<E> extends IDeque<E>, IVector<E>, IList<E>
{
	/**
	 * Translates a rank to a position.
	 * 
	 * @param rank, specifying a position.
	 * @return the position specified by the passed rank.
	 * @throws IndexOutOfBoundsException, if the rank is negative, or out of bounds.
	 */
	public IPosition<E> atRank( int rank ) throws IndexOutOfBoundsException;

	/**
	 * Returns the rank of a given position.
	 * 
	 * @param p, a position within the sequence.
	 * @return the rank of the specified position.
	 */
	public int rankOf( IPosition<E> p );
}
