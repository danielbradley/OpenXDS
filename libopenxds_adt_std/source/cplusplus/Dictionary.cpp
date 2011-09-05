#include "openxds.adt.std/Dictionary.h"
#include <openxds.base/Runtime.h>

using namespace openxds::adt::std;
using namespace openxds::base;

void createDictionary();

void createDictionary()
{
	Dictionary<char>* dir = new Dictionary<char>();
	delete dir;
}