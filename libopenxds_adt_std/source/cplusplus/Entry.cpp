#include "openxds.adt.std/Entry.h"
#include <openxds.core.adt/IEntry.h>
#include <openxds.base/Runtime.h>

using namespace openxds::adt::std;
using namespace openxds::base;

struct _Entry
{
	openxds::core::adt::IEntry super;
	int rank;
};

void createEntry();

void createEntry()
{
	openxds::core::adt::IEntry* e = (openxds::core::adt::IEntry*) Runtime::calloc( 1, sizeof( struct _Entry ) );
	Entry<char>* entry = new Entry<char>( e );
	delete entry;
}