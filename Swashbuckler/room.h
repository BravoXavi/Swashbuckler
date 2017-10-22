#ifndef CLASS_ROOM
#define CLASS_ROOM

#include "entity.h"
#include "exit.h"
#include <vector>

class Exit;

class Room: public Entity {

public:
	Room(const char* name, const char* description);
	~Room();

	const void checkRoom();

public:
	std::vector<Exit*> exits;

};

#endif // !CLASS_ROOM
