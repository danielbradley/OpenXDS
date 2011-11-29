#ifndef OPENXDS_ADT_STD_ENTRY_H
#define OPENXDS_ADT_STD_ENTRY_H

#include <openxds.adt/IEntry.h>

#include <openxds/Object.h>
#include <openxds.exceptions/NoSuchElementException.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/IEntry.h>
#include <openxds.core.adt/IKey.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

void* createEntry();

template<class E>
class Entry : public openxds::Object, public openxds::adt::IEntry<E>
{
public:
	Entry( const openxds::core::adt::IEntry* e )
	{
		this->e = e;
	}

	virtual ~Entry()
	{
	}
	



	virtual const char* getKey() const
	{
		const openxds::core::adt::IKey* k = this->e->getKey( this->e );
		return k->getChars( k );
	}

	virtual E& getValue()
	{
		const E* v = static_cast<const E*>( this->e->getValue( this->e ) );
		E* v2 = const_cast<E*>( v );
		return *v2;
	}

	virtual const E& getValue() const
	{
		const E* v = static_cast<const E*>( this->e->getValue( this->e ) );
		return *v;
	}

	virtual IEntry<E>* copy()
	{
		return new Entry( this->e );
	}

	virtual const IEntry<E>* copy() const
	{
		return new Entry( this->e );
	}

	virtual const openxds::core::adt::IEntry* getCoreEntry() const
	{
		return this->e;
	}

private:
	const openxds::core::adt::IEntry* e;
}; 

};};};

#endif
