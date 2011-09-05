package org.openxds.adt.std;

import org.openxds.base.*;
import org.openxds.exceptions.NoSuchElementException;
import org.openxds.adt.*;

/**
 * @param <E>, is the element type stored within the tree.
 * @param <R>, is the element type returned by doGeneralTour.
 */
public abstract class GeneralTour<E, R> implements IGeneralTour<E, R>
{
	protected ITree<E> tree;

	/**
	 * If extra members are required, Result should be extended by a subclass
	 * and the createResult method appropriately overridden.
	 */
	protected class Result
	{
		public R intermediateResult;
		public R finalResult;
	}
	
	/**
	 * Specifies the tree to be traversed by this tour.
	 * 
	 * @param aTree, the tree to be traversed.
	 */
	public void setTree( ITree<E> aTree )
	{
		this.tree = aTree;
	}
	
	/**
	 * Performs a general tour of the tree specified using "setTree".
	 * 
	 * @param p, the position in the tree to begin the traversal from.
	 */
	public R doGeneralTour( IPosition<E> p )
	{
		Result r = createResult();
		
		try
		{
			if ( null == p ) p = this.tree.root();

			if ( tree.isExternal( p ) )
			{
				visitExternal( p, r );
			}
			else
			{
				this.visitPreorder( p, r);
				
				IPIterator<E> it = tree.children( p );
				while ( it.hasNext() )
				{
					IPosition<E> child = it.next();
					r.intermediateResult = this.doGeneralTour( child );
					this.visitBelow( p, r );
				}
				this.visitPostorder( p, r );
			}
		}
		catch ( NoSuchElementException ex )
		{
			//If no root just return final result of new result.
		}
		return r.finalResult;
	}
	
	/**
	 * This method can be overridden to return a custom Result object
	 * that derives from Result.
	 * 
	 * @return a new Result object.
	 */
	protected Result createResult()
	{
		return new Result();
	}
	
	/**
	 * visitPreorder can be overridden by a deriving class.
	 * 
	 * @param p, a position in the tree.
	 * @param r, a Result object.
	 */
	protected void visitPreorder( IPosition<E> p, Result r ) {}

	/**
	 * visitBelow can be overridden by a deriving class.
	 * 
	 * @param p, a position in the tree.
	 * @param r, a Result object.
	 */
	protected void visitBelow( IPosition<E> p, Result r ) {}

	/**
	 * visitPostorder can be overridden by a deriving class.
	 * 
	 * @param p, a position in the tree.
	 * @param r, a Result object.
	 */
	protected void visitPostorder( IPosition<E> p, Result r ) {}

	/**
	 * visitExternal can be overridden by a deriving class.
	 * 
	 * @param p, a position in the tree.
	 * @param r, a Result object.
	 */
	protected void visitExternal( IPosition<E> p, Result r ) {}
}
