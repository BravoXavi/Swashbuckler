#include <iostream>
#include "creature.h"

using namespace std;

Creature::Creature(const char* roomName, const char* roomDescription) : Entity(roomName, roomDescription)
{
	name = roomName;
	description = roomDescription;
	entityType = creature;
}

Creature::~Creature() {}