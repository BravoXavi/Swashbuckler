#ifndef CLASS_ENTITY
#define CLASS_ENTITY

#include <string>
#include <list>

enum  type
{
	item,
	creature,
	room
};

class Entity {

public:
	Entity(const char* entityN, const char* entityD);
	~Entity();

	std::string name;
	std::string description;
	type entityType;

private:
	std::list<Entity*> containedEntities;

};

#endif // !CLASS_ENTITY