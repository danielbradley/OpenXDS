#include "openxds.adt.std/Position.h"
#include <openxds.core.adt/IPosition.h>
#include <openxds.base/Runtime.h>

using namespace openxds::adt::std;
using namespace openxds::base;

struct _Position
{
	openxds::core::adt::IPosition super;
	int rank;
};

void createPosition();

void createPosition()
{
	openxds::core::adt::IPosition* p = (openxds::core::adt::IPosition*) Runtime::calloc( 1, sizeof( struct _Position ) );
	Position<char>* position = new Position<char>( p );
	delete position;
}