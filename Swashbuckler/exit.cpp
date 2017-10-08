#include <iostream>
#include "exit.h"

using namespace std;

Exit::Exit(const char* exitName, const char* exitDescription) : Entity(exitName, exitDescription)
{
	name = exitName;
	description = exitDescription;
	entityType = exitdir;
}

Exit::~Exit() {}