package org.openxds.adt;

/**
 * Generalisation of a Euler tour for a General Tree.
 *
 * @param <E>, the type stored by the traversed tree.
 * @param <R>, the result type returned from the tour.
 */
public interface IGeneralTour<E, R>
{
	/**
	 * @param t, the tree to be traversed.
	 */
	public void   setTree( ITree<E> t );

	/**
	 * Performs a general tour of the tree, t, specified by calling "setTree".
	 * 
	 * @param p, a position of the tree, t.
	 * @return the final result of the tour.
	 */
	public R doGeneralTour( IPosition<E> p );
}
