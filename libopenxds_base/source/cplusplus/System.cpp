/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.base/System.h>
#include <openxds.exceptions/ImplementationException.h>
#include <openxds.base/String.h>
#include <openxds.core.base/CRuntime.h>
#include <openxds.core.base/Clock.h>

using namespace openxds::base;
using namespace openxds::exceptions;
using namespace openxds::core::base;

const int System::SIGNAL_ALARM = 0;
const bool System::Debug = false;

//-----------------------------------------------------------------------------
//  Time Operations
//-----------------------------------------------------------------------------

long System::getTimeAsInt()
{
	return Clock_GetTimeAsInt();
}

unsigned long
System::getClockCyclesUsed()
{
	return Clock_GetClockCyclesUsed();
}

unsigned long long
System::getMicroSecondsSinceEpoch()
{
	return Clock_GetMicroSecondsSinceEpoch();
}

unsigned long long
System::getSecondsSinceEpoch()
{
	return Clock_GetSecondsSinceEpoch();
}

//-----------------------------------------------------------------------------
//  Signals
//-----------------------------------------------------------------------------

void (*System::setSignal(int signum, void (*handler)(int)))(int)
{
  throw new ImplementationException(); //return BasePSA::SetSignal( signum, handler );
}

void (*System::resetSignal(int signum) )(int)
{
  throw new ImplementationException(); //return BasePSA::ResetSignal( signum );
}

int System::setAlarm( unsigned int seconds )
{
  throw new ImplementationException(); //return BasePSA::SetAlarm( seconds );
}

int System::resetAlarm()
{
  throw new ImplementationException(); //return BasePSA::ResetAlarm();
}
