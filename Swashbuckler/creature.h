#ifndef CLASS_CREATURE
#define CLASS_CREATURE

#include "entity.h"
#include "room.h"

class Creature : public Entity {

private:

public:
	Creature(const char* name, const char* description);
	~Creature();

	Room* location;

};

#endif // !CLASS_CREATURE
