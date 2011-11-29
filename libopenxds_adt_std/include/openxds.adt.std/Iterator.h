#ifndef OPENXDS_ADT_STD_ITERATOR_H
#define OPENXDS_ADT_STD_ITERATOR_H

#include <openxds.adt/IIterator.h>

#include <openxds/Object.h>
#include <openxds.exceptions/NoSuchElementException.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/IIterator.h>
#include <openxds.core.adt.std.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

template <class E>
class Iterator : public openxds::Object, public openxds::adt::IIterator<E>
{
public:
	Iterator( openxds::core::adt::IIterator* it )
	{
		this->it = it;
	}

	virtual ~Iterator()
	{
		this->it->free( this->it );
	}
	
	virtual void reset() const
	{
		this->it->reset( this->it );
	}

	virtual E& next()
	throw (openxds::exceptions::NoSuchElementException*)
	{
		const E* _e = static_cast<const E*>( this->it->next( this->it ) );
		E* e = const_cast<E*>( _e );
		if ( ! e ) throw new openxds::exceptions::NoSuchElementException();
	
		return *e;
	}

	virtual const E& next() const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		const E* _e = static_cast<const E*>( this->it->next( this->it ) );
		E* e = const_cast<E*>( _e );
		if ( ! e ) throw new openxds::exceptions::NoSuchElementException();
	
		return *e;
	}

	virtual bool hasNext() const
	{
		return this->it->hasNext( this->it );
	}
	
private:
	openxds::core::adt::IIterator* it;
}; 

};};};

#endif
