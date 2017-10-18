#ifndef CLASS_NPC
#define CLASS_NPC

#include "creature.h"

enum mood {
	CALM,
	MAD,
	VIOLENT
};

class Npc : public Creature {

public:
	Npc(const char* name, const char* description, Room* location);
	~Npc();

	bool aware = false;

	void checkShip();
	void getMad();

private:

};

#endif // !CLASS_NPC