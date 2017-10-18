#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "creature.h"
#include "exit.h"
#include "npc.h"

class Player : public Creature {

public:
	Player(const char* name, const char* description, Room* location);
	~Player();

	void Look();
	void Inventory();
	void PickUp(const char* itemName);
	void Drop(const char* itemName);
	void CheckItem(const char* itemName);

	bool Use(const char* itemUsed, const char* itemUsedOn);
	bool Put(const char* inserted, const char* container);
	bool Go(Directions dir);
	void Attack(Npc* badguy);
	int convertItemToInt(const char* itemName);

public:
	//Win conditions
	bool sailsDamaged = false;
	bool helmDamaged = false;
	bool fullBag = false;
	bool escaped = false;

private:

};

#endif // !CLASS_PLAYER