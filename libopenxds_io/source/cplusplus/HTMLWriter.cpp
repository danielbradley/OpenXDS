/*
 *  Copyright (C) 2013 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.base/StringBuffer.h>
#include <openxds.io/HTMLWriter.h>
#include <openxds.io/OutputStream.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

using namespace openxds::base;
using namespace openxds::core::base;
using namespace openxds::io;
using namespace openxds::io::exceptions;

HTMLWriter::HTMLWriter( OutputStream& ostream ) : PrintWriter( ostream )
{}

HTMLWriter::HTMLWriter( OutputStream* ostream ) : PrintWriter( ostream )
{}

HTMLWriter::~HTMLWriter() throw (IOException*)
{}

void
HTMLWriter::write( const char* characters, long offset, long count ) const
throw (IOException*)
{
	StringBuffer sb;

	for ( long i = 0; i < count; i++ )
	{
		unsigned char ch = characters[offset + i];
		switch ( ch )
		{
		case 0:
			i = count;
			break;

		case 195:
			break;

		case 160:
			sb.append( "&agrave;" );
			break;

		case 161:
			sb.append( "&aacute;" );
			break;

		case 162:
			sb.append( "&acirc;" );
			break;

		case 163:
			sb.append( "&atilde;" );
			break;

		case 164:
			sb.append( "&auml;" );
			break;

		case 165:
			sb.append( "&aring;" );
			break;

		case 166:
			sb.append( "&aelig;" );
			break;

		case 167:
			sb.append( "&ccedil;" );
			break;

		case 168:
			sb.append( "&egrave;" );
			break;

		case 169:
			sb.append( "&eacute;" );
			break;

		case 170:
			sb.append( "&ecirc;" );
			break;

		case 171:
			sb.append( "&euml;" );
			break;

		default:
			if ( ch > 127 ) fprintf( stderr, "%c == %u\n", ch, ch );
		
			sb.append( ch );
		}
	}

	const char* sb_chars = sb.getChars();
	long        sb_len   = sb.getLength();

	this->PrintWriter::write( sb_chars, 0, sb_len );
}
