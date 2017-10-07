#ifndef CLASS_ROOM
#define CLASS_ROOM

#include "entity.h"

class Room: public Entity {

private:

public:
	Room(const char* name, const char* description);
	~Room();

	void checkRoom();
};

#endif // !CLASS_ROOM
