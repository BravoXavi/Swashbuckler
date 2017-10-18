#ifndef CLASS_ENTITY
#define CLASS_ENTITY

#include <string>
#include <vector>
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
	~Entity();

	std::string name;
	std::string description;
	std::list<Entity*> containedEntities;
	type entityType;

	Entity* Find(const char* name, type entityType) const;
	bool Find(const std::string& name) const;

private:
	

};

#endif // !CLASS_ENTITY