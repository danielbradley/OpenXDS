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
	virtual       void              addFirst(       E* e )                                                                                = 0;
	virtual       void               addLast(       E* e )                                                                                = 0;
	virtual       E*             removeFirst()                                    throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual       E*              removeLast()                                    throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual       E&                getFirst()                                    throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual       E&                 getLast()                                    throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual const E&                getFirst()                              const throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual const E&                 getLast()                              const throw (openxds::exceptions::NoSuchElementException*)    = 0;

	// List
	virtual       IPosition<E>*  insertFirst(       E* e )                                                                                = 0;
	virtual       IPosition<E>*   insertLast(       E* e )                                                                                = 0;
	virtual       IPosition<E>* insertBefore(       IPosition<E>& p, E* e )                                                               = 0;
	virtual       IPosition<E>*  insertAfter(       IPosition<E>& p, E* e )                                                               = 0;
	virtual       E*                 replace(       IPosition<E>& p, E* e )                                                               = 0;
	virtual       E*                  remove(       IPosition<E>* p )                                                                     = 0;

	virtual       IPosition<E>*        first()                                    throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual       IPosition<E>*         last()                                    throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual       IPosition<E>*         prev(       IPosition<E>& p )             throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual       IPosition<E>*     previous(       IPosition<E>& p )             throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual       IPosition<E>*         next(       IPosition<E>& p )             throw (openxds::exceptions::NoSuchElementException*)    = 0;

	virtual       IIterator<E>*     elements()                                                                                            = 0;
	virtual       IPIterator<E>*   positions()                                                                                            = 0;

	virtual const IPosition<E>*        first()                              const throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual const IPosition<E>*         last()                              const throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual const IPosition<E>*         prev( const IPosition<E>& p )       const throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual const IPosition<E>*     previous( const IPosition<E>& p )       const throw (openxds::exceptions::NoSuchElementException*)    = 0;
	virtual const IPosition<E>*         next( const IPosition<E>& p )       const throw (openxds::exceptions::NoSuchElementException*)    = 0;

	virtual const IIterator<E>*     elements()                              const                                                         = 0;
	virtual const IPIterator<E>*   positions()                              const                                                         = 0;

	// Vector
	virtual       void                   add(      long rank, E* e )              throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	virtual       E*                     set(      long rank, E* e )              throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	virtual       E*              removeFrom(      long rank )                    throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	virtual       E&                     get(      long rank )                    throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	virtual const E&                     get(      long rank )              const throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	virtual bool                         has(      long rank )              const                                                         = 0;

	// Bridging
	virtual       long                rankOf( const IPosition<E>& p )       const                                                         = 0;
	virtual       IPosition<E>*       atRank(      long rank )                    throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	virtual const IPosition<E>*       atRank(      long rank )              const throw (openxds::exceptions::IndexOutOfBoundsException*) = 0;
	
	// Common
	virtual       long                  size()                              const                                                         = 0;
	virtual       bool               isEmpty()                              const                                                         = 0;
}; 

};};

#endif

