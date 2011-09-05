/*
 *  Copyright (C) 1997-2004 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef _OPENOCL_IO_STATISTICS_H_
#define _OPENOCL_IO_STATISTICS_H_

#include <openxds/base/Object.h>

#include <openxds/io.h>
#include <openxds/security.h>

namespace openxds {
  namespace io {

class Statistics : public openxds::base::Object
{
friend class File;
friend class StatPSA;
public:
  virtual ~Statistics();

  const Address& getAddress() const;

  bool equals( const openxds::base::Object& anObject ) const; 
  //virtual openxds::base::Object* clone() const;
  virtual openxds::base::String* toString() const;

protected:
  Statistics();
  void setAddress( Address* anAddress );

  Address* address;

  unsigned int links;

  openxds::security::Principal* owner;
  openxds::security::AccessControlList* acl;

  unsigned int size;
  unsigned long blockSize;
  unsigned long blocks;

  //Time* lastAccess;
  //Time* lastModification;
  //Time* lastChange;
};

};};

#endif
