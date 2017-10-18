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
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Slinger, The Lookout: HEY YOU! What are you doing there? Climb to the crow's nest NOW!!" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << ">";
	}
}

void Npc::getMad(const Room* playerLocation)
{
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if(playerLocation != location)
	{			
		switch (npcMood)
		{
			case CALM:
				std::cout << "Slinger, The Lookout: I told you to climb here right now. I don't like to repeat things, dog. MOVE!!" << std::endl;
				npcMood = MAD;
				break;
			case MAD:
				std::cout << "Slinger, The Lookout: Do you thing that beeing in this ship for a month gives you permision to question my orders? Don't get me mad, son..." << std::endl;
				npcMood = VIOLENT;
				break;
			case VIOLENT:
				std::cout << "Slinger, The Lookout: Your choice. This is your last oportunity. (You hear the sound of a musket beeing loaded)" << std::endl;
				npcMood = KILL;
				break;
			case KILL:
				std::cout << "BANG!!" << std::endl;
				break;
		}		
	}
	else
	{
		std::cout << "Slinger, The Lookout: Bla bla bla... (Boring complains about beeing out of bed... Seems like you only have one way to go)" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
}