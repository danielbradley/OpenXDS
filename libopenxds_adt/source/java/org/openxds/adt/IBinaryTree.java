package org.openxds.adt;

import org.openxds.exceptions.NoSuchElementException;
import org.openxds.exceptions.SemanticException;

public interface IBinaryTree<E>
{
	/**
	 * Add a new root to the tree containing the element e.
	 * 
	 * @param e
	 * @return the position associated with the new tree node.
	 * @throws SemanticException, if the tree already contains a root node.
	 */
	public IPosition<E> addRoot( E e ) throws SemanticException;

	/**
	 * Add a left child to position.
	 * 
	 * @param e
	 * @return the position associated with the new tree node.
	 * @throws SemanticException, if the position already has a left child.
	 */
	public IPosition<E> addLeft( IPosition<E> p, E e ) throws SemanticException;

	/**
	 * Add a right child to position.
	 * 
	 * @param e
	 * @return the position associated with the new tree node.
	 * @throws SemanticException, if the position already has a right child.
	 */
	public IPosition<E> addRight( IPosition<E> p, E e ) throws SemanticException;

	/**
	 * Adds the passed tree, t, as the left subtree of p.
	 * 
	 * @param p
	 * @param t 
	 * @return the new position of the old root of the subtree.
	 * @throws SemanticException
	 */
	public IPosition<E> addLeftSubtree( IPosition<E> p, IBinaryTree<E> t ) throws SemanticException;
	
	/**
	 * Adds the passed tree, t, as the right subtree of p.
	 * 
	 * @param p
	 * @param t
	 * @return the new position of the old root of the subtree.
	 * @throws SemanticException
	 */
	public IPosition<E> addRightSubtree( IPosition<E> p, IBinaryTree<E> t ) throws SemanticException;
	
	/**
	 * Remove the tree node pointed to by position.
	 * @param p, the position to remove.
	 * @return e, the element stored at the position.
	 * @throws SemanticException, if the position has a child.
	 */
	public E remove( IPosition<E> p );

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
	public IBinaryTree<E> removeAsTree( IPosition<E> p );
	
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
	 * @param p
	 * @return the left child of p.
	 * @throws NoSuchElementException, if no left child exists.
	 */
	public IPosition<E> left( IPosition<E> p ) throws NoSuchElementException;
	
	/**
	 * @param p
	 * @return the right child of p.
	 * @throws NoSuchElementException, if no right child exists.
	 */
	public IPosition<E> right( IPosition<E> p ) throws NoSuchElementException;

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
	 * @return true, if p has a left child; false otherwise.
	 */
	public boolean hasLeft( IPosition<E> p );
	
	/**
	 * @param p
	 * @return true, if p has a right child; false otherwise.
	 */
	public boolean hasRight( IPosition<E> p );

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
