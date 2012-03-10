.	IGeneralTour (interface)

..		Usage

Linkage:

~
-lopenxds_adt
~

To use the interface:

~
#include <openxds.adt/IGeneralTour.h>

using namespace openxds::adt;
~

!
~!include/openxds.adt/IGeneralTour.h~
#ifndef OPENXDS_ADT_IGENERALTOUR_H
#define OPENXDS_ADT_IGENERALTOUR_H

#include "openxds.adt.h"
#include <openxds/Interface.h>

namespace openxds {
	namespace adt {

template <class E>
class IGeneralTour : public openxds::Interface
{
public:
	virtual ~IGeneralTour() {}

	virtual openxds::Object* doGeneralTour()                  = 0;
	virtual openxds::Object* doGeneralTour( IPosition<E>& p ) = 0;
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

<tr><td><b>Object*</b></td> <td><a href='#doGeneralTour'>doGeneralTour</a></td> </tr>

</tbody>
</table>
~

..		Methods

~html~
<a name='doGeneralTour'></a>
<hr>
~

...			doGeneralTour

~
Object* doGeneralTour();
~

Returns
|
An object instance whose type depends on the implementation of the deriving class.
|
