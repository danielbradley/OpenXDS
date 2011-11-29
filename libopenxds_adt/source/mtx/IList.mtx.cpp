.	IList (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/IList.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/IList.h~
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

<tr><td><b>IPosition(E)* </b></td><td><a href='#insertFirst' >insertFirst  </a></td> <td><b>E*           </b> element </td>                                                                  </tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#insertLast'  >insertLast   </a></td> <td><b>E*           </b> element </td>                                                                  </tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#insertBefore'>insertBefore </a></td> <td><b>IPosition(E)&</b> p       </td><td><b>E*       </b> element</td>                                 </tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#insertAfter' >insertAfter  </a></td> <td><b>IPosition(E)&</b> p       </td><td><b>E*       </b> element</td>                                 </tr>
<tr><td><b>E*            </b></td><td><a href='#replace'     >replace      </a></td> <td><b>IPosition(E)&</b> p       </td><td><b>E*       </b> element</td>                                 </tr>
<tr><td><b>E*            </b></td><td><a href='#remove'      >remove       </a></td> <td><b>IPosition(E)*</b> p       </td>                                                                  </tr>

<tr><td><b>IPosition(E)* </b></td><td><a href='#first'       >first        </a></td> <td>                             </td><td>                        </td> <td>NoSuchElementException*</td></tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#last'        >last         </a></td> <td>                             </td><td>                        </td> <td>NoSuchElementException*</td></tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#prev'        >prev         </a></td><td><b>IPosition(E)&</b> p        </td><td>                        </td> <td>NoSuchElementException*</td></tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#previous'    >previous     </a></td><td><b>IPosition(E)&</b> p        </td><td>                        </td> <td>NoSuchElementException*</td></tr>
<tr><td><b>IPosition(E)* </b></td><td><a href='#next'        >next         </a></td><td><b>IPosition(E)&</b> p        </td><td>                        </td> <td>NoSuchElementException*</td></tr>

<tr><td><b>IIterator(E)* </b></td><td><a href='#elements'    >elements     </a></td>                                                                                                         </tr>

<tr><td><b>IPIterator(E)*</b></td><td><a href='#positions'   >positions    </a></td>                                                                                                         </tr>

<tr><td><b>bool          </b></td><td><a href='#isEmpty'     >isEmpty      </a></td>                                                                                                         </tr>
<tr><td><b>long          </b></td><td><a href='#size'        >size         </a></td>                                                                                                         </tr>

</tbody>
</table>
~

..		Methods

~html~
<a name='insertFirst'></a>
<hr>
~

...			insertFirst

~
IPosition<E>* insertFirst( E* element );
~

Parameters
|
/element/, to be inserted into the list.
|

Returns
|
A new /position/ that corresponds to the element's position in the list.
|


~html~
<a name='insertLast'></a>
<hr>
~

...			insertLast

~
IPosition<E>* insertLast( E* element );
~

Parameters
|
/element/, to be inserted into the list.
|

Returns
|
A new /position/ that corresponds to the element's position in the list.
|


~html~
<a name='insertBefore'></a>
<hr>
~

...			insertBefore

~
IPosition<E>* insertBefore( IPosition<E>& p, E* element );
~

Parameters
|
/p/, the position that the /element/ is to be inserted before;

/element/, to be inserted into the list.
|

Returns
|
A new /position/ that corresponds to the element's position in the list.
|

~html~
<a name='insertAfter'></a>
<hr>
~

...			insertAfter

~
IPosition<E>* insertAfter( IPosition<E>& p, E* element );
~

Parameters
|
/p/, the position that the /element/ is to be inserted after;

/element/, to be inserted into the list.
|

Returns
|
A new /position/ that corresponds to the element's position in the list.
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
/p/, the position that the /element/ is to be swapped into;

/element/, to be inserted into the list.
|

Returns
|
The previous /element/ in that /position/.
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
/p/, the position that the /element/ is to be removed from.
|

Returns
|
The /element/ stored at the passed /position/.
|

~html~
<a name='first'></a>
<hr>
~

...			first

~
IPosition<E>* first() throw (NoSuchElementException*);
~

Returns
|
The first /position/ of the list.
|

Throws
|
/NoSuchElementException/, if the list is empty.
|


~html~
<a name='last'></a>
<hr>
~

...			last

~
IPosition<E>* last() throw (NoSuchElementException*);
~

Returns
|
The last /position/ of the list.
|

Throws
|
/NoSuchElementException/, if the list is empty.
|


~html~
<a name='previous'></a>
<hr>
~

...			previous (prev)

~
IPosition<E>* previous( IPosition<E>& p ) throw (NoSuchElementException*);
~

Parameters
|
/p/, a position in the list.
|

Returns
|
The /position/ before /p/.
|

Throws
|
/NoSuchElementException/, if there is no position before /p/.
|

~html~
<a name='next'></a>
<hr>
~

...			next

~
IPosition<E>* next( IPosition<E>& p ) throw (NoSuchElementException*);
~

Parameters
|
/p/, a position in the list.
|

Returns
|
The /position/ after /p/.
|

Throws
|
/NoSuchElementException/, if there is no position after /p/.
|


~html~
<a name='elements'></a>
<hr>
~

...			elements

~
IIterator<E>* elements();
~

Returns
|
An /element/ iterator that iterates over the list's elements.
|

~html~
<a name='positions'></a>
<hr>
~

...			positions

~
IPIterator<E>* positions();
~

Returns
|
A /position/ iterator that iterates over the list's positions.
|


...			isEmpty

~
bool isEmpty();
~

Returns
|
TRUE, if the list is empty; otherwise FALSE.
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
The number of /elements/ stored in the list.
|
