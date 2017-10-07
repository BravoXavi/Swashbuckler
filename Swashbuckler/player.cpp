#include <iostream>
#include "player.h"

using namespace std;

Player::Player(const char* roomName, const char* roomDescription) : Creature(roomName, roomDescription)
{
	name = roomName;
	description = roomDescription;
	entityType = creature;
}

Player::~Player() {}