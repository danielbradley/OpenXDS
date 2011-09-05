/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_SYSTEM_H
#define OPENXDS_BASE_SYSTEM_H

#include <openxds/Object.h>
#include <openxds.base.h>

namespace openxds {
  namespace base {

class System : public Object //: public Serializable
{
public:
	//---------------------------------------------------------------------------
	//  Time Operations
	//---------------------------------------------------------------------------

	static long getTimeAsInt();
	static unsigned long getClockCyclesUsed();
	static unsigned long long getMicroSecondsSinceEpoch();
	static unsigned long long getSecondsSinceEpoch();

  //---------------------------------------------------------------------------
  //  Signals
  //---------------------------------------------------------------------------

  static void (*setSignal(int signum, void (*handler)(int)))(int);
  static void (*resetSignal(int signum) )(int);

  static int setAlarm( unsigned int seconds );
  static int resetAlarm();

  static const int SIGNAL_ALARM; //SIGALRM;

  static const bool Debug;

};

};};

#endif
