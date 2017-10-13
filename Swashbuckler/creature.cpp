#include <iostream>
#include "creature.h"

using namespace std;

Creature::Creature(const char* creatureName, const char* creatureDescription, Room* loc) : Entity(creatureName, creatureDescription)
{
	name = creatureName;
	description = creatureDescription;
	entityType = creature;
	location = loc;
}

Creature::~Creature() 
{
	for (std::vector<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
		delete *it;

	containedEntities.clear();
}