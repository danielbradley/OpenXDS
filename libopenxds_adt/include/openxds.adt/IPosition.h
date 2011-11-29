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

