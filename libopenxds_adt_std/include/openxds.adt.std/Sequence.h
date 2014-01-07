#ifndef OPENXDS_ADT_STD_SEQUENCE_H
#define OPENXDS_ADT_STD_SEQUENCE_H

#include <openxds.adt.std.h>
#include <openxds.adt.std/Iterator.h>
#include <openxds.adt.std/Position.h>
#include <openxds.adt.std/PIterator.h>
#include <openxds.adt/IPosition.h>
#include <openxds.adt/ISequence.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds/Object.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/IPosition.h>
#include <openxds.core.adt/ISequence.h>
#include <openxds.core.adt/IValue.h>
#include <openxds.core.adt.std.h>
#include <openxds.core.adt.std/StdADTFactory.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

void* createSequence();

template <class E>
class Sequence : public openxds::Object, public openxds::adt::ISequence<E>
{
public:
    Sequence()
	{
		this->_seq = openxds::core::adt::std::StdADTFactory_createSequence();
	}

	virtual ~Sequence()
	{
		while ( ! this->isEmpty() )
		{
			delete this->removeFirst();
		}
		this->_seq->free( this->_seq );
		this->_seq = null;
	}
	
	virtual void addFirst( E* e )
	{
		this->_seq->addFirst( this->_seq, e );
	}

	virtual void addLast( E* e )
	{
		this->_seq->addLast( this->_seq, e );
	}

	virtual E* removeFirst() throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();
	
		return static_cast<E*>( this->_seq->removeFirst( this->_seq ) );
	}
	
	virtual E* removeLast() throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();

		return static_cast<E*>( this->_seq->removeLast( this->_seq ) );
	}
	
	virtual E& getFirst() throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();

		const E* e= static_cast<const E*>( this->_seq->getFirst( this->_seq ) ); 
		E* e2     = const_cast<E*>( e );
		return *e2;
	}

	virtual E& getLast() throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();

		const E* e= static_cast<const E*>( this->_seq->getLast( this->_seq ) ); 
		E* e2     = const_cast<E*>( e );
		return *e2;
	}

	virtual const E& getFirst() const throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();

		const E* e= static_cast<const E*>( this->_seq->getFirst( this->_seq ) ); 
		E* e2     = const_cast<E*>( e );
		return *e2;
	}

	virtual const E& getLast() const throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();

		const E* e= static_cast<const E*>( this->_seq->getLast( this->_seq ) ); 
		E* e2     = const_cast<E*>( e );
		return *e2;
	}

	virtual IPosition<E>* insertFirst( E* e )
	{
		const openxds::core::adt::IPosition* p = this->_seq->insertFirst( this->_seq, e );
		return new Position<E>( p );
	}
	
	virtual IPosition<E>* insertLast( E* e )
	{
		const openxds::core::adt::IPosition* p = this->_seq->insertLast( this->_seq, e );
		return new Position<E>( p );
	}

	virtual IPosition<E>* insertBefore( IPosition<E>& p, E* e )
	{
		Position<E>& _p = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* p2 = this->_seq->insertBefore( this->_seq, _p.getCorePosition(), e );

		return new Position<E>( p2 );
	}

	virtual IPosition<E>* insertAfter( IPosition<E>& p, E* e )
	{
		Position<E>& _p = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* p2 = this->_seq->insertAfter( this->_seq, _p.getCorePosition(), e );

		return new Position<E>( p2 );
	}

	virtual E* replace( IPosition<E>& p, E* e )
	{
		Position<E>& _p = dynamic_cast<Position<E>&>( p );
		return static_cast<E*>( this->_seq->replace( this->_seq, _p.getCorePosition(), e ) );
	}

	virtual E* remove( IPosition<E>* p )
	{
		Position<E>* _p = dynamic_cast<Position<E>*>( p );
		E* e = static_cast<E*>( this->_seq->remove( this->_seq, _p->getCorePosition() ) );
		delete p;
		return e;
	}

	virtual IPosition<E>* first() throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();

		openxds::core::adt::IPosition* p = const_cast<openxds::core::adt::IPosition*>( this->_seq->first( this->_seq ) );
		return new Position<E>( p );
	}

	virtual IPosition<E>* last() throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();

		const openxds::core::adt::IPosition* p = this->_seq->last( this->_seq );
		return new Position<E>( p );
	}

	virtual IPosition<E>* prev( IPosition<E>& p ) throw (openxds::exceptions::NoSuchElementException*)
	{
		Position<E>& _p = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = _p.getCorePosition(); 
		const openxds::core::adt::IPosition* p2   = this->_seq->prev( this->_seq, core );

		if ( ! p2 ) throw new openxds::exceptions::NoSuchElementException();

		return new Position<E>( p2 );
	}

	virtual IPosition<E>* previous( IPosition<E>& p ) throw (openxds::exceptions::NoSuchElementException*)
	{
		return this->prev( p );
	}
	
	virtual IPosition<E>* next( IPosition<E>& p ) throw (openxds::exceptions::NoSuchElementException*)
	{
		Position<E>& _p = dynamic_cast<Position<E>&>( p );
		const openxds::core::adt::IPosition* core = _p.getCorePosition(); 
		const openxds::core::adt::IPosition* p2   = this->_seq->next( this->_seq, core );

		if ( ! p2 ) throw new openxds::exceptions::NoSuchElementException();

		return new Position<E>( p2 );
	}

	virtual IIterator<E>* elements()
	{
		return new Iterator<E>( this->_seq->elements( this->_seq ) );
	}

	virtual IPIterator<E>* positions()
	{
		return new PIterator<E>( this->_seq->positions( this->_seq ) );
	}

	virtual const IPosition<E>* first() const throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();

		const openxds::core::adt::IPosition* p = this->_seq->first( this->_seq );
		return new Position<E>( p );
	}

	virtual const IPosition<E>* last() const throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( this->isEmpty() ) throw new openxds::exceptions::NoSuchElementException();

		const openxds::core::adt::IPosition* p = this->_seq->last( this->_seq );
		return new Position<E>( p );
	}

	virtual const IPosition<E>* prev( const IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*)
	{
		const Position<E>& _p = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = _p.getCorePosition(); 
		const openxds::core::adt::IPosition* p2   = this->_seq->prev( this->_seq, core );

		if ( ! p2 ) throw new openxds::exceptions::NoSuchElementException();

		return new Position<E>( p2 );
	}

	virtual const IPosition<E>* previous( const IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*)
	{
		return this->prev( p );
	}
	
	virtual const IPosition<E>* next( const IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*)
	{
		const Position<E>& _p = dynamic_cast<const Position<E>&>( p );
		const openxds::core::adt::IPosition* core = _p.getCorePosition(); 
		const openxds::core::adt::IPosition* p2   = this->_seq->next( this->_seq, core );

		if ( ! p2 ) throw new openxds::exceptions::NoSuchElementException();

		return new Position<E>( p2 );
	}

	virtual const IIterator<E>* elements() const
	{
		return new Iterator<E>( this->_seq->elements( this->_seq ) );
	}

	virtual const IPIterator<E>* positions() const
	{
		return new PIterator<E>( this->_seq->positions( this->_seq ) );
	}

	virtual void add( long rank, E* e ) throw (openxds::exceptions::IndexOutOfBoundsException*)
	{
		long size = this->_seq->size( this->_seq );
		if ( (rank < 0) || (size < rank))
		{
			delete e;
			throw new openxds::exceptions::IndexOutOfBoundsException();
		}
	
		this->_seq->add( this->_seq, rank, e );
	}

	virtual E* set( long rank, E* e ) throw (openxds::exceptions::IndexOutOfBoundsException*)
	{
		long size = this->_seq->size( this->_seq );
		if ( (rank < 0) || (size <= rank))
		{
			delete e;
			throw new openxds::exceptions::IndexOutOfBoundsException();
		}
	
		return const_cast<E*>( static_cast<E*>( this->_seq->set( this->_seq, rank, e ) ) );
	}

	virtual E* removeFrom( long rank ) throw (openxds::exceptions::IndexOutOfBoundsException*)
	{
		long size = this->_seq->size( this->_seq );
		if ( (rank < 0) || (size <= rank))
			throw new openxds::exceptions::IndexOutOfBoundsException();

		E* e = const_cast<E*>( static_cast<E*>( this->_seq->removeFrom( this->_seq, rank ) ) );
		
		if ( !e ) throw new openxds::exceptions::IndexOutOfBoundsException();
	
		return e;
	}

	virtual E& get( long rank ) throw (openxds::exceptions::IndexOutOfBoundsException*)
	{
		long size = this->_seq->size( this->_seq );
		if ( (rank < 0) || (size <= rank))
			throw new openxds::exceptions::IndexOutOfBoundsException();

		E* e = const_cast<E*>( static_cast<const E*>( this->_seq->get( this->_seq, rank ) ) );

		if ( !e ) throw new openxds::exceptions::IndexOutOfBoundsException();
	
		return *e;
	}

	virtual const E& get( long rank ) const throw (openxds::exceptions::IndexOutOfBoundsException*)
	{
		long size = this->_seq->size( this->_seq );
		if ( (rank < 0) || (size <= rank))
			throw new openxds::exceptions::IndexOutOfBoundsException();

		E* e = const_cast<E*>( static_cast<const E*>( this->_seq->get( this->_seq, rank ) ) );

		if ( !e ) throw new openxds::exceptions::IndexOutOfBoundsException();
	
		return *e;
	}

	virtual bool has( long rank ) const
	{
		return (rank < this->size() );
	}

	virtual long rankOf( const IPosition<E>& p ) const
	{
		const Position<E>& _p = dynamic_cast<const Position<E>&>( p );
		return this->_seq->rankOf( this->_seq, _p.getCorePosition() );
	}

	virtual IPosition<E>* atRank( long rank ) throw (openxds::exceptions::IndexOutOfBoundsException*)
	{
		const openxds::core::adt::IPosition* p = this->_seq->atRank( this->_seq, rank );
		
		if ( !p ) throw new openxds::exceptions::IndexOutOfBoundsException();
	
		return new Position<E>( p );
	}

	virtual const IPosition<E>* atRank( long rank ) const throw (openxds::exceptions::IndexOutOfBoundsException*)
	{
		const openxds::core::adt::IPosition* p = this->_seq->atRank( this->_seq, rank );
		
		if ( !p ) throw new openxds::exceptions::IndexOutOfBoundsException();
	
		return new Position<E>( p );
	}

	virtual bool isEmpty() const
	{
		return this->_seq->isEmpty( this->_seq );
	}
	
	virtual long size() const
	{
		return this->_seq->size( this->_seq );
	}
	
private:
	openxds::core::adt::ISequence* _seq;
}; 

};};};

#endif
