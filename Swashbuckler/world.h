#ifndef CLASS_WORLD
#define CLASS_WORLD

#include <vector>
#include <string>
#include "entity.h"
#include "player.h"

class World {

public:
	World();
	~World();

	void readInput(std::vector<std::string> userInput);
	void ending();

	std::vector<Entity*> worldEntities;
	Player* mainguy;

private:

};

#endif // !CLASS_WORLD
