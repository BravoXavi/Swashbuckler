#include "entity.h"

Entity::Entity(const char* entityN, const char* entityD)
{
	name = entityN;
	description = entityD;
}

Entity::~Entity()
{
}

//Returns an Entity of the name and type specified (Item identification)
const Entity* Entity::Find(const char* name, type entityType) const
{
	for (std::list<Entity*>::const_iterator it = containedEntities.begin(); it != containedEntities.cend(); ++it)
	{
		if ((*it)->entityType == entityType)
		{
			if ((*it)->name == name)
				return *it;
		}
	}

	return nullptr;
}

//Returns true if it finds an entity with the specified name
const bool Entity::Find(const std::string& name) const
{
	for (std::list<Entity*>::const_iterator it = containedEntities.begin(); it != containedEntities.cend(); ++it)
	{
		if ((*it)->name == name.c_str())
			return true;
	}

	return false;
}