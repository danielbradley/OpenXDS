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

