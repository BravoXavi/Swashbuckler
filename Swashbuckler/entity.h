#ifndef CLASS_ENTITY
#define CLASS_ENTITY

#include <string>
#include <list>

using namespace std;

enum  type
{
	item,
	creature,
	room
};

class Entity {

private:
	list<Entity*> containedEntities;

public:
	string name;
	string description;
	type entityType;
	
	Entity(const char* entityN, const char* entityD);
	~Entity();
};

#endif // !CLASS_ENTITY