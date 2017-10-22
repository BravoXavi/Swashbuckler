#ifndef CLASS_ITEM
#define CLASS_ITEM

#include "entity.h"

enum ItemType
{
	CONTAINER,
	FOOD,
	SIMPLE,
	USABLE,
	UNPICKABLE
};

class Item : public Entity {

public:
	Item(const char* name, const char* description, ItemType type);
	~Item();

public:
	ItemType itemType;

};

#endif // !CLASS_ITEM