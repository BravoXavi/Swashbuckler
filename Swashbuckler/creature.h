#ifndef CLASS_CREATURE
#define CLASS_CREATURE

#include "entity.h"
#include "room.h"

class Creature : public Entity {

public:	
	Creature(const char* name, const char* description, Room* location);
	~Creature();

	Room* location;

private:

};

#endif // !CLASS_CREATURE
