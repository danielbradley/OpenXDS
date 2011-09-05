#ifndef OPENXDS_ADT_STD_TREE_H
#define OPENXDS_ADT_STD_TREE_H

#include <openxds.adt/IPosition.h>
#include <openxds.adt/ITree.h>
#include <openxds.adt.std/PIterator.h>
#include <openxds.adt.std/Position.h>

#include <openxds/Object.h>
#include <openxds.exceptions/NoSuchElementException.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/ITree.h>
#include <openxds.core.adt/IPIterator.h>
#include <openxds.core.adt/IPosition.h>
#include <openxds.core.adt.std.h>
#include <openxds.core.adt.std/StdADTFactory.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

void* createTree();

template <class E>
class Tree : public openxds::Object, public openxds::adt::ITree<E>
{
public:
	Tree()
	{
		this->t = openxds::core::adt::std::StdADTFactory_createTree();
	}
	
	virtual ~Tree()
	{
		if ( this->t )
		{
			if ( !this->isEmpty() )
			{
				IPosition<E>* p = this->root();
				this->deleteObjects( p );
			}
			this->t->free( this->t );
		}
	}

	virtual IPosition<E>* addRoot( E* value )
	{
		return new Position<E>( this->t->addRoot( this->t, value ) );
	}

	virtual IPosition<E>* addChild( IPosition<E>& p, E* value )
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();
		return new Position<E>( this->t->addChild( this->t, core, value ) );
	}
	
	virtual IPosition<E>* addSubtree( IPosition<E>& p, ITree<E>* itree )
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		Tree<E>* tree = dynamic_cast<Tree<E>*>( itree );
		openxds::core::adt::ITree* subtree = tree->t;
		tree->t = NULL;
		delete tree;

		return new Position<E>( this->t->addSubtree( this->t, core, subtree ) );
	}

	virtual E* replace( IPosition<E>& p, E* value )
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();
		
		return static_cast<E*>( this->t->replace( this->t, core, value ) );
	}

	virtual E* remove( IPosition<E>* p )
	{
		void* e = NULL;
		{
			Position<E>* posn = dynamic_cast<Position<E>*>( p );
			{
				const openxds::core::adt::IPosition* core = posn->getCorePosition();
				e = (void*) this->t->remove( this->t, core );
			}
			delete posn;
		}
		return static_cast<E*>( e );
	}

	virtual ITree<E>* removeAsTree( IPosition<E>* p )
	{
		Position<E>* posn = dynamic_cast<Position<E>*>( p );
		const openxds::core::adt::IPosition* core = posn->getCorePosition();
		delete posn;

		openxds::core::adt::ITree* itree = this->t->removeAsTree( this->t, core );
		
		Tree<E>* tree = new Tree<E>();
		tree->t->free( tree->t );
		tree->t = itree;
		
		return tree;
	}

	virtual IPosition<E>* root() const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() )
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
		const openxds::core::adt::IPosition* core = this->t->root( this->t ); 
		return new Position<E>( core );
	}

	virtual IPosition<E>* parent( IPosition<E>& p ) const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		if ( ! core )
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
		return new Position<E>( this->t->parent( this->t, core ) );
	}

	virtual IPIterator<E>* children( IPosition<E>& p ) const
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return new PIterator<E>( this->t->children( this->t, core ) );
	}

	virtual bool isRoot( IPosition<E>& p ) const
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->isRoot( this->t, core );
	}

	virtual bool isInternal( IPosition<E>& p ) const
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->isInternal( this->t, core );
	}

	virtual bool isExternal( IPosition<E>& p ) const
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->isExternal( this->t, core );
	}

	virtual bool hasParent( IPosition<E>& p ) const
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->hasParent( this->t, core );
	}

	virtual bool isEmpty() const
	{
		return this->t->isEmpty( this->t );
	}

	virtual int size() const
	{
		return this->t->size( this->t );
	}

private:
	void deleteObjects( IPosition<E>* p )
	{
		IPIterator<E>* it = this->children( *p );
		while ( it->hasNext() )
		{
			IPosition<E>* px = it->next();
			this->deleteObjects( px );
		}
		delete it;
		delete this->remove( p );
	}

	openxds::core::adt::ITree* t;
}; 

};};};

#endif
