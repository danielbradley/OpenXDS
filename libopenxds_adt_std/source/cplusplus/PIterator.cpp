#include "openxds.adt.std/PIterator.h"
#include <openxds.core.adt/IList.h>
#include <openxds.core.adt.std/StdADTFactory.h>
#include <openxds.base/Runtime.h>

using namespace openxds::adt::std;
using namespace openxds::base;

void createIterator();

void createIterator()
{
	openxds::core::adt::IList* list    = openxds::core::adt::std::StdADTFactory_createList();
	openxds::core::adt::IPIterator* ipit = list->positions( list ); 
	PIterator<char>* it = new PIterator<char>( ipit );
	delete it;
}