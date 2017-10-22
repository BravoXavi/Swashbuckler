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

//Returns a Direction enum matching a string
const Directions Exit::directionNameEnum(const char* dir)
{
	if (strcmp(dir, "north") == 0) return north;
	else if (strcmp(dir, "south") == 0) return south;
	else if (strcmp(dir, "west") == 0) return west;
	else if (strcmp(dir, "east") == 0) return east;
	else if (strcmp(dir, "up") == 0) return up;
	else if (strcmp(dir, "down") == 0) return down;
	else return north;
}