#ifndef CLASS_WORLD
#define CLASS_WORLD

#include <vector>
#include <string>
#include "entity.h"
#include "player.h"

class World {

private:

public:

	vector<Entity*> worldEntities;
	Player* mainguy;

	World();
	~World();

	void readInput(vector<string> userInput);
};

#endif // !CLASS_WORLD
