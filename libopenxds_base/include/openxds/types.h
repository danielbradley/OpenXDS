/* 
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_TYPES_H
#define OPENXDS_TYPES_H

/**
 *  types.h
 *
 *  This file specifies constant types.
 */

//#include <openxds/base/psa/export.h>
#include <sys/types.h>

#ifdef __c_plus_plus
#include <new>
#endif

//#ifdef WIN32
//  #pragma warning( disable : 4290 ) 
//#endif

#ifndef OPENXDS_BYTE
#define OPENXDS_BYTE
  typedef unsigned char byte;
#endif

#ifndef OPENXDS_FLAGS
#define OPENXDS_FLAGS
  typedef unsigned long int flags;
#endif

#ifndef OPENXDS_MASK
#define OPENXDS_MASK
  typedef unsigned long int mask;
#endif

//
//  This is used so the the same headers may be used in
//  Windows and Unix.
//

#ifdef _WIN32
#define PUBLIC __declspec( dllexport )
#else
#define PUBLIC
#endif

//
//  If OPENXDS_DEBUG is defined e.g. build -D OPENXDS_DEBUG
//  special version of new and delete will be used that
//  count memory allocations.
//

#ifdef OPENXDS_DEBUG
#ifndef _WIN32
#define OPENXDS_USE_DEBUG_NEW_AND_DELETE
#endif
#endif

//
//  This creates a "test:" keyword that when OPENXDS_TEST is defined
//  makes methods public.
//

#ifdef OPENXDS_TEST
#define TEST public:
#define protected public
#define private public
#else
	#define TEST
#endif

namespace openxds {

#ifdef _WIN32
#define OPENXDS_LITTLE_ENDIAN
#endif

#ifdef OPENXDS_LITTLE_ENDIAN
	struct _OPENXDSWordBytes
	{
		byte b0;
		byte b1;
		byte b2;
		byte b3;
	};
#else
	struct _OPENXDSWordBytes
	{
		byte b3;
		byte b2;
		byte b1;
		byte b0;
	};
#endif
	union OPENXDSWord
	{
		struct _OPENXDSWordBytes bytes;
		unsigned long    word;
	};
};
//#define Release(pointer) { delete( pointer ); pointer = null; }
//#ifndef Destroy
//#define Destroy(pointer) { delete pointer; pointer = null; }
//#define DestroyArray( pointer ) { delete[] pointer; pointer = null; }
//#endif

//static const int null = 0;
//static unsigned int null = 0;

#define null 0

//
// This makes abstract a keyword. But allows classes to
// be declared abstract to make class definitions
// clearer.
//
#define abstract

#endif // _OPENXDS_TYPES_H_

