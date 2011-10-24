/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_UTIL_ARGUMENTS_H
#define OPENXDS_UTIL_ARGUMENTS_H

#include <openxds/Object.h>

#include <openxds.adt.h>
#include <openxds.base.h>
#include <openxds.util.h>

namespace openxds {
	namespace util {
  
class Arguments : public openxds::Object
{
typedef const char* c_charPtr;

private:
	openxds::adt::ISequence<openxds::base::String>*   arguments;
	openxds::adt::IDictionary<int>*                   required;
	openxds::adt::IDictionary<int>*                   optional;
	openxds::base::String*                            command;
	openxds::adt::IDictionary<openxds::base::String>* options;
	openxds::adt::ISequence<openxds::base::String>*   files;
public:
	/**
	 *  Create an arguments object using the standard C arguments. <p>
	 */
	Arguments( int argc, const c_charPtr* argv );
	Arguments( const char* arguments );
	virtual ~Arguments();

	void addRequired( const char* key, int expectedNr );
	void addOptional( const char* key, int expectedNr );

	const openxds::base::String& getCommand() const;
	
	/**
	 *  Returns a properties object that maps each argument to the next
	 *  argument. <p>
	 *
	 *  <pre>
	 *  Example:
	 *
	 *  "command -v -l -c hero -x" would generate:
	 *
	 *  props {
	 *    "command" --> "-v"
	 *    "-v"      --> "-l"
	 *    "-l"      --> "-c"
	 *    "-c"      --> "hero"
	 *    "hero"    --> "-x"
	 *    "-x"      --> null
	 *  }
	 *  </pre>
	 */
	virtual const openxds::adt::IDictionary<openxds::base::String>& parsedOptions() const;
	virtual const       openxds::adt::IList<openxds::base::String>&   parsedFiles() const;

	//int   getNrOfArguments() const; what does this mean?
	bool           isValid() const;
	bool         hasOption( const char* key ) const;
	const openxds::base::String& getOptionValue( const char* key ) const;

private:
	int evaluateArgument( const openxds::base::String& s ) const;


};

};};

#endif // _OPENOCL_UTIL_ARGUMENTS_H_

