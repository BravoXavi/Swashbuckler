#ifndef CLASS_ROOM
#define CLASS_ROOM

#include <vector>
#include "entity.h"

class Exit;

class Room: public Entity {

public:
	Room(const char* name, const char* description);
	~Room();

public:
	std::vector<Exit*> exits;

};

#endif // !CLASS_ROOM
