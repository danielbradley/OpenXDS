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

