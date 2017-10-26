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
	bool worldTurn(std::vector<std::string> &userInput);
	const void ending();
	const bool compareInput(const char* a, const char* b);
	
public:	
	Player* mainguy;
	Npc* badguy;
	clock_t worldTimer;

private:
	const void updateWorld();	

private:
	std::vector<Entity*> worldEntities;
	double turnTime;
};

#endif // !CLASS_WORLD
