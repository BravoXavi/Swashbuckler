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
	Exit(Directions direction, Room* source, Room* destination, bool locked, const char* keyName);
	~Exit();

	const std::string directionName();
	const Directions directionNameEnum(const char* dir);

public:
	Room* destination;
	Directions direction;
	bool locked;
	const char* keyName;

private:
	Room* source;
	
};

#endif // !CLASS_EXIT