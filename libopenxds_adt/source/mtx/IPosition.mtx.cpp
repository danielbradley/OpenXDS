.	IPosition (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/IPosition.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/IPosition.h~
#ifndef OPENXDS_ADT_IPOSITION_H
#define OPENXDS_ADT_IPOSITION_H

#include "openxds.adt.h"
#include <openxds/Interface.h>

namespace openxds {
	namespace adt {

template<class E>
class IPosition : public openxds::Interface
{
public:
	virtual ~IPosition() {}

	virtual       E&            getElement()                              = 0;
	virtual       IPosition<E>*       copy()                              = 0;

	virtual const E&            getElement()                        const = 0;
	virtual const IPosition<E>*       copy()                        const = 0;


	virtual       bool              equals( const IPosition<E>& p ) const = 0;
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

<tr><td><b>E&            </b></td> <td><a href='#getElement' >getElement</a></td>                                       </tr>
<tr><td><b>IPosition(E)* </b></td> <td><a href='#copy'       >copy      </a></td>                                       </tr>
<tr><td><b>bool          </b></td> <td><a href='#equals'     >equals    </a></td> <td><b>const IPosition(E)&</b> p</td> </tr>

</tbody>
</table>
~

..		Methods

~html~
<a name='getElement'></a>
<hr>
~

...			getElement

~
E& getElement();
~

Returns
|
Returns /element/ corresponding to this position.
|

~html~
<a name='copy'></a>
<hr>
~

...			copy

~
IPosition<E>* copy();
~

Returns
|
A new /position/ instance that corresponds to the underlying node storing the /element/.
|

~html~
<a name='equals'></a>
<hr>
~

...			equals

~
bool equals( IPosition(E)& p );
~

Parameters
|
/p/, a /position/ corresponding to the underlying node storing an /element/.
|

Returns
|
TRUE, if /p/ corresponds to the same underlying node as this /position/; otherwise FALSE.
|
