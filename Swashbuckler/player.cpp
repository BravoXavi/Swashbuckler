#include <iostream>
#include "player.h"
#include "exit.h"

Player::Player(const char* playerName, const char* playerDescription, Room* loc) : Creature(playerName, playerDescription, loc)
{
	name = playerName;
	description = playerDescription;
	entityType = creature;
	location = loc;
}

Player::~Player() 
{
	for (std::vector<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
		delete *it;

	containedEntities.clear();
}

void Player::Look() 
{
	std::cout << "You're in the " << location->name << "." << std::endl << location->description << "." << std::endl;
	
	if (!location->containedEntities.empty())
	{
		std::cout << "I can see something handy in here: ";

		for (std::vector<Entity*>::iterator it = location->containedEntities.begin(); it != location->containedEntities.end(); ++it)
		{
			if(it != location->containedEntities.begin())  std::cout << ", ";
			std::cout << (*it)->name;
		}

		std::cout << "." << std::endl << ">";
	}
}

void Player::Inventory()
{
	if(containedEntities.empty()) std::cout << "You're not carrying anything, shark bait!" << std::endl << ">";
	else
	{
		std::cout << std::endl << "Items: " << std::endl;
		for (std::vector<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
			std::cout << "- " << (*it)->name << std::endl;

		std::cout << ">";
	}
}

void Player::PickUp(const char* itemName)
{
	bool gotIt = false;

	for(unsigned int i = 0; i < location->containedEntities.size(); i++)
	{
		if (location->containedEntities[i]->name == itemName)
		{
			if (location->containedEntities[i]->pickableEntity())
			{
				std::cout << "You picked " << itemName << std::endl;
				containedEntities.push_back(location->containedEntities[i]);
				location->containedEntities.erase(location->containedEntities.begin() + i);				
			}
			else
			{
				std::cout << "You cannot carry that!" << std::endl;
			}
			gotIt = true;
		}
	}

	if (!gotIt) std::cout << "There's nothing like that in here, sorry sea dog!"; 
	std::cout << std::endl << ">";
}

void Player::Drop(const char* itemName)
{
	bool gotIt = false;

	for (unsigned int i = 0; i < containedEntities.size(); i++)
	{
		if (containedEntities[i]->name == itemName)
		{
			std::cout << "You dropped " << itemName << std::endl;
			location->containedEntities.push_back(containedEntities[i]);
			containedEntities.erase(containedEntities.begin() + i);
			gotIt = true;
		}
	}

	if (!gotIt) std::cout << "You're not carrying that, scoundrel!" << std::endl << ">";
	else std::cout << ">";
}

void Player::CheckItem(const char* itemName)
{
	bool gotIt = false;

	for (std::vector<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
	{
		if ((*it)->name == itemName && (*it)->entityType == item)
		{
			std::cout << (*it)->description << std::endl;
			gotIt = true;
		}
	}

	if(!gotIt)
	{
		for (std::vector<Entity*>::iterator it = location->containedEntities.begin(); it != location->containedEntities.end(); ++it)
		{
			if ((*it)->name == itemName && (*it)->entityType == item)
			{
				std::cout << (*it)->description << std::endl;
				gotIt = true;
			}			
		}
	}

	if (!gotIt) std::cout << "You don't have or see something like that, scallywag!";

	std::cout << std::endl << ">";

}

void Player::Use(const char* itemUsed, const char* itemUsedOn)
{

}

bool Player::Go(Directions dir)
{
	if (location->exits.empty()) 
	{
		std::cout << "There's nothing on that direction..." << std::endl << ">";
		return false;
	}
	else
	{
		for (std::vector<Exit*>::iterator it = location->exits.begin(); it != location->exits.end(); ++it)
		{
			if ((*it)->direction == dir) 
			{
				location = (*it)->destination;
				return true;
			}
		}

		std::cout << "There's nothing on that direction..." << std::endl << ">";
		return false;
	}
}