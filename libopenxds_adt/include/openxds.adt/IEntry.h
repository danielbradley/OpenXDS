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

