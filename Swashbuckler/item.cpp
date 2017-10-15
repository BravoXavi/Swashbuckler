#include "item.h"

Item::Item(const char* itemName, const char* itemDescription, ItemType iType) : Entity(itemName, itemDescription)
{
	name = itemName;
	description = itemDescription;
	entityType = item;
	itemType = iType;
}

Item::~Item()
{
	for (std::list<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
		delete *it;

	containedEntities.clear();
}
