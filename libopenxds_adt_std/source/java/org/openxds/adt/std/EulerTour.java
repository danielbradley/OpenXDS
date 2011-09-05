package org.openxds.adt.std;

import org.openxds.adt.*;
import org.openxds.exceptions.ImplementationException;
import org.openxds.exceptions.NoSuchElementException;

public abstract class EulerTour<E>
{
	protected IBinaryTree<E> tree;

	protected class Result
	{
		Object leftResult;
		Object rightResult;
		Object finalResult;
	}
	
	protected void visitLeft( IPosition<E> p, Result r ) {}
	protected void visitBelow( IPosition<E> p, Result r ) {}
	protected void visitRight( IPosition<E> p, Result r ) {}
	protected void visitExternal( IPosition<E> p, Result r ) {}

	public Object eulerTour( IPosition<E> p )
	{
		Result r = new Result();

		if ( tree.isExternal( p ) )
		{
			visitExternal( p, r );
		}
		else
		{
			try
			{
				visitLeft( p, r );
				if ( tree.hasLeft( p ) ) r.leftResult = eulerTour( tree.left(p) );
				visitBelow( p, r );
				if ( tree.hasRight( p ) ) r.rightResult = eulerTour( tree.right(p) );
				visitRight( p, r );
			}
			catch ( NoSuchElementException ex )
			{
				throw new ImplementationException( ex, "Unexpected IndexOutOfBoundsException caught" );
			}
		}

		return r.finalResult;
	}
}
