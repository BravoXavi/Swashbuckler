#ifndef CLASS_ITEM
#define CLASS_ITEM

#include "entity.h"

class Item : public Entity {

public:
	Item(const char* name, const char* description, bool isPickable);
	~Item();

	bool pickable;

private:

};

#endif // !CLASS_ITEM