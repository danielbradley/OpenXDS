/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_FILEALREADYEXISTSEXCEPTION_H
#define OPENXDS_IO_FILEALREADYEXISTSEXCEPTION_H

#include "openxds.io.h"
#include "openxds.io.exceptions/IOException.h"

#include <openxds.base.h>

namespace openxds {
	namespace io {
		namespace exceptions {
  

class FileAlreadyExistsException : public IOException
{
public:
	virtual ~FileAlreadyExistsException() {}

	virtual const char* getType() const
	{
		return "FileAlreadyExistsException";
	}
};

};};};

#endif
