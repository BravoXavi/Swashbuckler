#ifndef CLASS_WORLD
#define CLASS_WORLD

#include <vector>
#include <string>
#include <time.h>
#include "entity.h"
#include "player.h"

class World {

public:
	World();
	~World();

	void readInput(std::vector<std::string> &userInput);
	bool worldTurn(std::vector<std::string> &userInput);
	void ending();

	std::vector<Entity*> worldEntities;
	Player* mainguy;
	clock_t worldTimer;

private:

};

#endif // !CLASS_WORLD
