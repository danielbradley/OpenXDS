.	IEntry (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/IEntry.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/IEntry.h~
#ifndef OPENXDS_ADT_IENTRY_H
#define OPENXDS_ADT_IENTRY_H

#include "openxds.adt.h"
#include <openxds/Interface.h>

namespace openxds {
	namespace adt {

template<class E>
class IEntry : public openxds::Interface
{
public:
	virtual ~IEntry() {};

	virtual const char*        getKey() const = 0;
	virtual       E&         getValue()       = 0;
	virtual const E&         getValue() const = 0;
	virtual       IEntry<E>*     copy()       = 0;
	virtual const IEntry<E>*     copy() const = 0;
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
	<th>Returns</th><th>Method-name</th><th>Throws</th>
</tr>
</thead>
<tbody>

<tr><td><b>const char*</b></td><td><a href='#getKey'  >getKey  </a></td> <td></td> </tr>
<tr><td><b>E&         </b></td><td><a href='#getValue'>getValue</a></td> <td></td> </tr>
<tr><td><b>IEntry(E)* </b></td><td><a href='#copy'    >copy    </a></td> <td></td> </tr>

</tbody>
</table>
~

..		Methods

~html~
<a name='getKey'></a>
<hr>
~

...			getKey

~
const char* getKey();
~

Returns
|
Returns the entry's /key/.
|

~html~
<a name='getValue'></a>
<hr>
~

...			getValue

~
E& getValue();
~

Returns
|
A reference to the /element/ value stored in this entry.
|

~html~
<a name='copy'></a>
<hr>
~

...			copy

~
IEntry<E>* copy();
~

Returns
|
A new /IEntry/ instance, that the user is responsible for deallocating.
|
