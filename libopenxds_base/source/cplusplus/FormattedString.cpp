/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.base/FormattedString.h"

#include <openxds.core.base/CharString.h>
#include <openxds.core.adt.std/StdString.h>

#include <cstdlib>
#include <cstdarg>
//#include <cstring>

/**
 *  This tells the compiler that class String has been declared
 *  within the particular namespace. <p>
 */  
using namespace openxds::base;
using namespace openxds::core::adt;
using namespace openxds::core::adt::std;
using namespace openxds::core::base;

FormattedString::FormattedString( const char* format, ... ) : String()
{
	char* tmp;

	va_list ap;
	va_start( ap, format );

	tmp = new_CharString_format_valist( format, ap );
	{
		free_StdString( (StdString*) this->_data );
		this->_data = new_StdString( tmp );
	}
	free_CharString( tmp );

	va_end( ap );
}

FormattedString::~FormattedString()
{
}
