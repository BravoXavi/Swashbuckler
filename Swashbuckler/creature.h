#ifndef CLASS_CREATURE
#define CLASS_CREATURE

#include "entity.h"
#include "room.h"

class Creature : public Entity {

private:

public:
	Room* location;

	Creature(const char* name, const char* description, Room* location);
	~Creature();

	

};

#endif // !CLASS_CREATURE
