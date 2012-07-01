#ifndef OPENXDS_ADT_IMAP_H
#define OPENXDS_ADT_IMAP_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.base.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class IMap : public openxds::Interface
{
public:
	virtual                                            ~IMap() {}

	virtual       E*                                     put( const char* key, E* element )                                                = 0;
	virtual       E*                                  remove( const char* key )                                                            = 0;

	virtual       E&                                     get( const char* key )       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IIterator<openxds::base::String>*     keys()                                                                             = 0;
	virtual       IIterator<E>*                       values()                                                                             = 0;
	virtual       IIterator<E>*                     elements()                                                                             = 0;


	virtual bool                                         has( const char* key ) const                                                      = 0;
	virtual const E&                                     get( const char* key ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IIterator<openxds::base::String>*     keys()                  const                                                      = 0;
	virtual const IIterator<E>*                       values()                  const                                                      = 0;
	virtual const IIterator<E>*                     elements()                  const                                                      = 0;

	virtual int                                         size()                  const                                                      = 0;
	virtual bool                                     isEmpty()                  const                                                      = 0;
}; 

};};

#endif

