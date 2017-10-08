#include <iostream>
#include "exit.h"

using namespace std;

Exit::Exit(Directions direc, Room* sour, Room* dest)
{
	direction = direc;
	source = sour;
	destination = dest;
}

Exit::~Exit() {}