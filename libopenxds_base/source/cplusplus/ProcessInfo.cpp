/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.base.h"
#include "openxds.base/ProcessInfo.h"

#include "openxds.base/String.h"

#include "openxds.core.base/Process.h"

using namespace openxds::base;

ProcessInfo::ProcessInfo()
{
	this->processId = openxds::core::base::Process_GetCurrentID();
}

ProcessInfo::ProcessInfo( unsigned int pid )
{
	this->processId = pid;
}

ProcessInfo::~ProcessInfo()
{}

unsigned int
ProcessInfo::getProcessId() const
{
	return this->processId;
}

unsigned long
ProcessInfo::getMemoryUsage() const
{
	return 0; //ProcessPSA::GetMemoryUsage();
}
