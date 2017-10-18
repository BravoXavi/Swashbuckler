#include "npc.h"

Npc::Npc(const char* npcName, const char* npcDescription) : Entity(npcName, npcDescription)
{
	name = npcName;
	description = npcDescription;
	entityType = npc;
}

Npc::~Npc()
{
}
