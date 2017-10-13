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
}

bool Item::pickableEntity(){
	return pickable;
}