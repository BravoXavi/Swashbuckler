#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "creature.h"

class Player : public Creature {

private:

public:
	Player(const char* name, const char* description);
	~Player();

	void Look();
};

#endif // !CLASS_PLAYER