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

	virtual       long                  size()                                const                                                      = 0;
	virtual       IPosition<E>*       addRoot(       E* value )                                          = 0;
	virtual       IPosition<E>*      addChild(       IPosition<E>& p, E*        value )                  = 0;
	virtual       IPosition<E>* insertChildAt(       IPosition<E>& p, E*        value, long i )          = 0;
	virtual       IPosition<E>*    addSubtree(       IPosition<E>& p, ITree<E>* value )                  = 0;
	virtual       E*                  replace(       IPosition<E>& p, E*        value )                  = 0;
	virtual       E*                   remove(       IPosition<E>* p  )                                  = 0;
	virtual       ITree<E>*      removeAsTree(       IPosition<E>* p  )                                  = 0;
	virtual       ITree<E>*        copyAsTree( const IPosition<E>& p  ) const                            = 0; 
	virtual       ITree<E>*        copyAsTree()                         const                            = 0; 
	virtual       void           swapSubtrees(       IPosition<E>& p, ITree<E>& tree, IPosition<E>& p2 ) = 0;

	virtual       IPosition<E>*         root()                                      throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IPosition<E>*       parent(       IPosition<E>& p )               throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IPosition<E>*        child(       IPosition<E>& p, long i )       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IPIterator<E>*    children(       IPosition<E>& p )                                                                    = 0;

	virtual       IPosition<E>&      getRoot()                                      throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPosition<E>&      getRoot()                                const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPosition<E>*         root()                                const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPosition<E>*       parent( const IPosition<E>& p )         const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPosition<E>*        child( const IPosition<E>& p, long i ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPIterator<E>*    children( const IPosition<E>& p )         const                                                      = 0;
	virtual       bool                isRoot( const IPosition<E>& p )         const                                                      = 0;
	virtual       bool            isInternal( const IPosition<E>& p )         const                                                      = 0;
	virtual       bool            isExternal( const IPosition<E>& p )         const                                                      = 0;
	virtual       bool             hasParent( const IPosition<E>& p )         const                                                      = 0;
	virtual       bool              hasChild( const IPosition<E>& p, long i ) const                                                      = 0;
	virtual       bool               isEmpty()                                const                                                      = 0;
	virtual       long            nrChildren( const IPosition<E>& p )         const                                                      = 0;
	virtual       long             nrOfChild( const IPosition<E>& p )         const                                                      = 0;
}; 

};};

#endif

