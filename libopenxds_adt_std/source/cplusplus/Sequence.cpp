#include "openxds.adt/IPosition.h"
#include "openxds.adt.std/Sequence.h"
#include <openxds.base/Runtime.h>

using namespace openxds::adt::std;
using namespace openxds::base;

void createSequence();

void createSequence()
{
	Sequence<char>* sequence = new Sequence<char>();
	delete sequence;
}