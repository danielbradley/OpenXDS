/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.base/FormattedString.h"
#include "openxds.base/Runtime.h"

#include <openxds.core.base/CharString.h>
#include <openxds.core.adt.std/StdString.h>

#include <cstdlib>
#include <cstdarg>
#include <cstdio>

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
	int written;
	int size = 10;

	char* tmp;

	va_list ap;
	{
		va_start( ap, format );
		{
			tmp     = (char*) Runtime::calloc( size, sizeof( char ) );
			written = vsnprintf( tmp, size, format, ap );
		}
		va_end(ap);

		if ( written >= size )
		{
			va_start(ap,format);
			{
				Runtime::free( tmp );
				tmp = (char*) Runtime::calloc( written + 1, sizeof( char ) );
				written = vsnprintf( tmp, written + 1, format, ap );
			}
			va_end(ap);
		}

		free_StdString( (StdString*) this->_data );
		this->_data = new_StdString( tmp );
		Runtime::free( tmp );
		this->chars = this->getChars();
	}
}

FormattedString::~FormattedString()
{
}
