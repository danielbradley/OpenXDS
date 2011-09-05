#include "openxds.adt.std/Tree.h"
#include <openxds.base/Runtime.h>

using namespace openxds::adt::std;
using namespace openxds::base;

void createTree();

void createTree()
{
	Tree<char>* tree = new Tree<char>();
	delete tree;
}