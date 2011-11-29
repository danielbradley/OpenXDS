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

