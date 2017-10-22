#include "exit.h"

Exit::Exit(Directions direc, Room* sour, Room* dest)
{
	direction = direc;
	source = sour;
	destination = dest;
}

Exit::~Exit() 
{
	delete source;
	delete destination;
}