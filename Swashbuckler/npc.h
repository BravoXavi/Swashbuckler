#ifndef CLASS_NPC
#define CLASS_NPC

#include "creature.h"

enum mood {
	CALM,
	MAD,
	VIOLENT,
	KILL
};

class Npc : public Creature {

public:
	Npc(const char* name, const char* description, Room* location);
	~Npc();

	mood npcMood = CALM;
	void checkShip(const Room* playerLocation);
	void getMad(const Room* playerLocation);

public:
	bool aware = false;
	bool alive = false;
	bool shot = false;

private:

};

#endif // !CLASS_NPC