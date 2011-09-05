/* 
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_EXCEPTIONS_H
#define OPENXDS_EXCEPTIONS_H

#include "openxds/types.h"
#include "openxds/global.h"

namespace openxds {
	namespace exceptions {

static const bool BASE_DEBUG = true;

class PUBLIC Exception;
class PUBLIC CollisionException;
class PUBLIC ImplementationException;
class PUBLIC IndexOutOfBoundsException;
class PUBLIC NonCloneableException;
class PUBLIC NonComparableException;
class PUBLIC NoSuchElementException;
class PUBLIC NullPointerException;
class PUBLIC ParameterException;
class PUBLIC RuntimeException;
class PUBLIC SemanticException;
class PUBLIC Error;

};};

#endif
