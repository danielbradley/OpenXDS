#ifndef OPENXDS_ADT_STD_PITERATOR_H
#define OPENXDS_ADT_STD_PITERATOR_H

#include <openxds.adt/IPIterator.h>

#include <openxds/Object.h>
#include <openxds.exceptions/NoSuchElementException.h>

#include <openxds.adt.std/Position.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/IPIterator.h>
#include <openxds.core.adt.std.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

template <class E>
class PIterator : public openxds::Object, public openxds::adt::IPIterator<E>
{
public:
	PIterator( openxds::core::adt::IPIterator* it )
	{
		this->it = it;
	}

	virtual ~PIterator()
	{
		this->it->free( this->it );
	}
	
	virtual void reset() const
	{
		this->it->reset( this->it );
	}

	virtual IPosition<E>* next()
	throw (openxds::exceptions::NoSuchElementException*)
	{
		const openxds::core::adt::IPosition* pos = this->it->next( this->it );
		if ( !pos ) throw new openxds::exceptions::NoSuchElementException();
	
		return new Position<E>( pos );
	}

	virtual const IPosition<E>* next() const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		const openxds::core::adt::IPosition* pos = this->it->next( this->it );
		if ( !pos ) throw new openxds::exceptions::NoSuchElementException();
	
		return new Position<E>( pos );
	}

	virtual bool hasNext() const
	{
		return this->it->hasNext( this->it );
	}
	
private:
	openxds::core::adt::IPIterator* it;
}; 

};};};

#endif
