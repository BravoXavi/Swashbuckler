#include "item.h"

Item::Item(const char* itemName, const char* itemDescription, bool isPickable) : Entity(itemName, itemDescription)
{
	name = itemName;
	description = itemDescription;
	pickable = isPickable;
}

Item::~Item()
{
}