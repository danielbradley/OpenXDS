#ifndef OPENXDS_ADT_STD_POSITION_H
#define OPENXDS_ADT_STD_POSITION_H

#include <openxds.adt/IPosition.h>

#include <openxds/Object.h>
#include <openxds.exceptions/NoSuchElementException.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/IPosition.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

void* createPosition();

template <class E>
class Position : public openxds::Object, public openxds::adt::IPosition<E>
{
public:
	Position( const openxds::core::adt::IPosition* p )
	{
		this->p = p;
	}

	virtual ~Position()
	{}
	
	virtual E& getElement()
	{
		const E* e = static_cast<const E*>( this->p->getElement( this->p ) );
		E* e2 = const_cast<E*>( e );
		return *e2;
	}

	virtual const E& getElement() const
	{
		const E* e = static_cast<const E*>( this->p->getElement( this->p ) );
		return *e;
	}

	virtual IPosition<E>* copy()
	{
		return new Position( this->p );
	}

	virtual const IPosition<E>* copy() const
	{
		return new Position( this->p );
	}

	virtual bool equals( const IPosition<E>& p ) const
	{
		const Position<E>& pos = dynamic_cast<const Position<E>&>( p );
		return this->p == pos.p;
	}

	virtual const openxds::core::adt::IPosition* getCorePosition() const
	{
		return this->p;
	}

private:
	const openxds::core::adt::IPosition* p;
}; 

};};};

#endif
