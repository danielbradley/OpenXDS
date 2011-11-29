#ifndef OPENXDS_ADT_IEITERATOR_H
#define OPENXDS_ADT_IEITERATOR_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class IEIterator : public openxds::Interface
{
public:
	virtual                  ~IEIterator() {}
	virtual       void             reset() const                                                      = 0;
	virtual       IEntry<E>*        next()       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IEntry<E>*        next() const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       bool           hasNext() const                                                      = 0;
}; 

};};

#endif

