#include "npc.h"
#include "room.h"
#include <iostream>

Npc::Npc(const char* npcName, const char* npcDescription, Room* loc) : Creature(npcName, npcDescription, loc)
{
	name = npcName;
	description = npcDescription;
	entityType = npc;
	location = loc;
}

Npc::~Npc()
{
}

void Npc::checkShip()
{
	std::cout << "CHECKING SHIP" << std::endl;
}