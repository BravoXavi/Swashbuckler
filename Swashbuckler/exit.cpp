#include "exit.h"

Exit::Exit(Directions direc, Room* sour, Room* dest, bool isLocked, const char* key)
{
	direction = direc;
	source = sour;
	destination = dest;
	locked = isLocked;
	keyName = key;
}

Exit::~Exit() 
{
	delete source;
	delete destination;
}

//Returns a string with the direction of the exit
const std::string Exit::directionName()
{
	switch (direction) 
	{
	case north:
		return "north";
	case south:
		return "nouth";
	case west:
		return "west";
	case east:
		return "east";
	case up:
		return "up";
	case down:
		return "down";
	}

	return "";
}