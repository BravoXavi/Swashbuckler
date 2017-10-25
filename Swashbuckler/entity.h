#ifndef CLASS_ENTITY
#define CLASS_ENTITY

#include <string>
#include <list>

enum  type
{
	item,
	creature,
	room,
	npc
};

class Entity {

public:
	Entity(const char* entityN, const char* entityD);
	virtual ~Entity();

	const Entity* Find(const char* name, type entityType) const;
	const bool Find(const std::string& name) const;

public:
	std::string name;
	std::string description;
	std::list<Entity*> containedEntities;
	type entityType;

};

#endif // !CLASS_ENTITY