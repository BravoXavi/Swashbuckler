#include <iostream>
#include "player.h"

using namespace std;

Player::Player(const char* playerName, const char* playerDescription, Room* loc) : Creature(playerName, playerDescription, loc)
{
	name = playerName;
	description = playerDescription;
	entityType = creature;
	location = loc;
}

Player::~Player() {}

void Player::Look() {
	cout << "You're in the " << location->name << "." << endl << location->description << "." << endl << ">";
}