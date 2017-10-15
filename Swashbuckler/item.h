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

	ItemType itemType;

private:

};

#endif // !CLASS_ITEM