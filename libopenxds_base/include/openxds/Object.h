/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_OBJECT_H
#define OPENXDS_OBJECT_H

#include <openxds/types.h>
#include <openxds.h>
#include <openxds.core.base.h>
#include <openxds.core.threads.h>

namespace openxds {

class Object
{
protected:
    Object();
    explicit Object( const Object& obj );
public:
    virtual ~Object();

static	long long getObjectCount();

    //Class* getClass() const;

    void notify();
    void notifyAll();
    void wait( long timeout );
    void wait( long timeout, int nanos );
    void wait();
    void finalize();

	static void startTest();
	static void stopTest();

	Object& operator=( Object& );

  protected:
  	void decrementObjectCount();
  	void incrementObjectCount();

  private:
	int objectID;
	
	static  int test;
	static	long long objectCount;
	static void* objects;
	static openxds::core::threads::IMutex* lock;
};
    
};

#endif
