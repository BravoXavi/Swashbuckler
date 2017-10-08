#ifndef CLASS_EXIT
#define CLASS_EXIT

#include "entity.h"
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

class Exit : public Entity{

private:

public:

	Directions direction;

	Exit(const char* name, const char* description, Directions direction);
	~Exit();


};

#endif // !CLASS_EXIT