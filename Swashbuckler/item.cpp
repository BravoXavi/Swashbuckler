#include "item.h"

Item::Item(const char* itemName, const char* itemDescription, ItemType iType) : Entity(itemName, itemDescription)
{
	name = itemName;
	description = itemDescription;
	entityType = item;
	itemType = iType;
}

Item::~Item()
{}
