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

	std::vector<Exit*> exits;

private:

};

#endif // !CLASS_ROOM
