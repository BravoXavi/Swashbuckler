#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "creature.h"
#include "exit.h"
#include "npc.h"

class Player : public Creature {

public:
	Player(const char* name, const char* description, Room* location);
	~Player();

	const void Look();
	const void Inventory();
	const void Exits();
	const void Unlock(const char* dir);
	const void Repair(const char* itemName);
	const void PickUp(const char* itemName);
	const void Drop(const char* itemName);
	const void CheckItem(const char* itemName);	
	const bool Use(const char* itemUsed, const char* itemUsedOn);	
	const bool Go(const Directions dir);
	
	bool Put(const char* inserted, const char* container);
	void Attack(Npc* badguy);
	
public:
	//Player flags
	bool trapped = false;
	bool sailsDamaged = false;
	bool helmDamaged = false;
	bool fullBag = false;
	bool escaped = false;

private:
	const int convertItemToInt(const char* itemName);
};

#endif // !CLASS_PLAYER