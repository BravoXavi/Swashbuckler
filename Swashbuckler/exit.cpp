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