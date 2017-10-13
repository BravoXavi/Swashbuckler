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

Player::~Player() 
{
}

void Player::Look() 
{
	cout << "You're in the " << location->name << "." << endl << location->description << "." << endl << ">";
}

void Player::Inventory()
{
	if(containedEntities.empty()) cout << "You're not carrying anything, shark bait!" << endl << ">";
	else
	{
		cout << "Items: " << endl;
		for (std::list<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
			std::cout << '- ' << (*it)->name << endl;
	}
}

bool Player::Go(Directions dir)
{
	if (location->exits.empty()) 
	{
		cout << "There's nothing on that direction..." << endl << ">";
		return false;
	}
	else
	{
		for (unsigned int i = 0; i < location->exits.size(); i++)
		{
			if (location->exits[i]->direction == dir) 
			{
				location = location->exits[i]->destination;
				cout << "You walked to " << location->name << "." << endl << ">";
				return true;
			}
		}

		cout << "There's nothing on that direction..." << endl << ">";
		return false;
	}
}