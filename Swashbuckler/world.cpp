#include "world.h"
#include "room.h"
#include "player.h"

World::World() 
{
	Room sleeping_quarters("Sleeping quarters","It's kinda dark, and everyone is sleeping. I should not wake anyone...");
	Room main_deck("Main deck", "Blablabla maindeck");

	Player mainguy("Slinger", "A young, untrained but clever pirate");
}

World::~World() {}