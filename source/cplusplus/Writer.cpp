/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include <openxds.io/Writer.h>
#include <openxds.io.exceptions/IOException.h>

using namespace openxds::io;
using namespace openxds::io::exceptions;

const int Writer::EOL = '\n';

Writer::~Writer() throw (IOException*)
{
}
