.	IIterator (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/IIterator.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/IIterator.h~
#ifndef OPENXDS_ADT_IITERATOR_H
#define OPENXDS_ADT_IITERATOR_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class IIterator : public openxds::Interface
{
public:
	virtual            ~IIterator() {}
	virtual       void      reset() const                                                      = 0;
	virtual       E&         next()       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const E&         next() const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       bool    hasNext() const                                                      = 0;
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

<tr><td><b>void</b></td><td><a href='#reset'  >reset  </a></td>                                </tr>
<tr><td><b>E*  </b></td><td><a href='#next'   >next   </a></td><td>NoSuchElementException*</td></tr>
<tr><td><b>bool</b></td><td><a href='#hasNext'>hasNext</a></td>                                </tr>

</tbody>
</table>
~

..		Methods

~html~
<a name='reset'></a>
<hr>
~

...			reset

~
void reset();
~

Causes
|
The iterator to be reset such that a call to /next/ will return the first /element/ of the iteration.
|

~html~
<a name='hasNext'></a>
<hr>
~

...			hasNext

~
bool hasNext();
~

Returns
|
TRUE, if another /element/ could be returned by a call to /next/; otherwise FALSE.
|

~html~
<a name='next'></a>
<hr>
~

...			next

~
E* next() throw (NoSuchElementException*);
~

Returns
|
A reference to the next /element/ in the iteration.
|

Throws
|
/NoSuchElementException/, if the iterator has no more items.
|
