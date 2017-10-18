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

void Npc::checkShip(const Room* playerLocation)
{
	if ((playerLocation->name == "Poopdeck" || playerLocation->name == "Main deck") && !aware)
	{
		aware = true;
		std::cout << "NPC GETS MAD AND STARTS TO REACT!" << std::endl;
	}
	else 
	{
		std::cout << "CHECKING SHIP" << std::endl;
	}
}

void Npc::getMad()
{
	std::cout << "GETTING MAD" << std::endl;
}