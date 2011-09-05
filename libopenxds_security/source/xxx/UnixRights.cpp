/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds/security/posix/UnixRights.h>

#include <openxds/base/String.h>
#include <openxds/security/Right.h>

using namespace openxds::base;
using namespace openxds::security;
using namespace openxds::security::posix;

const Right* UnixRights::READ = new Right( "unix", "r" );
const Right* UnixRights::WRITE = new Right( "unix", "w" );
const Right* UnixRights::EXECUTE = new Right( "unix", "x" );
