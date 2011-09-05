#ifndef OPENXDS_ADT_ISEQUENCE_H
#define OPENXDS_ADT_ISEQUENCE_H

#include "openxds.adt.h"
#include "openxds.adt/IList.h"
#include <openxds.exceptions/IndexOutOfBoundsException.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class ISequence : public openxds::adt::IList<E>
{
public:
	virtual ~ISequence() {}

	// Deque
	virtual void              addFirst( E* e ) = 0;
	virtual void               addLast( E* e ) = 0;
	virtual E*             removeFirst() throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual E*              removeLast() throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual E&                getFirst() const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual E&                 getLast() const throw (openxds::exceptions::NoSuchElementException*) = 0;

	// List
	virtual IPosition<E>*  insertFirst( E* e ) = 0;
	virtual IPosition<E>*   insertLast( E* e ) = 0;
	virtual IPosition<E>* insertBefore( IPosition<E>& p, E* e ) = 0;
	virtual IPosition<E>*  insertAfter( IPosition<E>& p, E* e ) = 0;
	virtual E*                 replace( IPosition<E>& p, E* e ) = 0;
	virtual E*                  remove( IPosition<E>* p ) = 0;

	virtual IPosition<E>*        first() const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual IPosition<E>*         last() const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual IPosition<E>*         prev( IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual IPosition<E>*     previous( IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual IPosition<E>*         next( IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*) = 0;

	virtual IPIterator<E>*   positions() const = 0;

	// Vector
	virtual void                   add( int rank, E* e ) throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	virtual E*                     set( int rank, E* e ) throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	virtual E*              removeFrom( int rank )       throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	virtual E&                     get( int rank ) const throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;

	// Bridging
	virtual int                 rankOf( IPosition<E>& p ) const = 0;
	virtual IPosition<E>*       atRank( int rank ) const throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	
	// Common
	virtual int                   size() const = 0;
	virtual bool               isEmpty() const = 0;
}; 

};};

#endif
