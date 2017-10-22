#ifndef CLASS_EXIT
#define CLASS_EXIT

#include "room.h"

enum Directions
{
	north,
	south,
	west,
	east,
	up,
	down
};

class Room;

class Exit {

public:
	Exit(Directions direction, Room* source, Room* destination);
	~Exit();

	std::string directionName();

public:
	Room* destination;
	Directions direction;

private:
	Room* source;
	
};

#endif // !CLASS_EXIT