package org.openxds.adt.std;

import org.openxds.adt.IList;
import org.openxds.adt.IPIterator;
import org.openxds.adt.IPosition;
import org.openxds.adt.ITree;

/**
 * Tree implemented using Nodes with Children stored in a List.
 * Space-complexity is O(n).
 */
public class Tree<E> implements ITree<E>
{
	Node<E> root;
	int     size;
	
	class Node<F> implements IPosition<F>
	{
		ITree<F> owner;
		IPosition<F> parent;
		IList<Node<F>> children = new List<Node<F>>();
		IPosition<Node<F>> location = null;
		F e;
		
		Node( ITree<F> t, F e ) { this.owner = t; this.e = e; }
		
		public F getElement() { return e; }
		
		/**
		 * @complexity O(n)
		 */
		private int setOwnerReturnSize( ITree<F> anOwner )
		{
			this.owner = anOwner;
			int size = 1;
			
			IPIterator<Node<F>> it = this.children.positions();
			while ( it.hasNext() )
			{
				IPosition<Node<F>> p = it.next();
				Node<F> n = p.getElement();
				size += n.setOwnerReturnSize( anOwner );
			}
			return size;
		}
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> addRoot(E e) throws IllegalStateException
	{
		if ( null != this.root ) throw new IllegalStateException( "Adding root to non-empty tree" );
		
		this.root = new Node<E>( this, e );
		this.size++;
		return this.root;
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> addChild(IPosition<E> p, E e)
	{
		Node<E> node  = cast( p );
		Node<E> child = new Node<E>( this, e );
		child.parent = node;
		child.location = node.children.insertLast( child );
		this.size++;
		return child;
	}
	
	/**
	 * Time-complexity O(t.size()), as must update owner for every existing node in subtree.
	 */
	public IPosition<E> addSubtree( IPosition<E> p, ITree<E> t ) throws IllegalStateException
	{
		Tree<E> tree = (Tree<E>) t;
		Node<E> parent = (Node<E>) p;
		Node<E> child = tree.root;
		
		child.parent = parent;
		child.location = parent.children.insertLast( child );
		child.setOwnerReturnSize( parent.owner );
		this.size += tree.size;
		
		tree.size = 0;
		tree.root = null;
		
		return child;
	}

	/**
	 * Time-complexity O(1).
	 */
	public E remove( IPosition<E> p )
	{
		if ( this.isInternal( p ) ) throw new IllegalArgumentException();

		Node<E> child = cast( p );
		Node<E> parent = cast( this.parent( p ) );
		Node<E> node   = parent.children.remove( child.location );
		
		this.size--;
		return node.getElement();
	}

	/**
	 * Time-complexity O(size(t)), where t is returned tree, as must set new owner of each node.
	 */
	public ITree<E> removeAsTree( IPosition<E> p )
	{
		Node<E> node   = cast( p );
		Node<E> parent = cast( this.parent( p ) );
		
		Node<E> root = parent.children.remove( node.location );
		
		Tree<E> subtree = new Tree<E>();
		subtree.root = root;
		subtree.size = root.setOwnerReturnSize( subtree );
		
		this.size -= subtree.size;
		
		return subtree;
	}
	
	/**
	 * Time-complexity O(n), as need to construct iterator of tree positions.
	 */
	public IPIterator<E> children(IPosition<E> p)
	{
		Node<E> n = cast( p );
		IPIterator<Node<E>> it = n.children.positions();	// O(1) on List
		
		PositionIterator<E> it2 = new PositionIterator<E>(); 
		while ( it.hasNext() )
		{
			IPosition<Node<E>> position = it.next();
			Node<E> n2 = position.getElement();
			it2.addPosition( n2 ); 
		}
		
		return it2;
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> parent(IPosition<E> p)
	{
		Node<E> n = cast( p );
		return n.parent;
	}

	/**
	 * Time-complexity O(1).
	 */
	public IPosition<E> root() throws java.util.NoSuchElementException
	{
		if ( null == this.root ) throw new java.util.NoSuchElementException();
		
		return this.root;
	}

	/**
	 * Time-complexity O(1).
	 */
	public boolean isEmpty()
	{
		return ( 0 == this.size );
	}

	/**
	 * Time-complexity O(1).
	 */
	public boolean isExternal(IPosition<E> p)
	{
		Node<E> n = cast( p );
		return (n.children.size() == 0);
	}

	/**
	 * Time-complexity O(1).
	 */
	public boolean isInternal(IPosition<E> p)
	{
		return ! this.isExternal( p );
	}

	/**
	 * Time-complexity O(1).
	 */
	public boolean isRoot(IPosition<E> p)
	{
		Node<E> n = cast( p );
		return (null == n.parent);
	}

	/**
	 * Time-complexity O(1).
	 */
	public E replace(IPosition<E> p, E e)
	{
		Node<E> n = cast( p );
		E ret     = n.e;
		n.e = e;
		return ret;
	}

	/**
	 * Time-complexity O(1).
	 */
	public int size()
	{
		return this.size;
	}

	/**
	 * Time-complexity O(1).
	 */
	private Node<E> cast( IPosition<E> p )
	{
		try
		{
			Node<E> n = (Node<E>) p;
			if ( n.owner != this ) throw new IllegalArgumentException();
			return n;
		} catch ( ClassCastException ex ) {
			throw new IllegalArgumentException();
		}
	}
}
