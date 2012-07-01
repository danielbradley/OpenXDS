.	ITree (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/ITree.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/ITree.h~
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
~
!

..		Method Summary

~html~
<table>
<thead>
<tr>
	<th>Returns</th><th>Method-name</th><th colspan='2'>Parameters</th><th>Throws</th>
</tr>
</thead>
<tbody>

<tr><td><b>IPosition(E)* </b></td><td><a href='#addRoot'     >addRoot     </a></td><td><b>E*           </b> element </td>                                                             </tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#addChild'    >addChild    </a></td><td><b>IPosition(E)&</b> p       </td><td><b>E*       </b> element</td>                            </tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#addSubtree'  >addSubtree  </a></td><td><b>IPosition(E)&</b> p       </td><td><b>ITree(E)*</b> lower  </td>                            </tr>
<tr><td><b>E*            </b></td><td><a href='#replace'     >replace     </a></td><td><b>IPosition(E)&</b> p       </td><td><b>E*       </b> element</td>                            </tr>
<tr><td><b>E*            </b></td><td><a href='#remove'      >remove      </a></td><td><b>IPosition(E)*</b> p       </td>                                                             </tr>
<tr><td><b>ITree(E)*     </b></td><td><a href='#removeAsTree'>removeAsTree</a></td><td><b>IPosition(E)*</b> p       </td>                                                             </tr>
<tr><td><b>ITree(E)*     </b></td><td><a href='#copyAsTree'  >copyAsTree  </a></td><td><b>IPosition(E)*</b> p       </td>                                                             </tr>

<tr><td><b>IPosition(E)* </b></td><td><a href='#root'        >root        </a></td><td>                           </td><td>                       </td><td>NoSuchElementException*</td></tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#parent'      >parent      </a></td><td><b>IPosition(E)&</b> p     </td><td>                       </td><td>NoSuchElementException*</td></tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#child'       >child       </a></td><td><b>IPosition(E)&</b> p     </td><td><b>long</b> index      </td><td>NoSuchElementException*</td></tr>
<tr><td><b>IPIterator(E)*</b></td><td><a href='#children'    >children    </a></td><td><b>IPosition(E)&</b> p     </td>                                                               </tr>

<tr><td><b>bool          </b></td><td><a href='#isRoot'      >isRoot      </a></td><td><b>IPosition(E)&</b> p     </td>                                                               </tr>
<tr><td><b>bool          </b></td><td><a href='#isInternal'  >isInternal  </a></td><td><b>IPosition(E)&</b> p     </td>                                                               </tr>
<tr><td><b>bool          </b></td><td><a href='#isExternal'  >isExternal  </a></td><td><b>IPosition(E)&</b> p     </td>                                                               </tr>
<tr><td><b>bool          </b></td><td><a href='#hasParent'   >hasParent   </a></td><td><b>IPosition(E)&</b> p     </td>                                                               </tr>
<tr><td><b>bool          </b></td><td><a href='#hasChild'    >hasChild    </a></td><td><b>IPosition(E)&</b> p     </td><td><b>long</b> i          </td>                               </tr>
<tr><td><b>bool          </b></td><td><a href='#isEmpty'     >isEmpty     </a></td>                                                                                                   </tr>
<tr><td><b>long          </b></td><td><a href='#nrChildren'  >nrChildren  </a></td><td><b>IPosition(E)&</b> p     </td>                                                               </tr>
<tr><td><b>long          </b></td><td><a href='#size'        >size        </a></td>                                                                                                   </tr>

</tbody>
</table>
~

..		Methods

~html~
<a name='addRoot'></a>
<hr>
~

...			addRoot

~
IPosition<E>* addRoot( E* element );
~

Parameters
|
/element/, to be stored in the root of the tree.
|

Returns
|
A new position that can directly accesss the root position of the tree.
|


~html~
<a name='addChild'></a>
<hr>
~

...			addChild

~
IPosition<E>* addChild( IPosition<E>& p, E* element );
~

Parameters
|
/p/, a position referencing the node the element should be made a child of;

/element/, to be stored in of the tree.
|

Returns
|
A new position that can directly accesss the root position of the tree.
|


~html~
<a name='addSubtree'></a>
<hr>
~

...			addSubtree

~
IPosition<E>* addSubtree( IPosition<E>& p, ITree<E>* aTree );
~

Parameters
|
/p/, a position referencing the node that the root of the tree should be made a child of;

/aTree/, to be added as a subtree of this tree.
|

Returns
|
A new position referencing the root node of the added subtree.
|


~html~
<a name='replace'></a>
<hr>
~

...			replace

~
E* replace( IPosition<E>& p, E* element );
~

Parameters
|
/p/, a position (node) of the tree;

/element/, to be stored in the tree at position /p/.
|

Returns
|
The element that was previously stored at position /p/.
|


~html~
<a name='remove'></a>
<hr>
~

...			remove

~
E* remove( IPosition<E>* p );
~

Parameters
|
/p/, a position referencing a left node of the tree.
|

Returns
|
The element that was previously stored at position /p/.
|


~html~
<a name='removeAsTree'></a>
<hr>
~

...			removeAsTree

~
ITree<E>* removeAsTree( IPosition<E>* p );
~

Parameters
|
/p/, a position (node) of the tree.
|

Returns
|
A new tree correspond to the previous subtree whose root was /p/.
|


~html~
<a name='root'></a>
<hr>
~

...			root

~
IPosition<E>* root() throws NoSuchElementException;
~

Returns
|
A new position that corresponds to the root node of the tree.
|

Throws
|
/NoSuchElementException/, if the tree is empty.
|


~html~
<a name='parent'></a>
<hr>
~

...			parent

~
IPosition<E>* parent( IPosition<E>& ) throws NoSuchElementException;
~

Parameters
|
/p/, a position (node) of the tree.
|

Returns
|
A new position that corresponds to the parent node of /p/.
|

Throws
|
/NoSuchElementException/, if /p/ is the root of the tree.
|


~html~
<a name='child'></a>
<hr>
~

...			child

~
IPosition<E>* child( IPosition<E>&, long i ) throws NoSuchElementException;
~

Parameters
|
/p/, the parent node of the child;

/i/, an number specifying a child of /p/.
|

Returns
|
A new position that corresponds to the /i/ the child of /p/.
|

Throws
|
/NoSuchElementException/, if /p/ doesn't have an /i/ th child.
|


~html~
<a name='children'></a>
<hr>
~

...			children

~
IPIterator<E>* children( IPosition<E>& p );
~

Parameters
|
/p/, a position (node) of the tree.
|

Returns
|
A (possibly empty) position iterator that contains the positions of all children of /p/.
|


~html~
<a name='isRoot'></a>
<hr>
~

...			isRoot

~
bool isRoot( IPosition<E>& p );
~

Parameters
|
/p/, a position (node) of the tree.
|

Returns
|
TRUE, if /p/ is the root of the tree; otherwise FALSE.
|


~html~
<a name='isInternal'></a>
<hr>
~

...			isInternal

~
bool isInternal( IPosition<E>& p );
~

Parameters
|
/p/, a position (node) of the tree.
|

Returns
|
TRUE, if /p/ is an internal node of the tree (has children); otherwise FALSE.
|


~html~
<a name='isExternal'></a>
<hr>
~

...			isExternal

~
bool isExternal( IPosition<E>& p );
~

Parameters
|
/p/, a position (node) of the tree.
|

Returns
|
TRUE, if /p/ is an external node of the tree (has no children); otherwise FALSE.
|


~html~
<a name='hasParent'></a>
<hr>
~

...			hasParent

~
bool hasParent( IPosition<E>& p );
~

Parameters
|
/p/, a position (node) of the tree.
|

Returns
|
TRUE, if /p/ is not the root node; otherwise FALSE.
|


~html~
<a name='hasChild'></a>
<hr>
~

...			hasChild

~
bool hasChild( IPosition<E>& p, long i );
~

Parameters
|
/p/, a position (node) of the tree;

/i/, a number specifying a child of /p/.
|

Returns
|
TRUE, if /p/ has an /i/ th child; otherwise FALSE.
|


~html~
<a name='isEmpty'></a>
<hr>
~

...			isEmpty

~
bool isEmpty();
~

Returns
|
TRUE, if the tree is empty; otherwise FALSE.
|


~html~
<a name='nrChildren'></a>
<hr>
~

...			nrChildren

~
long nrChildren( IPosition<E>& p );
~

Parameters
|
/p/, a position (node) of the tree.
|

Returns
|
The number of children of /p/.
|


~html~
<a name='size'></a>
<hr>
~

...			size

~
long size();
~

Returns
|
The number of nodes in the tree.
|
