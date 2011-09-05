package org.openxds.adt.std;

import org.openxds.adt.IBinaryTree;
import org.openxds.adt.IPIterator;
import org.openxds.adt.IPosition;
import org.openxds.exceptions.SemanticException;

import java.util.NoSuchElementException;

public class ArrayBinaryTree<E> implements IBinaryTree<E>
{
	class Node implements IPosition<E>
	{
		IBinaryTree<E> o;
		E              e;
		int            index;
		
		Node( IBinaryTree<E> owner, E anElement, int anIndex )
		{
			this.o = owner;
			this.e = anElement;
			this.index = anIndex;
		}
		
		public E getElement()
		{
			return this.e;
		}
	}

	Array<Node> nodes;
	int size;

	/**
	 * Instantiates a new ArrayBinaryTree
	 * 
	 * Time-complexity is O(1) as initial tree is empty.
	 */
	public ArrayBinaryTree() {}
	
	/**
	 * Instantiates a new ArrayBinaryTree based upon the passed in generic array.
	 * 
	 * Time-complexity is O(n) as each element must be copied.
	 */
	public ArrayBinaryTree( E[] elements )
	{
		int N = elements.length;
		this.nodes = new Array<Node>( N );
		for ( int i=0; i < N; i++ )
		{
			if ( null != elements[i] )
			{
				this.nodes.set(i, new Node(this,elements[i],i) );
				this.size++;
			}
		}
		
		if ( 0 == this.size )
		{
			this.nodes = null;
		}
	}

	/**
	 * Time-complexity O(1)
	 */
	public IPosition<E> addRoot(E e) throws IllegalStateException
	{
		this.nodes = new Array<Node>( 2 );
		this.nodes.set( 1, new Node( this, e, 1 ) );
		this.size++;
		return this.nodes.get(1);
	}

	/**
	 * Time-complexity O(1)
	 */
	public IPosition<E> addChild(IPosition<E> p, E e) throws IllegalStateException
	{
		boolean left = this.hasLeft(p);
		boolean right = this.hasRight(p);
		
		Node n = cast(p);
		int index = n.index*2;
		if ( left && right ) throw new IllegalStateException();
		else if ( left )
		{
			index++;
		}
		
		// O(n) is amortised to O(1) over n calls through doubling
		if ( this.nodes.length <= index ) this.nodes.enlarge();
		
		this.nodes.set( index, new Node( this, e, index ) );
		this.size++;
		return this.nodes.get( index );
	}

	public IPosition<E> addLeft(IPosition<E> p, E e) throws SemanticException
	{
		if ( this.hasLeft( p ) ) throw new SemanticException();
		
		Node n = cast( p );
		int index = n.index * 2;
		this.nodes.set( index, new Node( this, e, index ) );
		return this.nodes.get(index);
	}

	public IPosition<E> addRight(IPosition<E> p, E e) throws SemanticException
	{
		if ( this.hasRight( p ) ) throw new SemanticException();
		
		Node n = cast( p );
		int index = (n.index * 2) + 1;
		this.nodes.set( index, new Node( this, e, index ) );
		return this.nodes.get(index);
	}
	
	/**
	 * Time-complexity O(t.size()), as either addLeftSubtree or addRightSubtree is called,
	 * which then recursively call moveSubtreeInto t.size() - 1 times.
	 */
	public IPosition<E> addSubtree( IPosition<E> p, IBinaryTree<E> t ) throws IllegalStateException
	{
		if ( ! this.hasLeft( p ) )
		{
			return addLeftSubtree( p, t );
		}
		else if ( ! this.hasRight( p ) )
		{
			return addRightSubtree( p, t );
		}
		else
		{
			throw new IllegalStateException();
		}
	}
	
	/**
	 * Time-complexity O(t.size()), as calls moveSubtreeInto t.size() - 1 times.
	 */
	public IPosition<E> addLeftSubtree( IPosition<E> p, IBinaryTree<E> t ) throws IllegalStateException
	{
		if ( this.hasLeft( p ) ) throw new IllegalStateException();
		
		Node parent = cast( p );
		
		int left = parent.index * 2;
		this.moveSubtreeInto( left, t, t.root() );
		
		return this.nodes.get( left );
	}
	
	/**
	 * Time-complexity O(t.size()), as calls moveSubtreeInto t.size() - 1 times.
	 */
	public IPosition<E> addRightSubtree( IPosition<E> p, IBinaryTree<E> t ) throws IllegalStateException
	{
		if ( this.hasLeft( p ) ) throw new IllegalStateException();
		
		Node parent = cast( p );
		
		int left = parent.index * 2;
		this.moveSubtreeInto( left, t, t.root() );

		return this.nodes.get( left );
	}

	/**
	 * Time-complexity O(t.size()), a recursively calls self t.size() - 1 times.
	 */
	private void moveSubtreeInto( int index, IBinaryTree<E> t, IPosition<E> p )
	{
		if ( this.nodes.length <= index ) this.nodes.enlarge();
		
		this.nodes.set( index, new Node( this, p.getElement(), index ));
		
		if ( t.hasLeft( p ) )
		{
			moveSubtreeInto( index*2, t, t.left( p ) );
		}
		
		if ( t.hasRight( p ) )
		{
			moveSubtreeInto( index*2 + 1, t, t.right( p ) );
		}

		t.remove( p );
	}
	
	/**
	 * Time-complexity O(1)
	 */
	public E remove(IPosition<E> p) throws IllegalArgumentException
	{
		if ( this.isInternal(p) ) throw new IllegalArgumentException();
		
		Node n = cast(p);
		E ret = n.e;
		this.nodes.set( n.index, null );
		this.size--;
		
		if ( 1 == n.index ) this.nodes = null;
		
		return ret;
	}

	/**
	 * Time-complexity O(1)
	 */
	public E replace(IPosition<E> p, E e)
	{
		Node n = cast(p);
		E    old = n.e;
		n.e      = e;
		return old;
	}

	/**
	 * Time-complexity O(t.size()), as recursively calls moveSubtreeInto t.size() - 1 times.
	 */
	public IBinaryTree<E> removeAsTree( IPosition<E> p )
	{
		ArrayBinaryTree<E> t = new ArrayBinaryTree<E>();
		t.moveSubtreeInto( 1, this, p );
		
		return t;
	}
	
	/**
	 * O(1)
	 */
	public IPosition<E> left(IPosition<E> p) throws NoSuchElementException
	{
		if ( ! this.hasLeft( p ) ) throw new NoSuchElementException();

		Node n = cast( p );
		int index = n.index * 2;
		return this.nodes.get(index);
	}

	/**
	 * O(1)
	 */
	public IPosition<E> right(IPosition<E> p)
	{
		if ( ! this.hasRight( p ) ) throw new NoSuchElementException();

		Node n = cast( p );
		int index = n.index * 2 + 1;
		return this.nodes.get(index);
	}

	/**
	 * O(1)
	 */
	public boolean hasLeft(IPosition<E> p)
	{
		Node n = cast( p );
		int index = n.index * 2;
		return ( (index < this.nodes.length) && (null != this.nodes.get(index)) );
	}

	/**
	 * O(1)
	 */
	public boolean hasRight(IPosition<E> p) {
		Node n = cast( p );
		int index = n.index * 2 + 1;
		return ( (index < this.nodes.length) && (null != this.nodes.get(index)) );
	}

	/**
	 * O(1)
	 */
	public IPIterator<E> children(IPosition<E> p)
	{
		PositionIterator<E> it = new PositionIterator<E>();

		if ( this.hasLeft(p) )  it.addPosition( this.left(p) );
		if ( this.hasRight(p) ) it.addPosition( this.right(p) );
		
		return it;
	}

	/**
	 * O(1)
	 */
	public IPosition<E> parent(IPosition<E> p) throws NoSuchElementException
	{
		Node n = cast( p );
		if ( 1 == n.index ) throw new NoSuchElementException();
		
		int parent = n.index / 2;
		return this.nodes.get(parent);
	}

	/**
	 * O(1)
	 */
	public IPosition<E> root() throws NoSuchElementException
	{
		if ( null == this.nodes ) throw new NoSuchElementException();

		return this.nodes.get(1);
	}

	/**
	 * O(1)
	 */
	public boolean isEmpty()
	{
		return ( null == this.nodes );
	}

	/**
	 * O(1)
	 */
	public boolean isExternal(IPosition<E> p)
	{
		return (! this.isInternal(p) );
	}

	/**
	 * O(1)
	 */
	public boolean isInternal(IPosition<E> p)
	{
		return ( this.hasLeft(p) || this.hasRight(p) );
	}

	/**
	 * O(1)
	 */
	public boolean isRoot(IPosition<E> p)
	{
		Node n = cast(p);
		return (1 == n.index);
	}

	/**
	 * O(1)
	 */
	public int size()
	{
		return this.size;
	}

	private Node cast( IPosition<E> p ) throws IllegalArgumentException
	{
		Node n = null;
		try
		{
			n = (Node) p;
			if ( this != n.o ) throw new IllegalArgumentException( "Node is not owned by this Binary Tree" );
		} catch ( ClassCastException ex ) {
			throw new IllegalArgumentException( "Position isn't an Array Binary Tree Node" );
		}
		return n;
	}
}
