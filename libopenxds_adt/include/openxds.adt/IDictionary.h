#ifndef OPENXDS_ADT_IDICTIONARY_H
#define OPENXDS_ADT_IDICTIONARY_H

#include "openxds.adt.h"
#include <openxds/Interface.h>
#include <openxds.exceptions/NoSuchElementException.h>

namespace openxds {
	namespace adt {

template <class E>
class IDictionary : public openxds::Interface
{
public:
	virtual                    ~IDictionary() {}

	virtual       IEntry<E>*         insert( const      char* key, E* element )                                           = 0;
	virtual       IEntry<E>*      insertRef( const      char* key, E& element )                                           = 0;
	virtual       E*                 remove(       IEntry<E>* e               )                                           = 0;

	virtual       IEntry<E>*           find( const char* key )       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IEntry<E>*     startsWith( const char* key )       throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual       IEIterator<E>*    findAll( const char* key )                                                            = 0;

	virtual       IEIterator<E>*    entries()                                                                             = 0;
	virtual       IIterator<E>*      values()                                                                             = 0;

	virtual const IEntry<E>*           find( const char* key ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IEntry<E>*     startsWith( const char* key ) const throw (openxds::exceptions::NoSuchElementException*) = 0;
	virtual const IEIterator<E>*    findAll( const char* key ) const                                                      = 0;

	virtual const IEIterator<E>*    entries() const                                                                       = 0;
	virtual const  IIterator<E>*     values() const                                                                       = 0;

	virtual bool                containsKey( const char* key ) const                                                      = 0;
	virtual bool          containsKeyPrefix( const char* key ) const                                                      = 0;

	virtual bool                    isEmpty() const                                                                       = 0;
	virtual int                        size() const                                                                       = 0;
}; 

};};

#endif

