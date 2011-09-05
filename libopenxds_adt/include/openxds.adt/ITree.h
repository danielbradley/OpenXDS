#ifndef OPENXDS_ADT_ITREE_H
#define OPENXDS_ADT_ITREE_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class ITree : public openxds::Interface
{
public:
	virtual       ~ITree() {}

	virtual       IPosition<E>*      addRoot( E* value ) = 0;
	virtual       IPosition<E>*     addChild( IPosition<E>& p, E* value ) = 0;
	virtual       IPosition<E>*   addSubtree( IPosition<E>& p, ITree* value ) = 0;
	virtual       E*                 replace( IPosition<E>& p, E* value ) = 0;
	virtual       E*                  remove( IPosition<E>* p ) = 0;
	virtual       ITree<E>*     removeAsTree( IPosition<E>* p ) = 0;

	virtual       IPosition<E>*         root() const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IPosition<E>*       parent( IPosition<E>& p ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IPIterator<E>*    children( IPosition<E>& p ) const = 0;
	virtual       bool                isRoot( IPosition<E>& p ) const = 0;
	virtual       bool            isInternal( IPosition<E>& p ) const = 0;
	virtual       bool            isExternal( IPosition<E>& p ) const = 0;
	virtual       bool             hasParent( IPosition<E>& p ) const = 0;
	virtual       bool               isEmpty() const = 0;
	virtual       int                   size() const = 0;
}; 

};};

#endif
