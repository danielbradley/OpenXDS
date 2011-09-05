#include "openxds.adt.std/Stack.h"

using namespace openxds::adt::std;

static void createStack()
{
	Stack<char>* stack = new Stack<char>();
	delete stack;
}