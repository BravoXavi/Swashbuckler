#include "entity.h"

Entity::Entity(const char* entityN, const char* entityD, type entityT)
{
	name = entityN;
	description = entityD;
	entityType = entityT;
}

Entity::~Entity()
{
}
