#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "creature.h"
#include "exit.h"

class Player : public Creature {

public:
	Player(const char* name, const char* description, Room* location);
	~Player();

	void Look();
	void Inventory();
	void PickUp(const char* itemName);
	void Drop(const char* itemName);
	void CheckItem(const char* itemName);
	void Use(const char* itemUsed, const char* itemUsedOn);
	bool Go(Directions dir);

	int convertItemToInt(const char* itemName);

public:
	//Win conditions
	bool sailsDamaged = false;
	bool helmDamaged = false;
	bool fullBag = false;

private:

};

#endif // !CLASS_PLAYER