#include <iostream>
#include "exit.h"

using namespace std;

Exit::Exit(Room* dest, directions direc)
{
	destination = dest;
	direction = direc;
}

Exit::~Exit() {}