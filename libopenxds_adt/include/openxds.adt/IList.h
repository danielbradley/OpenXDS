#ifndef OPENXDS_ADT_ILIST_H
#define OPENXDS_ADT_ILIST_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.exceptions/IndexOutOfBoundsException.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class IList : public openxds::Interface
{
public:
	virtual                           ~IList() {}

	// List
	virtual       IPosition<E>*  insertFirst(       E* e )                                                                       = 0;
	virtual       IPosition<E>*   insertLast(       E* e )                                                                       = 0;
	virtual       IPosition<E>* insertBefore(       IPosition<E>& p, E* e )                                                      = 0;
	virtual       IPosition<E>*  insertAfter(       IPosition<E>& p, E* e )                                                      = 0;
	virtual       E*                 replace(       IPosition<E>& p, E* e )                                                      = 0;
	virtual       E*                  remove(       IPosition<E>* p )                                                            = 0;

	virtual       IPosition<E>*        first()                              throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IPosition<E>*         last()                              throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IPosition<E>*         prev(       IPosition<E>& p )       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IPosition<E>*     previous(       IPosition<E>& p )       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IPosition<E>*         next(       IPosition<E>& p )       throw (openxds::exceptions::NoSuchElementException*) = 0;

	virtual       IIterator<E>*     elements()                                                                                   = 0;
	virtual       IPIterator<E>*   positions()                                                                                   = 0;

	virtual const IPosition<E>*        first()                        const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPosition<E>*         last()                        const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPosition<E>*         prev( const IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPosition<E>*     previous( const IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPosition<E>*         next( const IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*) = 0;

	virtual const IIterator<E>*     elements()                        const                                                      = 0;
	virtual const IPIterator<E>*   positions()                        const                                                      = 0;

	// Common
	virtual long                  size() const = 0;
	virtual bool               isEmpty() const = 0;
}; 

};};

#endif

