#ifndef OPENXDS_ADT_STD_EITERATOR_H
#define OPENXDS_ADT_STD_EITERATOR_H

#include <openxds.adt/IEIterator.h>

#include <openxds/Object.h>
#include <openxds.exceptions/NoSuchElementException.h>

#include <openxds.adt.std/Entry.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/IEIterator.h>
#include <openxds.core.adt.std.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

template <class E>
class EIterator : public openxds::Object, public openxds::adt::IEIterator<E>
{
public:
	EIterator( openxds::core::adt::IEIterator* it )
	{
		this->it = it;
	}

	virtual ~EIterator()
	{
		this->it->free( this->it );
	}
	
	virtual void reset() const
	{
		this->it->reset( this->it );
	}

	virtual IEntry<E>* next()
	throw (openxds::exceptions::NoSuchElementException*)
	{
		const openxds::core::adt::IEntry* e = this->it->next( this->it );
		if ( !e ) throw new openxds::exceptions::NoSuchElementException();
	
		return new Entry<E>( e );
	}

	virtual const IEntry<E>* next() const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		const openxds::core::adt::IEntry* e = this->it->next( this->it );
		if ( !e ) throw new openxds::exceptions::NoSuchElementException();
	
		return new Entry<E>( e );
	}

	virtual bool hasNext() const
	{
		return this->it->hasNext( this->it );
	}
	
private:
	openxds::core::adt::IEIterator* it;
}; 

};};};

#endif
