/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.base/Math.h"
#include <openxds.core.base/Math.h>
#include <cstdlib>

using namespace openxds::base;
using namespace openxds::core::base;

double
Math::pi()
{
	return Math_pi();
}

double
Math::floor( double aNumber )
{
	return Math_floor( aNumber );
}

double
Math::roof( double aNumber )
{
	abort();
}

long
Math::min( long n1, long n2 )
{
	return Math_min( n1, n2 );
}

long
Math::max( long n1, long n2 )
{
	return Math_max( n1, n2 );
}

long
Math::between( long aNumber, long lower, long upper )
{
	return Math_constrainBetween( aNumber, lower, upper );
}

double
Math::toPower( double base, double power )
{
	return Math_toPower( base, power );
}

double
Math::squareroot( double value )
{
	return Math_squareroot( value );
}

long
Math::sizeOfRange( double first, double last, double increment )
{
	return Math_sizeOfRange( first, last, increment );
}

bool
Math::almostEqual( double a, double b )
{
	return Math_isAlmostEqual( a, b );
}
