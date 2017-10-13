#include "item.h"

Item::Item(const char* itemName, const char* itemDescription, bool isPickable) : Entity(itemName, itemDescription)
{
	name = itemName;
	description = itemDescription;
	entityType = item;
	pickable = isPickable;
}

Item::~Item()
{
	for (std::vector<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
		delete *it;

	containedEntities.clear();
}

bool Item::pickableEntity(){
	return pickable;
}