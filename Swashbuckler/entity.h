#ifndef CLASS_ENTITY
#define CLASS_ENTITY

#include <string>
#include <vector>
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
	std::list<Entity*> containedEntities;
	type entityType;

	Entity* Find(const char* name, type entityType) const;

	virtual bool containsEntity(const char* entityName)
	{
		bool ret = false;

		for (std::list<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
		{
			if ((*it)->name == entityName)
			{
				ret = true;
			}
		}

		return ret;
	}

private:
	

};

#endif // !CLASS_ENTITY