#ifndef CLASS_WORLD
#define CLASS_WORLD

#include <vector>
#include <string>
#include <time.h>
#include "entity.h"
#include "player.h"
#include "npc.h"

class World {

public:
	World();
	~World();

	void readInput(std::vector<std::string> &userInput);
	void ending();
	void updateWorld();
	bool worldTurn(std::vector<std::string> &userInput);
	
	std::vector<Entity*> worldEntities;
	Player* mainguy;
	Npc* badguy;
	clock_t worldTimer;
	double turnTime;

private:

};

#endif // !CLASS_WORLD
