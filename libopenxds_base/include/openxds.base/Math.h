/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_MATH_H
#define OPENXDS_BASE_MATH_H

#include "openxds.base.h"
#include "openxds/Object.h"

namespace openxds {
	namespace base {

class Math : public Object
{
public:
	static double pi();
	static double floor( double aNumber );
	static double roof( double aNumber );

	static long min( long n1, long n2 );
	static long max( long n1, long n2 );
	static long between( long aNumber, long lower, long higher );

	static double toPower( double base, double power );
	static double squareroot( double value );

	static int roundToInteger( double aNumber );

	static long sizeOfRange( double first, double last, double increment ); 
	static bool almostEqual( double A, double B );

private:
	static const double PI;

};

};};

#endif
