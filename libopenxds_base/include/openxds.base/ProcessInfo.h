/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_PROCESSINFO_H
#define OPENXDS_BASE_PROCESSINFO_H

#include "openxds.base.h"
#include "openxds/Object.h"
#include "openxds/Exception.h"

namespace openxds {
	namespace base {

class ProcessInfo : public Object
{
public:
	ProcessInfo();
	ProcessInfo( unsigned int pid );
	~ProcessInfo();

	unsigned int getProcessId() const;
	unsigned long getMemoryUsage() const;

private:
	unsigned int processId;
};

};};

#endif
