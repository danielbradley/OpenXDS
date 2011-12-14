//
//  Argo.cpp
//  libopenxds_base
//
//  Created by Daniel Bradley on 2/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <openxds.base/Character.h>
#include <openxds.base/DynamicBuffer.h>
#include <openxds.base/Math.h>
#include <openxds.base/ProcessInfo.h>
#include <openxds.base/Runtime.h>
#include <openxds.base/String.h>
#include <openxds.base/StringBuffer.h>
#include <openxds.base/StringTokenizer.h>
#include <openxds.base/System.h>

#include <openxds.exceptions/ImplementationException.h>
#include <openxds.exceptions/IndexOutOfBoundsException.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds.exceptions/NonCloneableException.h>
#include <openxds.exceptions/SemanticException.h>
#include <openxds/Exception.h>
#include <openxds/ICloneable.h>
#include <openxds/IException.h>
#include <openxds/Interface.h>
#include <openxds/Object.h>
#include <openxds/RuntimeException.h>
#include <openxds/global.h>
#include <openxds/types.h>
#include <openxds.base.h>
#include <openxds.h>
#include <openxds.core.base/CharString.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace openxds::core::base;

void doSomething();

void doSomething()
{
	const char* ch = new_CharString( "Hello World" );
	fprintf( stdout, "%s\n", ch );

}