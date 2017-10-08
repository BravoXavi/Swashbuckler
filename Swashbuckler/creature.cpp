#include <iostream>
#include "creature.h"

using namespace std;

Creature::Creature(const char* creatureName, const char* creatureDescription, Room* location) : Entity(creatureName, creatureDescription)
{
	name = creatureName;
	description = creatureDescription;
	entityType = creature;
}

Creature::~Creature() {}