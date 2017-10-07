#include "world.h"
#include "room.h"

World::World() 
{
	Room sleeping_quarters("Sleeping quarters","It's kinda dark, and everyone is sleeping. I should not wake anyone...");
	Room main_deck("Main deck", "Blablabla maindeck");
}

World::~World() {}