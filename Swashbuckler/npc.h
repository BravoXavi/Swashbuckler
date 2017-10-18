#ifndef CLASS_NPC
#define CLASS_NPC

#include "entity.h"

class Npc : public Entity {

public:
	Npc(const char* name, const char* description);
	~Npc();

private:

};

#endif // !CLASS_NPC