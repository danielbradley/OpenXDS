/*
 *  Copyright (C) 1997-2011 Daniel Robert Bradley. All rights reserved.
 *
 *  This software is redistributable under the terms of the GNU LGPL
 *  (Lesser General Public License).
 *
 *  I.S.Labs is a registered trademark of Daniel Robert Bradley
 */

#include "openxds.util/Arguments.h"

#include <openxds.adt/IDictionary.h>
#include <openxds.adt/ISequence.h>
#include <openxds.adt.std/Dictionary.h>
#include <openxds.adt.std/Sequence.h>
#include <openxds.base/Runtime.h>
#include <openxds.base/StringTokenizer.h>
#include <openxds.base/Runtime.h>

using namespace openxds::adt;
using namespace openxds::adt::std;
using namespace openxds::base;
using namespace openxds::exceptions;
using namespace openxds::util;

Arguments::Arguments( int argc, const c_charPtr* argv )
{
	this->arguments = new Sequence<String>();
	this->required  = new Dictionary<int>();
	this->optional  = new Dictionary<int>();
	this->options   = NULL;
	this->files     = NULL;

	switch ( argc )
	{
	case 0:
		this->command = new String();
		break;
	case 1:
		this->command = new String( argv[0] );
		break;
	default:
		this->command = new String( argv[0] );
		for ( int i=1; i < argc; i++ )
		{
			this->arguments->addLast( new String( argv[i] ) );
		}
	}
}

Arguments::Arguments( const char* arguments )
{
	this->arguments = new Sequence<String>();
	this->required  = new Dictionary<int>();
	this->optional  = new Dictionary<int>();
	this->options   = NULL;
	this->files     = NULL;

	StringTokenizer st( arguments );
	st.setDelimiter( ' ' );
	
	if ( st.hasMoreTokens() )
	{
		this->command = st.nextToken();
	}
	
	while ( st.hasMoreTokens() )
	{
		this->arguments->addLast( st.nextToken() );
	}
}

Arguments::~Arguments()
{
	delete this->arguments;
	delete this->required;
	delete this->optional;
	delete this->command;
	delete this->options;
	delete this->files;
}

void
Arguments::addRequired( const char* key, int expectedNr )
{
	int* nr = (int*) Runtime::calloc( 1, sizeof(int) );
	*nr = expectedNr;

	this->required->insert( key, nr );
}

void
Arguments::addOptional( const char* key, int expectedNr )
{
	int* nr = (int*) Runtime::calloc( 1, sizeof(int) );
	*nr = expectedNr;

	this->optional->insert( key, nr );
}

const String&
Arguments::getCommand() const
{
	return *this->command;
}

const IDictionary<String>&
Arguments::parsedOptions() const
{
	if ( !this->options )
	{
		IDictionary<String>* options = new Dictionary<String>();
		{
			String* key   = NULL;
			String* value = NULL;
		
			IPIterator<String>* it = this->arguments->positions();
			{
				if ( it->hasNext() )
				{
					IPosition<String>* p = it->next();
					{
						value = p->getElement().asString();
					}
					delete p;
				}
			
				while ( it->hasNext() )
				{
					IPosition<String>* p = it->next();
					{
						key   = value;
						value = p->getElement().asString();
					
						options->insert( key->getChars(), value->asString() );
					}
					delete p;
				}

				options->insert( value->getChars(), new String() );
			}
			delete it;
			
			delete key;
			delete value;
		}
		
		const_cast<Arguments*>( this )->options = options;
	}
	return *options;
}

int
Arguments::evaluateArgument( const String& s ) const
{
	int skip = 0;

	if ( s.startsWith( "-" ) )
	{
		try
		{
			IEntry<int>* e = this->required->find( s.getChars() );
			{
				skip = e->getValue();
			}
			delete e;
		}
		catch ( NoSuchElementException* ex )
		{
			delete ex;
			
			try
			{
				IEntry<int>* e = this->optional->find( s.getChars() );
				{
					skip = e->getValue();
				}
				delete e;
			}
			catch ( NoSuchElementException* ex )
			{
				delete ex;
			}
		}
	}
	
	return skip;
}


const IList<String>&
Arguments::parsedFiles() const
{
	if ( !this->files )
	{
		ISequence<String>* files = new Sequence<String>();
		{
			IPIterator<String>* it = this->arguments->positions();
			{
				bool add_rest = false;
			
				while ( it->hasNext() )
				{
					IPosition<String>* p = it->next();
					{
						const String& s = p->getElement();
						
						if ( s.contentEquals( "-" ) )
						{
							add_rest = true;
						}
						else if ( !add_rest && s.startsWith( "-" ) )
						{
							int n = this->evaluateArgument( s );
							
							for ( int i=0; i < n; i++ )
							{
								if ( it->hasNext() ) delete it->next();
							}
						} else {
							files->addLast( s.asString() );
						}
					}
					delete p;
				}
			}
			delete it;
		}
		const_cast<Arguments*>( this )->files = files;
		
	}
	return *files;
}


//int
//Arguments::getNrOfArguments() const
//{
//	return 0;
//}


bool
Arguments::isValid() const
{
	bool valid = true;

	const IDictionary<String>& options = this->parsedOptions();
	{
		IEIterator<int>* ie = this->required->entries();
		bool loop = true;
		while ( loop && ie->hasNext() )
		{
			IEntry<int>* e = ie->next();
			{
				try
				{
					delete options.find( e->getKey() );
				}
				catch ( NoSuchElementException* ex )
				{
					delete ex;
					valid = false;
					loop  = false;
				}
			}
			delete e;
		}
		delete ie;
	}

	return valid;
}

bool
Arguments::hasOption( const char* key ) const
{
	bool ret = false;

	try
	{
		delete this->parsedOptions().find( key );
		ret = true;
	}
	catch ( Exception* ex )
	{
		delete ex;
	}
	
	return ret;
}

const String&
Arguments::getOptionValue( const char* key ) const
{
	const IEntry<String>* e = this->parsedOptions().find( key );
	const String& ret = e->getValue();
	delete e;
	return ret;
}


