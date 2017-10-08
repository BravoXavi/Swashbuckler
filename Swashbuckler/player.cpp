#include <iostream>
#include "player.h"

using namespace std;

Player::Player(const char* playerName, const char* playerDescription, Room* location) : Creature(playerName, playerDescription, location)
{
	name = playerName;
	description = playerDescription;
	entityType = creature;
}

Player::~Player() {}

void Player::Look() {
	cout << "You're in the " << location->name << "." << endl << location->description << "." << endl << ">";
}