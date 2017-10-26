#include <iostream>
#include "creature.h"

Creature::Creature(const char* creatureName, const char* creatureDescription, Room* loc) : Entity(creatureName, creatureDescription)
{
	name = creatureName;
	description = creatureDescription;
	entityType = creature;
	location = loc;
}

Creature::~Creature() 
{}