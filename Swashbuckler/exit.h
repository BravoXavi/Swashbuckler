#ifndef CLASS_EXIT
#define CLASS_EXIT

#include "room.h"

enum  directions
{
	north,
	south,
	west,
	east,
	up,
	down
};

class Exit {

private:

public:

	Room* destination;
	directions direction;

	Exit(Room* destination, directions direction);
	~Exit();


};

#endif // !CLASS_EXIT