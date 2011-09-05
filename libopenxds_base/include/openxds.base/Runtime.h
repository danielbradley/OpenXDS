/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_RUNTIME_H
#define OPENXDS_BASE_RUNTIME_H

#include "openxds.base/String.h"
#include "openxds.base.h"
#include "openxds.testing.h"
#include "openxds/Object.h"

#include <openxds.core.threads.h>

namespace openxds {
	namespace base {

class Runtime : public Object
{
friend class Debug;
friend class openxds::testing::Testing;
public:
	Runtime();
	virtual ~Runtime();

	static void* malloc( size_t size );
	static void* calloc( size_t nmemb, size_t size );
	static void* realloc( void* ptr, size_t size );
	static void  free( void* ptr );

	unsigned long getUpTime() const;
	unsigned long getUserTime() const;
	unsigned long getSystemTime() const;

	//unsigned long getChildUserTime();
	//unsigned long getChildSystemTime();

	static	long long   getAllocationCount();
	static	long long   getCRuntimeAllocationCount();
	static  void        sleepFor( unsigned int seconds );
	static  void        microSleepFor( unsigned int microseconds );
	static  void        printMemorySummary( void* f );

	static void startTest();
	static void stopTest();

private:

#ifdef OPENOCL_USE_DEBUG_NEW_AND_DELETE
public:
#endif

static  void incrementAllocationCount();
static  void decrementAllocationCount();
static  bool test;

private:
static  openxds::core::threads::IMutex*     lock;
static	long long	allocationCount;
};

};};

#endif
