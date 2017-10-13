#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "creature.h"
#include "exit.h"

class Player : public Creature {

public:
	Player(const char* name, const char* description, Room* location);
	~Player();

	void Look();
	bool Go(Directions dir);

private:

};

#endif // !CLASS_PLAYER