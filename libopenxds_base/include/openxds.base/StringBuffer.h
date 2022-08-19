/*
 *  Copyright (C) 1997-2009 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#ifndef OPENXDS_BASE_STRINGBUFFER_H
#define OPENXDS_BASE_STRINGBUFFER_H

#include <openxds/Object.h>

#include <openxds.base.h>
#include <openxds.base_exceptions.h>

namespace openxds {
	namespace base {

class StringBuffer : public openxds::Object
{
public:
	StringBuffer();
	~StringBuffer();

	void clear();

	void append( long character );
	void append( const char* aCString );
	void appendHex( const char* aCString );

	/**
	*  Appends the characters of the string referenced to the
	*  StringBuffer.
	*/ 
	void append( const String& aString );
//	void append( const Object& aString );

	void insertCharAt( int index, unsigned int value )
	  throw (openxds::exceptions::IndexOutOfBoundsException*);
	void removeCharAt( int index )
	  throw (openxds::exceptions::IndexOutOfBoundsException*);
	void removeLast();

	int remove( char ch );
	int replace( char ch, char chx );

	virtual openxds::Object* clone() const;
	String* asString() const;
	const String& getContent() const;

	char charAt( int index ) const
	  throw (openxds::exceptions::IndexOutOfBoundsException*);

	const char* getChars() const;
	int getLength() const;

private:
	void initialize( int size );
	bool isFull() const;
	void expand();
	void shuffleUp( int index );
	void shuffleDown( int index );

	int   capacity;
	int   length;
	char* data;

	String* tmp;
};

};};

#endif
