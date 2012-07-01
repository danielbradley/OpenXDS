#ifndef OPENXDS_ADT_STD_MAP_H
#define OPENXDS_ADT_STD_MAP_H

#include <openxds.adt/IMap.h>
#include <openxds.adt.std/Iterator.h>

#include <openxds/Object.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds.base/String.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/IKey.h>
#include <openxds.core.adt/IMap.h>
#include <openxds.core.adt/IIterator.h>
#include <openxds.core.adt.std.h>
#include <openxds.core.adt.std/StdADTFactory.h>
#include <openxds.core.adt.std/StdIterator.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

void* createMap();

template <class E>
class Map : public openxds::Object, public openxds::adt::IMap<E>
{
public:
	Map()
	{
		this->m = openxds::core::adt::std::StdADTFactory_createMap();
		this->cacheKey   = null;
		this->cacheValue = null;
	}
	
	virtual ~Map()
	{
		//Use EIterator to remove objects.
	
//		IEIterator<E>* it = this->entries();
//		while ( it->hasNext() )
//		{
//			IEntry<E>* entry = it->next();
//			delete this->remove( entry );
//		}
//		delete it;
//		this->d->free( this->d );
	}

	virtual E* put( const char* key, E* value )
	{
		openxds::core::adt::IKey* _key = openxds::core::adt::std::StdADTFactory_createKey( key );
		return static_cast<E*>( this->m->put( this->m, _key, value ) );
	}
	
	virtual E* remove( const char* key )
	{
		openxds::core::adt::IKey* _key = openxds::core::adt::std::StdADTFactory_createKey( key );
		return static_cast<E*>( this->m->remove( this->m, _key ) );
	}

	virtual bool has( const char* key ) const
	{
		openxds::core::adt::IKey* _key = openxds::core::adt::std::StdADTFactory_createKey( key );
		const E* _e = static_cast<const E*>( this->m->get( this->m, _key ) );
		E* e = const_cast<E*>( _e );
		
		bool ret = (null != e);
		if ( ret )
		{
			const_cast<Map*>( this )->cacheKey   = key;
			const_cast<Map*>( this )->cacheValue = e;
		}
		else
		{
			const_cast<Map*>( this )->cacheKey   = null;
			const_cast<Map*>( this )->cacheValue = null;
		}
		return ret;
	}
	
	virtual E& get( const char* key ) throw (openxds::exceptions::NoSuchElementException*)
	{
		E* e = null;
		if ( this->cacheKey == key )
		{
			e = this->cacheValue;
		}
		else
		{
			this->cacheKey   = null;
			this->cacheValue = null;

			openxds::core::adt::IKey* _key = openxds::core::adt::std::StdADTFactory_createKey( key );
			const E* _e = static_cast<const E*>( this->m->get( this->m, _key ) );
			e = const_cast<E*>( _e );
		}
		if ( ! e )
		{
			throw new openxds::exceptions::NoSuchElementException();
		}

		return *e;
	}

	virtual IIterator<openxds::base::String>* keys()
	{
		openxds::core::adt::IIterator* _keys = this->m->keys( this->m );
		{
			openxds::core::adt::std::StdIterator* string_keys = openxds::core::adt::std::new_StdIterator();
			while ( _keys->hasNext( _keys ) )
			{
				const openxds::core::adt::IKey* key = static_cast<const openxds::core::adt::IKey*>( _keys->next( _keys ) );
				StdIterator_addElement( string_keys, new openxds::base::String( key->getChars( key ) ) );
			}
			_keys->free( _keys );
			_keys = (openxds::core::adt::IIterator*) string_keys;
		}
		
		return new Iterator<openxds::base::String>( _keys );
	}
	
	virtual IIterator<E>*  values()
	{
		return new Iterator<E>( this->m->values( this->m ) );
	}

	virtual IIterator<E>* elements()
	{
		return this->values();
	}

	virtual const E& get( const char* key ) const throw (openxds::exceptions::NoSuchElementException*)
	{
		openxds::core::adt::IKey* _key = openxds::core::adt::std::StdADTFactory_createKey( key );
		const E* e = static_cast<const E*>( this->m->get( this->m, _key ) );
		if ( ! e )
		{
			throw new openxds::exceptions::NoSuchElementException();
		}
		return *e;
	}
	
	virtual const IIterator<openxds::base::String>* keys() const
	{
		openxds::core::adt::IIterator* _keys = this->m->keys( this->m );
		{
			openxds::core::adt::std::StdIterator* string_keys = openxds::core::adt::std::new_StdIterator();
			while ( _keys->hasNext( _keys ) )
			{
				const openxds::core::adt::IKey* key = static_cast<const openxds::core::adt::IKey*>( _keys->next( _keys ) );
				StdIterator_addElement( string_keys, new openxds::base::String( key->getChars( key ) ) );
			}
			_keys->free( _keys );
			_keys = (openxds::core::adt::IIterator*) string_keys;
		}
		
		return new Iterator<openxds::base::String>( _keys );
	}
	
	virtual const IIterator<E>*  values() const
	{
		return new Iterator<E>( this->m->values( this->m ) );
	}

	virtual const IIterator<E>*  elements() const
	{
		return this->values();
	}

	virtual int size() const
	{
		return this->m->size( this->m );
	}

	virtual bool isEmpty() const
	{
		return this->m->isEmpty( this->m );
	}

private:
	openxds::core::adt::IMap* m;
	const char* cacheKey;
	E*          cacheValue;
}; 

};};};

#endif
