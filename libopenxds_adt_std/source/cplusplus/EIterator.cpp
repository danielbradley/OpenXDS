#include "openxds.adt.std/EIterator.h"
#include <openxds.core.adt/IDictionary.h>
#include <openxds.core.adt.std/StdADTFactory.h>
#include <openxds.base/Runtime.h>

using namespace openxds::adt::std;
using namespace openxds::base;

void createEIterator();

void createEIterator()
{
	openxds::core::adt::IDictionary* dict = openxds::core::adt::std::StdADTFactory_createDictionary();
	openxds::core::adt::IEIterator*    it = dict->entries( dict ); 
	EIterator<char>* it2 = new EIterator<char>( it );
	delete it2;
}