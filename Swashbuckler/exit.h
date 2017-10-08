#ifndef CLASS_EXIT
#define CLASS_EXIT

#include "entity.h"
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

class Exit : public Entity {

private:

public:

	Room* destination;
	directions direction;

	Exit(const char* name, const char* description, Room* destination, directions direction);
	~Exit();


};

#endif // !CLASS_EXIT