.	IDictionary (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/IDictionary.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/IDictionary.h~
#ifndef OPENXDS_ADT_IDICTIONARY_H
#define OPENXDS_ADT_IDICTIONARY_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class IDictionary : public openxds::Interface
{
public:
	virtual                    ~IDictionary() {}

	virtual       IEntry<E>*         insert( const      char* key, E* element )                                           = 0;
	virtual       IEntry<E>*      insertRef( const      char* key, E& element )                                           = 0;
	virtual       E*                 remove(       IEntry<E>* e               )                                           = 0;

	virtual       IEntry<E>*           find( const char* key )       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IEntry<E>*     startsWith( const char* key )       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IEIterator<E>*    findAll( const char* key )                                                            = 0;

	virtual       IEIterator<E>*    entries()                                                                             = 0;
	virtual       IIterator<E>*      values()                                                                             = 0;

	virtual const IEntry<E>*           find( const char* key ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IEntry<E>*     startsWith( const char* key ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IEIterator<E>*    findAll( const char* key ) const                                                      = 0;

	virtual const IEIterator<E>*    entries() const                                                                       = 0;
	virtual const  IIterator<E>*     values() const                                                                       = 0;

	virtual bool                containsKey( const char* key ) const                                                      = 0;

	virtual bool                    isEmpty() const                                                                       = 0;
	virtual int                        size() const                                                                       = 0;
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
<tr><td><b>IEntry(E)*     </b></td> <td><a href='#insert'    >insert      </a></td> <td><b>const char* </b> key</td> <td><b>E*</b> element</td>                                     </tr>
<tr><td><b>IEntry(E)*     </b></td> <td><a href='#insertRef' >insertRef   </a></td> <td><b>const char* </b> key</td> <td><b>E&</b> element</td>                                     </tr>
<tr><td><b>E*             </b></td> <td><a href='#remove'    >remove      </a></td> <td><b>IEntry(E)*  </b> e  </td>                                                                </tr>
<tr><td><b>IEntry(E)*     </b></td> <td><a href='#find'      >find        </a></td> <td><b>const char* </b> key</td> <td>                       </td><td>NoSuchElementException*</td></tr>
<tr><td><b>IEntry(E)*     </b></td> <td><a href='#startsWith'>startsWith  </a></td> <td><b>const char* </b> key</td> <td>                       </td><td>NoSuchElementException*</td></tr>
<tr><td><b>IEIterator(E)* </b></td> <td><a href='#findAll'   >findAll     </a></td> <td><b>const char* </b> key</td> <td>                       </td>                               </tr>
<tr><td><b>IEIterator(E)* </b></td> <td><a href='#entries'   >entries     </a></td> <td>                       </td> <td>                       </td>                               </tr>
<tr><td><b>IIterator(E)*  </b></td> <td><a href='#values'    >values      </a></td> <td>                       </td> <td>                       </td>                               </tr>
<tr><td><b>bool           </b></td> <td><a href='#isEmpty'   >isEmpty     </a></td>                                                                                                 </tr>
<tr><td><b>long           </b></td> <td><a href='#size'      >size        </a></td>                                                                                                 </tr>
</tbody>
</table>
~

..		Methods

~html~
<a name='insert'></a>
<hr>
~

...			insert

~
IEntry<E>* insert( const char* key, E* element );
~

Parameters
|
/key/, to associate the /value/ with in the dictonary.

/element/, to be stored in the dictionary.
|

Returns
|
A new /entry/ that corresponds to the underlying position in the dictionary.
|


~html~
<a name='insertRef'></a>
<hr>
~

...			insert

~
IEntry<E>* insertRef( const char* key, E& element );
~

Parameters
|
/key/, to associate the /value/ with in the dictonary.

/element/, reference to be stored in the dictionary.
|

Returns
|
A new /entry/ that corresponds to the underlying position in the dictionary.
|


~html~
<a name='insertRef'></a>
<hr>
~

...			insertRef

~
IEntry<E>* insertRef( const char* key, E& element );
~

Parameters
|
/key/, to associate the /value/ with in the dictonary.

/element/, reference to be stored in the dictionary.
|

Returns
|
A new /entry/ that corresponds to the underlying position in the dictionary.
|


~html~
<a name='remove'></a>
<hr>
~

...			remove

~
E* remove( IEntry<E>* e );
~

Parameters
|
/e/, the /entry/ to be removed from the dictionary.
|

Returns
|
The /element/ that was stored in the /entry/.
|

~html~
<a name='find'></a>
<hr>
~

...			find

~
IEntry<E>* find( const char* key ) throw (NoSuchElementException*);
~

Parameters
|
/key/, that identifies one or more entries in the dictionary.
|

Returns
|
A new /entry/ instance that corresponds to the first entry in the dictionary that is identifeid by /key/.
|

Throws
|
/NoSuchElementException/ if no entry in the dictionary is identified by /key/.
|


~html~
<a name='startsWith'></a>
<hr>
~

...			startsWith

~
IEntry<E>* startsWith( const char* key ) throw (NoSuchElementException*);
~

Parameters
|
/key/, that identifies one or more entries in the dictionary.
|

Returns
|
A new /entry/ instance that corresponds to the first entry in the dictionary who key starts with /key/.
|

Throws
|
/NoSuchElementException/ if no entry's key starts with /key/.
|


~html~
<a name='findAll'></a>
<hr>
~

...			findAll

~
IEIterator<E>* findAll( const char* key );
~

Parameters
|
/key/, that identifies one or more entries in the dictionary.
|

Returns
|
A new /entry/ iterator that iterates over all entries that are identified by /key/.
|


~html~
<a name='entries'></a>
<hr>
~

...			entries

~
IEIterator<E>* entries();
~

Returns
|
A new /entry/ iterator that iterates over all entries in the dictionary.
|


~html~
<a name='values'></a>
<hr>
~

...			values

~
IIterator<E>* values();
~

Returns
|
A new iterator that iterates over all values in the dictionary.
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
