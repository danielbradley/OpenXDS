/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_IO_LINEPARSER_H
#define OPENXDS_IO_LINEPARSER_H

#include "openxds.io.h"
#include "openxds.adt.h"
#include <openxds.base.h>
#include <openxds.exceptions/NoSuchElementException.h>
#include <openxds/Object.h>

namespace openxds {
	namespace io {

/**
 *  Class LineParser extends Object
 *
 *  Used to be roughly equivalent to a java.io.LineNumberReader.
 *
 *  LineParser lp( istream );
 *  lp.parseLine()
 *  if ( lp.nrOfTokens > 0 )
 *  {
 *    print lp.tokens->get( 0 );
 *  }
 */
class LineParser : public openxds::Object
{
public:
	LineParser( const InputStream& in );
	LineParser( InputStream* in );
	~LineParser();

	openxds::base::String* readLine();
	
	void parseLine();
	
	void setDelimiter( char aCharacter );

	const openxds::base::String& getToken( unsigned int posn ) const
		throw (openxds::exceptions::NoSuchElementException*);
	
	int getLineNumber() const;
	bool hasFinished() const;
	//virtual openxds::base::Object* clone() const;

	// During processing
	openxds::adt::ISequence<openxds::base::String>* tokens;

private:

	bool isReference;
	const InputStream* inputStream;
	int lineNumber;
	byte delimiter;

	bool finished;
};

};};

#endif
