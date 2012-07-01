.	IMap (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/IMap.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/IMap.h~
#ifndef OPENXDS_ADT_IMAP_H
#define OPENXDS_ADT_IMAP_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.base.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class IMap : public openxds::Interface
{
public:
	virtual                                            ~IMap() {}

	virtual       E*                                     put( const char* key, E* element )                                                = 0;
	virtual       E*                                  remove( const char* key )                                                            = 0;

	virtual       E&                                     get( const char* key )       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IIterator<openxds::base::String>*     keys()                                                                             = 0;
	virtual       IIterator<E>*                       values()                                                                             = 0;
	virtual       IIterator<E>*                     elements()                                                                             = 0;


	virtual bool                                         has( const char* key ) const                                                      = 0;
	virtual const E&                                     get( const char* key ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IIterator<openxds::base::String>*     keys()                  const                                                      = 0;
	virtual const IIterator<E>*                       values()                  const                                                      = 0;
	virtual const IIterator<E>*                     elements()                  const                                                      = 0;

	virtual int                                         size()                  const                                                      = 0;
	virtual bool                                     isEmpty()                  const                                                      = 0;
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
<tr><td><b>E*                 </b></td> <td><a href='#put'       >put         </a></td> <td><b>const char* </b> key</td> <td><b>E*</b> element</td>                                </tr>
<tr><td><b>E*                 </b></td> <td><a href='#remove'    >remove      </a></td> <td><b>const char* </b> key</td>                                                           </tr>
<tr><td><b>E*                 </b></td> <td><a href='#get'       >get         </a></td> <td><b>const char* </b> key</td> <td>                 </td><td>NoSuchElementException*</td> </tr>
<tr><td><b>IIterator(String)* </b></td> <td><a href='#keys'      >keys        </a></td>                                                                                            </tr>
<tr><td><b>IIterator(E)*      </b></td> <td><a href='#elements'  >values      </a></td>                                                                                            </tr>
<tr><td><b>IIterator(E)*      </b></td> <td><a href='#elements'  >elements    </a></td>                                                                                            </tr>
<tr><td><b>bool               </b></td> <td><a href='#isEmpty'   >isEmpty     </a></td>                                                                                            </tr>
<tr><td><b>long               </b></td> <td><a href='#size'      >size        </a></td>                                                                                            </tr>

</tbody>
</table>
~

..		Methods

~html~
<a name='put'></a>
<hr>
~

...			put

~
E* put( const char* key, E* element );
~

Parameters
|
/key/, that the /element/ will be associated with;

/element/, to be mapped to /key/.
|

Returns
|
The /element/ currently mapped to /key/; otherwise NULL.
|

~html~
<a name='remove'></a>
<hr>
~

...			remove

~
E* remove( const char* key );
~

Parameters
|
/key/, that may map to an /element/.
|

Returns
|
The /element/ currently mapped to /key/; otherwise NULL.
|

~html~
<a name='get'></a>
<hr>
~

...			get

~
E& get( const char* key ) throw (NoSuchElementException*);
~

Parameters
|
/key/, that may map to an /element/.
|

Returns
|
A reference to the /element/ currently mapped to /key/; otherwise NULL.
|

Throws
|
/NoSuchElementException/, if the /key/ is not in the map.
|


~html~
<a name='keys'></a>
<hr>
~

...			keys

~
IIterator<String>* keys();
~

Returns
|
A /string/ iterator that iterates over the keys stored in the Map.
|

~html~
<a name='elements'></a>
<hr>
~

...			elements (values)

~
IIterator<E>* elements();
~

Returns
|
An /element/ iterator that iterates over the /elements/ stored in the map.
|

...			isEmpty

~
bool isEmpty();
~

Returns
|
TRUE, if the map is empty; otherwise FALSE.
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
The number of key/element mappings in the map.
|
