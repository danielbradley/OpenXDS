
#ifndef OPENXDS_ADT_STD_DICTIONARY_H
#define OPENXDS_ADT_STD_DICTIONARY_H

#include <openxds.adt/IDictionary.h>
#include <openxds.adt.std/EIterator.h>
#include <openxds.adt.std/Entry.h>
#include <openxds.adt.std/Iterator.h>

#include <openxds/Object.h>
#include <openxds.exceptions/NoSuchElementException.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/IDictionary.h>
#include <openxds.core.adt/IEIterator.h>
#include <openxds.core.adt/IEntry.h>
#include <openxds.core.adt.std.h>
#include <openxds.core.adt.std/StdADTFactory.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

void* createDictionary();

template <class E>
class NonDeletingDictionary : public openxds::Object, public openxds::adt::IDictionary<E>
{
public:
	NonDeletingDictionary()
	{
		this->d = openxds::core::adt::std::StdADTFactory_createDictionary();
		this->throwExceptions = 1;
	}
	
	virtual ~NonDeletingDictionary()
	{
		//Use EIterator to remove objects.
	
		IEIterator<E>* it = this->entries();
		while ( it->hasNext() )
		{
			IEntry<E>* entry = it->next();
			this->remove( entry ); // Returned objects are not being deleted here.
		}
		delete it;

		this->d->free( this->d );
	}

	virtual void setThrowExceptions( bool throwExceptions )
	{
		this->throwExceptions = throwExceptions;
	}
	
	virtual IEntry<E>* insert( const char* key, E* value )
	{
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		IEntry<E>* e = new Entry<E>( this->d->insert( this->d, k, (void*) value ) );
		k->free( k );
		return e;
	}

	virtual IEntry<E>* insertRef( const char* key, E& value )
	{
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		IEntry<E>* e = new Entry<E>( this->d->insertRef( this->d, k, &value ) );
		k->free( k );
		return e;
	}
	
	virtual E* remove( IEntry<E>* e )
	{
		Entry<E>* e2 = dynamic_cast<Entry<E>*>( e );
		const openxds::core::adt::IEntry* core = e2->getCoreEntry();
		E* value = static_cast<E*>( this->d->remove( this->d, core ) );
		delete e;
		return value;
	}

	virtual IEntry<E>* find( const char* key )
	throw (openxds::exceptions::NoSuchElementException*)
	{
		Entry<E>* e = NULL;
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		{
			const openxds::core::adt::IEntry* core = this->d->find( this->d, k );
			k->free( k );

			if ( core )
			{
				e = new Entry<E>( core );
			}
			else
			if ( throwExceptions )
			{
				throw new openxds::exceptions::NoSuchElementException();
			}
		}
		return e;
	}

	virtual IEntry<E>* startsWith( const char* key )
	throw (openxds::exceptions::NoSuchElementException*)
	{
		Entry<E>* e = NULL;
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		{
			const openxds::core::adt::IEntry* core = this->d->startsWith( this->d, k );
			k->free( k );

			if ( core )
			{
				e = new Entry<E>( core );
			}
			else
			if ( throwExceptions )
			{
				throw new openxds::exceptions::NoSuchElementException();
			}
		
		}
		return e;
	}

	virtual IEIterator<E>* findAll( const char* key )
	{
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		EIterator<E>* it = new EIterator<E>( this->d->findAll( this->d, k ) );
		k->free( k );
		return it;
	}

	virtual bool has( const char* key ) const
	{
		bool ret = false;
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		{
			const openxds::core::adt::IEntry* core = this->d->find( this->d, k );
			ret = (null != core );
		}
		k->free( k );
		return ret;
	}

	virtual const IEntry<E>* find( const char* key ) const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		Entry<E>* e = NULL;
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		{
			const openxds::core::adt::IEntry* core = this->d->find( this->d, k );
			k->free( k );

			if ( core )
			{
				e = new Entry<E>( core );
			}
			else
			if ( throwExceptions )
			{
				throw new openxds::exceptions::NoSuchElementException();
			}
		}
		return e;
	}

	virtual const IEntry<E>* startsWith( const char* key ) const
	throw (openxds::exceptions::NoSuchElementException*)
	{
		Entry<E>* e = NULL;
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		{
			const openxds::core::adt::IEntry* core = this->d->startsWith( this->d, k );
			k->free( k );

			if ( core )
			{
				e = new Entry<E>( core );
			}
			else
			if ( throwExceptions )
			{
				throw new openxds::exceptions::NoSuchElementException();
			}
		}
		return e;
	}

	virtual const IEIterator<E>* findAll( const char* key ) const
	{
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		EIterator<E>* it = new EIterator<E>( this->d->findAll( this->d, k ) );
		k->free( k );
		return it;
	}

	virtual IEIterator<E>* entries()
	{
		return new EIterator<E>( this->d->entries( this->d ) );
	}
	
	virtual const IEIterator<E>* entries() const
	{
		return new EIterator<E>( this->d->entries( this->d ) );
	}

	virtual const Iterator<E>* values() const
	{
		return new Iterator<E>( this->d->values( this->d ) );
	}

	virtual Iterator<E>* values()
	{
		return new Iterator<E>( this->d->values( this->d ) );
	}
	
	virtual bool containsKey( const char* key ) const
	{
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		bool contains = this->d->containsKey( this->d, k );
		k->free( k );
		return contains;
	}

	virtual bool containsKeyPrefix( const char* key ) const
	{
		openxds::core::adt::IKey* k = openxds::core::adt::std::StdADTFactory_createKey( key );
		bool contains = this->d->containsKeyPrefix( this->d, k );
		k->free( k );
		return contains;
	}

	virtual int size() const
	{
		return this->d->size( this->d );
	}

	virtual bool isEmpty() const
	{
		return this->d->isEmpty( this->d );
	}

protected:
	openxds::core::adt::IDictionary* d;
	bool throwExceptions;
}; 

template <class E>
class Dictionary : public NonDeletingDictionary<E>
{
public:
	virtual ~Dictionary()
	{
		//Use EIterator to remove objects.
	
		IEIterator<E>* it = this->entries();
		while ( it->hasNext() )
		{
			IEntry<E>* entry = it->next();
			delete this->remove( entry );
		}
		delete it;
	}
};

template <class E>
class NTDictionary : public Dictionary<E>
{
public:
	NTDictionary()
	{
		this->setThrowExceptions( false );
	}
};

template <class E>
class SortedDictionary : public Dictionary<E>
{
public:
	SortedDictionary()
	{
		this->d = openxds::core::adt::std::StdADTFactory_createSortedDictionary();
	}
};


};};};

#endif
