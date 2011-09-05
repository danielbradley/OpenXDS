/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_SECURITY_H
#define OPENXDS_SECURITY_H

#include <openxds/types.h>

namespace openxds {
	namespace security {
  
class PUBLIC PrivilegedAttribute;
class PUBLIC SecurityAttribute;
class PUBLIC Principal;

class PUBLIC Right;
class PUBLIC RightsList;

class PUBLIC Policy;
class PUBLIC AccessPolicy;
class PUBLIC AccessControlList;

class PUBLIC AccessException;

};};

#endif
