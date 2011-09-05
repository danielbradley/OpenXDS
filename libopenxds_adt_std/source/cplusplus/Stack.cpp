#include "openxds.adt.std/Stack.h"

using namespace openxds::adt::std;

void createStack();

void createStack()
{
	Stack<char>* stack = new Stack<char>();
	delete stack;
}