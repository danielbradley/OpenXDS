/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/Object.h>

#include <openxds.core.threads/Mutex.h>

#include <exception>
#include <new>
#include <cstdlib>
#include <cstdio>

using namespace openxds;
using namespace openxds::core::threads;

int         Object::test = 0;
long long   Object::objectCount = 0;
IMutex*     Object::lock = null;
void*       Object::objects = null;

Object::Object()
{
	if ( Object::test )
	{
		Object::lock->lock( Object::lock );
		//Sequence_add( (ISequence*) Object::objects, this );
		Object::objectCount++;
		Object::lock->unlock( Object::lock );
	}
	else if ( this->test )
	{
		Object::lock->lock( Object::lock );
		//Sequence_add( (ISequence*) Object::objects, this );
		Object::objectCount++;
		Object::lock->unlock( Object::lock );
	}
}

Object::Object( const Object& obj )
{
	if ( Object::test )
	{
		Object::lock->lock( Object::lock );
		//Sequence_add( (ISequence*) Object::objects, this );
		Object::objectCount++;
		Object::lock->unlock( Object::lock );
	}
	else if ( this->test )
	{
		Object::lock->lock( Object::lock );
		//Sequence_add( (ISequence*) Object::objects, this );
		Object::objectCount++;
		Object::lock->unlock( Object::lock );
	}
}

Object::~Object()
{
	if ( Object::test )
	{
		Object::lock->lock( Object::lock );
		//Sequence_remove_element( (ISequence*) Object::objects, this );
		Object::objectCount--;
		Object::lock->unlock( Object::lock );
	}
	else if ( this->test )
	{
		Object::lock->lock( Object::lock );
		//Sequence_remove_element( (ISequence*) Object::objects, this );
		Object::objectCount--;
		Object::lock->unlock( Object::lock );
	}
}

long long
Object::getObjectCount()
{
	long long count = 0;
	if ( Object::test ) Object::lock->lock( Object::lock );
	count = Object::objectCount;
	if ( Object::test ) Object::lock->unlock( Object::lock );

	return count;
}

//Class*  Object::getClass() const
//{
//  return (Class*) null;
//}

//Object*
//Object::clone() const
//{}

//String* Object::asString() const
//{
//  return new String();
//}

Object&
Object::operator=( Object& )
{
	//	if ( object = object )
	abort();
	return *this;
}

void
Object::decrementObjectCount()
{
	//Object::objectCount -= 1;
}

void
Object::incrementObjectCount()
{
	//Object::objectCount += 1;
}

void    Object::notify() {;}
void    Object::notifyAll() {;}
void    Object::wait( long timeout ) {;}
void    Object::wait( long timeout, int nanos ) {;}
void    Object::wait() {;}
void    Object::finalize() {;}

void
Object::startTest()
{
	switch ( Object::test )
	{
	case 0:
		Object::test++;
		Object::lock = new_Mutex();
		//Object::objects = new_Sequence();
		break;
	default:
		Object::test++;
	}
}

void
Object::stopTest()
{
	//unsigned int max = Sequence_count( (ISequence*) Object::objects );
	//fprintf( stderr, "Object::stopDebug(): objects in sequence: %i object count: %lli\n", max, Object::objectCount );

	switch ( Object::test )
	{
	case 0:
		fprintf( stderr, "Object::stopTest(): called on non-testing object, aborting!\n" );
		abort();
		break;
	case 1:
		//free_Sequence( (ISequence*) Object::objects );
		Object::lock->free( Object::lock );
		Object::test--;
		break;
	default:
		Object::test--;
	}
}
