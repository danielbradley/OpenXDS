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
		this->r = NULL;
	}
	
	virtual ~Tree()
	{
		delete this->r;
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

	virtual long size() const
	{
		return this->t->size( this->t );
	}

	virtual IPosition<E>* addRoot( E* value )
	{
		delete this->r;
		       this->r = new Position<E>( this->t->addRoot( this->t, value ) );
		return this->r->copy();
	}

	virtual IPosition<E>* addChild( IPosition<E>& p, E* value )
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();
		return new Position<E>( this->t->addChild( this->t, core, value ) );
	}

	virtual IPosition<E>* insertChildAt( IPosition<E>& p, E* value, long i )
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();
		return new Position<E>( this->t->insertChildAt( this->t, core, value, i ) );
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

	virtual void copyChildren( ITree<E>& target, IPosition<E>& t, const ITree<E>& source, const IPosition<E>& s ) const
	{
		const openxds::adt::IPIterator<E>* it = source.children( s );
		while ( it->hasNext() )
		{
			const openxds::adt::IPosition<E>* sc = it->next();
			{
				const E& element = sc->getElement();
				E* copy = new E( element );
				openxds::adt::IPosition<E>* tc = target.addChild( t, copy );
				{
					copyChildren( target, *tc, source, *sc );
				}
				delete tc;
			}
			delete sc;
		}
		delete it;
	} 

	virtual ITree<E>* copyAsTree( const IPosition<E>& p ) const
	{
		ITree<E>* tree = new Tree<E>();
		{
			const E& value1 = p.getElement();
			E* value2 = new E( value1 );
			IPosition<E>* root = tree->addRoot( value2 );
			{
				copyChildren( *tree, *root, *this, p );
			}
			delete root;
		}
		return tree;
	}

	virtual ITree<E>* copyAsTree() const
	{
		return this->copyAsTree( this->getRoot() );
	}

	virtual void swapSubtrees( IPosition<E>& p, ITree<E>& tree, IPosition<E>& p2 )
	{
		const openxds::core::adt::IPosition* a = dynamic_cast<Position<E>&>( p  ).getCorePosition();
		const openxds::core::adt::IPosition* b = dynamic_cast<Position<E>&>( p2 ).getCorePosition();
		
		Tree<E>& _tree = dynamic_cast<Tree<E>&>( tree );
		
		this->t->swapSubtrees( this->t, a, _tree.t, b );
	}

	virtual IPosition<E>* root()
	throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() )
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
		const openxds::core::adt::IPosition* core = this->t->root( this->t ); 
		return new Position<E>( core );
	}

	virtual IPosition<E>* parent( IPosition<E>& p )
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

	virtual IPosition<E>* child( IPosition<E>& p, long i )
	throw (openxds::exceptions::NoSuchElementException*)
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core  = posn.getCorePosition();
		const openxds::core::adt::IPosition* child = this->t->child( this->t, core, i );
		
		if ( child )
		{
			return new Position<E>( child );
		}
		else
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
	}

	virtual IPIterator<E>* children( IPosition<E>& p )
	{
		Position<E>& posn = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return new PIterator<E>( this->t->children( this->t, core ) );
	}

	virtual IPosition<E>& getRoot()
	throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() )
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
		return *this->r;
	}

	virtual const IPosition<E>& getRoot() const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() )
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
		return *this->r;
	}

	virtual const IPosition<E>* root() const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() )
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
		const openxds::core::adt::IPosition* core = this->t->root( this->t ); 
		return new Position<E>( core );
	}

	virtual const IPosition<E>* parent( const IPosition<E>& p ) const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		if ( ! core )
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
		return new Position<E>( this->t->parent( this->t, core ) );
	}

	virtual const IPosition<E>* child( const IPosition<E>& p, long i ) const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core  = posn.getCorePosition();
		const openxds::core::adt::IPosition* child = this->t->child( this->t, core, i );
		
		if ( child )
		{
			return new Position<E>( child );
		}
		else
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
	}

	virtual const IPIterator<E>* children( const IPosition<E>& p ) const
	{
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return new PIterator<E>( this->t->children( this->t, core ) );
	}

	virtual bool isRoot( const IPosition<E>& p ) const
	{
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->isRoot( this->t, core );
	}

	virtual bool isInternal( const IPosition<E>& p ) const
	{
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->isInternal( this->t, core );
	}

	virtual bool isExternal( const IPosition<E>& p ) const
	{
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->isExternal( this->t, core );
	}

	virtual bool hasParent( const IPosition<E>& p ) const
	{
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->hasParent( this->t, core );
	}

	virtual bool hasChild( const IPosition<E>& p, long i ) const
	{
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->hasChild( this->t, core, i );
	}

	virtual bool isEmpty() const
	{
		return this->t->isEmpty( this->t );
	}

	virtual long nrChildren( const IPosition<E>& p ) const
	{
		fprintf( stdout, "Tree:nrChildren()\n" );
	
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->nrChildren( this->t, core );
	}

	virtual long nrOfChild( const IPosition<E>& p ) const
	{
		const Position<E>& posn = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = posn.getCorePosition();

		return this->t->nrOfChild( this->t, core );
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
	IPosition<E>* r;
}; 

};};};

#endif
