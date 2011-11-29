.	IStack (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/IStack.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/IStack.h~
#ifndef OPENXDS_ADT_ISTACK_H
#define OPENXDS_ADT_ISTACK_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class IStack : public openxds::Interface
{
public:
	virtual            ~IStack() {}
	virtual       void    push( E* anElement )                                                            = 0;
	virtual       E*       pop()                     throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       E&       top()                     throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const E&       top()               const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       bool isEmpty()               const                                                      = 0;
	virtual       long    size()               const                                                      = 0;
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
	<th>Returns</th><th>Method-name</th><th colspan='1'>Parameters</th><th>Throws</th>
</tr>
</thead>
<tbody>

<tr><td><b>void </b></td> <td><a href='#push'    >push    </a></td> <td><b>E*</b> element</td>                                </tr>
<tr><td><b>E*   </b></td> <td><a href='#pop'     >pop     </a></td> <td>                 </td><td>NoSuchElementException*</td> </tr>
<tr><td><b>E&   </b></td> <td><a href='#top'     >top     </a></td> <td>                 </td><td>NoSuchElementException*</td> </tr>
<tr><td><b>bool </b></td> <td><a href='#isEmpty' >isEmpty </a></td>                                                           </tr>
<tr><td><b>long </b></td> <td><a href='#size'    >size    </a></td>                                                           </tr>

</tbody>
</table>
~

..		Methods

~html~
<a name='push'></a>
<hr>
~

...			put

~
void push( E* element );
~

Parameters
|
/element/, to be pushed onto the top of the stack.
|

~html~
<a name='pop'></a>
<hr>
~

...			pop

~
E* pop() throw (NoSuchElementException*);
~

Returns
|
The top /element/ from the stack.
|

Throws
|
/NoSuchElementException/, if the stack is empty.
|

~html~
<a name='top'></a>
<hr>
~

...			top

~
E& top() throw (NoSuchElementException*);
~

Returns
|
A reference to the top /element/ on the stack.
|

Throws
|
/NoSuchElementException/, if the stack is empty.
|

~html~
<a name='keys'></a>
<hr>
~

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
