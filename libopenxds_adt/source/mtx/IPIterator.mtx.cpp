.	IPIterator (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/IPIterator.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/IPIterator.h~
#ifndef OPENXDS_ADT_IPITERATOR_H
#define OPENXDS_ADT_IPITERATOR_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class IPIterator : public openxds::Interface
{
public:
	virtual                    ~IPIterator() {}
	virtual       void               reset() const                                                      = 0;
	virtual       IPosition<E>*       next()       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IPosition<E>*       next() const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       bool             hasNext() const                                                      = 0;
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

<tr><td><b>void         </b></td><td><a href='#reset'  >reset  </a></td>                                </tr>
<tr><td><b>IPosition(E)*</b></td><td><a href='#next'   >next   </a></td><td>NoSuchElementException*</td></tr>
<tr><td><b>bool         </b></td><td><a href='#hasNext'>hasNext</a></td>                                </tr>

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
The iterator to be reset such that a call to /next/ will return the first /position/ of the iteration.
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
TRUE, if another /position/ could be returned by a call to /next/; otherwise FALSE.
|

~html~
<a name='next'></a>
<hr>
~

...			next

~
IPosition<E>* next() throw (NoSuchElementException*);
~

Returns
|
A new /IPosition/ instance, that the user is responsible for deallocating.
|

Throws
|
/NoSuchElementException/, if the iterator has no more items.
|
