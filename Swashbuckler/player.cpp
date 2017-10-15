#include <iostream>
#include "player.h"
#include "exit.h"
#include "item.h"

Player::Player(const char* playerName, const char* playerDescription, Room* loc) : Creature(playerName, playerDescription, loc)
{
	name = playerName;
	description = playerDescription;
	entityType = creature;
	location = loc;
}

Player::~Player() 
{
	for (std::list<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
		delete *it;

	containedEntities.clear();
}

void Player::Look() 
{
	std::cout << "You're in the " << location->name << "." << std::endl << location->description << "." << std::endl;
	
	if (!location->containedEntities.empty())
	{
		std::cout << "I can see something handy in here: ";

		for (std::list<Entity*>::iterator it = location->containedEntities.begin(); it != location->containedEntities.end(); ++it)
		{
			if(it != location->containedEntities.begin())  std::cout << ", ";
			std::cout << (*it)->name;
		}

		std::cout << "." << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << ">";
	}
}

void Player::Inventory()
{
	if(containedEntities.empty()) std::cout << "You're not carrying anything, shark bait!";
	else
	{
		std::cout << "Items: " << std::endl;
		for (std::list<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
		{
			std::cout << "- " << (*it)->name;
			if ((*it)->containedEntities.size() == 2)
			{
				std::cout << " (Full)";
			}
			std::cout << std::endl;
		}		
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
}

void Player::PickUp(const char* itemName)
{
	Item* itemToPick = (Item*)location->Find(itemName, item);

	if (itemToPick == nullptr)
	{
		std::cout << "There's nothing like that in here, sorry sea dog!";
	}
	else 
	{
		if (itemToPick->entityType != UNPICKABLE)
		{
			std::cout << "You picked " << itemName;
			containedEntities.push_back(itemToPick);
			location->containedEntities.remove(itemToPick);
		}
		else
		{
			std::cout << "You cannot carry that!";
		}
	}

	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
}

void Player::Drop(const char* itemName)
{
	Item* itemToDrop = (Item*)location->Find(itemName, item);

	if (itemToDrop == nullptr)
	{
		std::cout << "You're not carrying that, scoundrel!";
	}
	else
	{
		std::cout << "You droped " << itemName;
		location->containedEntities.push_back(itemToDrop);
		containedEntities.remove(itemToDrop);
	}

	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
}

void Player::CheckItem(const char* itemName)
{
	bool gotIt = false;

	Item* itemToCheck = (Item*)Find(itemName, item);
	if (itemToCheck == nullptr) itemToCheck = (Item*)location->Find(itemName, item);
	if (itemToCheck == nullptr)
	{
		std::cout << "You don't have or see something like that, scallywag!";
	}
	else
	{
		std::cout << itemToCheck->description;
	}

	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
}

bool Player::Put(const char* inserted, const char* container)
{
	Item* insertedItem = (Item*)Find(inserted, item);
	Item* containerItem = (Item*)Find(container, item);

	if (insertedItem == nullptr || containerItem == nullptr)
	{
		std::cout << "You're not able of doing that, parrot!";
		return false;
	}
	else if (insertedItem->itemType != FOOD || containerItem->itemType != CONTAINER)
	{
		std::cout << "Why would you do that, picaroon?";
		return false;
	}
	else
	{
		std::cout << "You put the " << insertedItem->name << " inside the " << containerItem->name;
		containerItem->containedEntities.push_back(insertedItem);
		containedEntities.remove(insertedItem);	
		if (containerItem->containedEntities.size() == 2) fullBag = true;
	}

	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
	return true;
}

bool Player::Use(const char* itemUsed, const char* itemUsedOn)
{
	int itemCode = 0;
	itemCode = convertItemToInt(itemUsed);

	Item* usingItem = (Item*)Find(itemUsed, item);
	Item* usedOnItem = (Item*)location->Find(itemUsedOn, item);

	if (usingItem == nullptr || usedOnItem == nullptr)
	{
		std::cout << "You're not able of doing that, parrot!";
		return false;
	}
	else if (usingItem->itemType != USABLE || usedOnItem->itemType != UNPICKABLE)
	{
		std::cout << "You're not able of doing that, parrot!";
		return false;
	}
	else 
	{
		switch (itemCode)
		{
		case 735:
			if (usedOnItem->name == "Sails")
			{
				if (!sailsDamaged)
				{
					sailsDamaged = true;
					std::cout << "You use the Cutlass to damage the ropes that hold the Sails together. They will have a bad time repairing this..." << std::endl;
				}
				else
				{
					std::cout << "You already did the job. Lower that Cutlass, butcher!" << std::endl;
				}
			}
			else
			{
				std::cout << "That's not a good idea...";
			}			
			break;

		case 602:
			if (usedOnItem->name == "Helm")
			{
				if (!helmDamaged)
				{
					helmDamaged = true;
					std::cout << "You use the back of the hammer to disengage the helm. This will cause at least 30 minutes of repairs. More time to disappear.";
				}
				else
				{
					std::cout << "Trying to make something else could be too loud. Better leave it like that.";
				}
			}
			else if (usedOnItem->name == "Boat")
			{
				if (Find("Nails") && Find("Plank"))
				{
					std::cout << "Do you wants to repair the boat and sail away? (Y/N)" << std::endl;
					char response;
					std::cin >> response;
					switch (response)
					{
						case 'Y':
							escaped = true;
							break;
						case 'N':
							break;
						default: 
							std::cout << "That's not an answer, lad.";
							break;
					}										
				}
			}
			else
			{
				std::cout << "That's not a good idea...";
			}			
			break;
		default:
			std::cout << "That's not even a possibility, blowfish!";
			break;
		}
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		if(!escaped) std::cout << ">";
		return true;
	}

}

int Player::convertItemToInt(const char* itemName)
{
	int output = 0;
	std::string toConvert = itemName;
	for (unsigned int i = 0; i < toConvert.length(); i++)
	{
		output += (int)toConvert[i];
	}

	return output;
}

bool Player::Go(Directions dir)
{
	if (location->exits.empty()) 
	{
		std::cout << "There's nothing on that direction...";
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << ">";
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

		std::cout << "There's nothing on that direction...";
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << ">";
		return false;
	}
}