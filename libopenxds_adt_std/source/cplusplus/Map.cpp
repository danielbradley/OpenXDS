#include "openxds.adt.std/Map.h"
#include <openxds.base/Runtime.h>
#include <openxds.base/String.h>

using namespace openxds::adt::std;
using namespace openxds::base;

void createMap();

void createMap()
{
	Map<String>* map = new Map<String>();
	delete map;
}