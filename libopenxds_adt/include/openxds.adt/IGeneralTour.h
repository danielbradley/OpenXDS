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

