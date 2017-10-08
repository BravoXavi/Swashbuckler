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

private:

public:

	Room* source;
	Room* destination;
	Directions direction;

	Exit(Directions direction, Room* source, Room* destination);
	~Exit();


};

#endif // !CLASS_EXIT