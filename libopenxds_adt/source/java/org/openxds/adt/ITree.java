package org.openxds.adt;

import org.openxds.exceptions.NoSuchElementException;
import org.openxds.exceptions.SemanticException;

public interface ITree<E>
{
	/**
	 * Add a new root to the tree containing the element e.
	 * 
	 * @param e
	 * @return the position associated with the new tree node.
	 * @throws IllegalStateException, if the tree already contains a root node.
	 */
	public IPosition<E> addRoot( E e ) throws SemanticException;

	/**
	 * Adds a new child to the parent node p that contains the element e.
	 * 
	 * @param p, the position of the parent node.
	 * @param e, the element to be stored in the new child node.
	 * @return the position associated with the new node.
	 */
	public IPosition<E> addChild( IPosition<E> p, E e );

	/**
	 * Adds the passed tree as a descendants of p.
	 * 
	 * @param p, the new parent.
	 * @param t, the existing tree.
	 * @return the new position of the old root of t.
	 */
	public IPosition<E> addSubtree( IPosition<E> p, ITree<E> t );
	
	/**
	 * Remove the tree node pointed to by position.
	 * @param p, the position to remove.
	 * @return e, the element stored at the position.
	 * @throws SemanticException, if the position has children.
	 */
	public E remove( IPosition<E> p ) throws SemanticException;

	/**
	 * Replace the element that is stored in the node at position p.
	 * 
	 * @param p, the position of the tree node.
	 * @param e, the element to be stored at p.
	 * @return the existing element stored at p.
	 */
	public E replace( IPosition<E> p, E e );

	/**
	 * Remove the subtree rooted by tree node and return it as an independent tree.
	 * @param p, the position representing the root of the subtree to remove.
	 * @return an independent tree.
	 */
	public ITree<E> removeAsTree( IPosition<E> p );
	
	/**
	 * @return the position of the root of the tree.
	 * @throws NoSuchElementException, if the tree is empty.
	 */
	public IPosition<E> root() throws NoSuchElementException;

	/**
	 * @param p, a node of the tree.
	 * @return the parent of the node p.
	 * @throws NoSuchElementException, if p is the root of the tree.
	 */
	public IPosition<E> parent( IPosition<E> p ) throws NoSuchElementException;

	/**
	 * @param p, a node of the tree.
	 * @return an iterator containing the positions of the children of p.  
	 */
	public IPIterator<E> children( IPosition<E> p );
	
	/**
	 * @param p
	 * @return true if p is the root of this tree; false otherwise.
	 */
	public boolean isRoot( IPosition<E> p );
	
	/**
	 * @param p
	 * @return true if p is an internal node (has one or more children); false otherwise.
	 */
	public boolean isInternal( IPosition<E> p );
	
	/**
	 * @param p
	 * @return true if p is an external node; false otherwise.
	 */
	public boolean isExternal( IPosition<E> p );
	
	/**
	 * @return the number of nodes in this tree.
	 */
	public int size();

	/**
	 * @return true, if there are node nodes in the tree; false otherwise.
	 */
	public boolean isEmpty();
}
