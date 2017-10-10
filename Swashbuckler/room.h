#ifndef CLASS_ROOM
#define CLASS_ROOM

#include "entity.h"
#include "exit.h" //esto no tiene porque ser necesario -> Forward Declaration
#include <vector>

class Exit;

class Room: public Entity {

private:

public:
	Room(const char* name, const char* description);
	~Room();

	vector<Exit*> exits;

	void checkRoom();
};

#endif // !CLASS_ROOM
