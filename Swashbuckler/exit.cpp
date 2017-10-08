#include <iostream>
#include "exit.h"

using namespace std;

Exit::Exit(const char* exitName, const char* exitDescription, Room* dest, directions direc) : Entity(exitName, exitDescription)
{
	name = exitName;
	description = exitDescription;
	entityType = exitdir;
	destination = dest;
	direction = direc;
}

Exit::~Exit() {}