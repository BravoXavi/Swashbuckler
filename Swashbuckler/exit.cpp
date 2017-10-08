#include <iostream>
#include "exit.h"
#include "room.h"

using namespace std;

Exit::Exit(const char* exitName, const char* exitDescription, Directions direc) : Entity(exitName, exitDescription)
{
	name = exitName;
	description = exitDescription;
	direction = direc;
}

Exit::~Exit() {}