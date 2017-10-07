#ifndef CLASS_WORLD
#define CLASS_WORLD

#include <vector>
#include "entity.h"

class World {

private:

public:

	vector<Entity*> worldEntities;

	World();
	~World();

};

#endif // !CLASS_WORLD
