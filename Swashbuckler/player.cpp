#include <iostream>
#include "player.h"
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

//Returns Name, Description, and items contained in the players room
const void Player::Look() 
{
	std::cout << "You're in the " << location->name << "." << std::endl << location->description << "." << std::endl;
	
	if (!location->containedEntities.empty())
	{
		std::cout << "You can see something handy in here: ";

		for (std::list<Entity*>::iterator it = location->containedEntities.begin(); it != location->containedEntities.end(); ++it)
		{
			if(it != location->containedEntities.begin())  std::cout << ", ";
			std::cout << (*it)->name;
		}

		std::cout << ".";		
	}

	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
}

//Returns all items contained by the player
const void Player::Inventory()
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

//Returns exits and directions of the players room
const void Player::Exits()
{
	std::cout << "Exits: " << std::endl;
	for (std::vector<Exit*>::iterator it = location->exits.begin(); it != location->exits.end(); ++it)
	{
		if((*it)->locked)	std::cout << "- " << (*it)->destination->name << " (" << (*it)->directionName() << ", Locked) ";
		else				std::cout << "- " << (*it)->destination->name << " (" << (*it)->directionName() << ") ";
		std::cout << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
}

//Moves an item from the list in the Room to the one in the Player (Inventory)
const void Player::PickUp(const char* itemName)
{
	Item* itemToPick = (Item*)location->Find(itemName, item);

	if (itemToPick == nullptr)
	{
		std::cout << "There's nothing like that in here, sorry sea dog!";
	}
	else 
	{
		if (itemToPick->itemType != UNPICKABLE)
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

//Moves an item from the list in the Player to the one in the Room
const void Player::Drop(const char* itemName)
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

//Returns the item description contained by the player or the room
const void Player::CheckItem(const char* itemName)
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

//Puts an item inside the list of another item (Just able in CONTAINER items)
bool Player::Put(const char* inserted, const char* container)
{
	Item* insertedItem = (Item*)Find(inserted, item);
	Item* containerItem = (Item*)Find(container, item);

	if (insertedItem == nullptr || containerItem == nullptr)
	{
		std::cout << "You're not able of doing that, parrot!";
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << ">";
		return false;
	}
	else if (insertedItem->itemType != FOOD || containerItem->itemType != CONTAINER)
	{
		std::cout << "Why would you do that, picaroon?";
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << ">";
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

//Repairs the boat and ends the game
const void Player::Repair(const char* itemName)
{
	if (strcmp(itemName, "Boat") == 0)
	{
		if (Find("Nails") && Find("Plank") && Find("Hammer"))
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
		else
		{
			std::cout << "How would you do that without some crafting materials, you slicky boy?";			
		}

		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << ">";
	}
}

//Used an item on another item (contained by Player or Room). The behaviour is reduced to some interactions.
const bool Player::Use(const char* itemUsed, const char* itemUsedOn)
{
	int itemCode = 0;
	itemCode = convertItemToInt(itemUsed);

	Item* usingItem = (Item*)Find(itemUsed, item);
	Item* usedOnItem = (Item*)location->Find(itemUsedOn, item);

	if (usingItem == nullptr || usedOnItem == nullptr || usingItem->itemType != USABLE || usedOnItem->itemType != UNPICKABLE)
	{
		std::cout << "You're not able of doing that, parrot!";
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << ">";

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
					std::cout << "You use the Cutlass to damage the ropes that hold the Sails together. They will have a bad time repairing this...";
				}
				else
				{
					std::cout << "You already did the job. Lower that Cutlass, butcher!";
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

//Used to attack an NPC. 'sword' item is needed.
void Player::Attack(Npc* badguy)
{
	if (location->name == "Crow's nest")
	{
		if (Find("Cutlass"))
		{
			std::cout << "Fast as the wind, you use your Cutlass to end poor Slingers miserable life. With a mad look in his eyes he falls from the Crow's nest into the sea and disappears." << std::endl;
			badguy->alive = false;
		}
		else
		{
			std::cout << "You do not own a weapon!" << std::endl;
		}
	}
	else std::cout << "You don't have any enemy close." << std::endl;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
}

//Returns the name string of an item as a numeric value. Used to SWITCH between items.
const int Player::convertItemToInt(const char* itemName)
{
	int output = 0;
	std::string toConvert = itemName;
	for (unsigned int i = 0; i < toConvert.length(); i++)
	{
		output += (int)toConvert[i];
	}

	return output;
}

//Modifies the player location if an exit of the specified direction exists.
const bool Player::Go(const Directions dir)
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
				if ((*it)->locked)
				{
					std::cout << "That room is locked, scallywag!";
					std::cout << std::endl;
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << ">";
					return false;
				}
				else if (trapped)
				{
					if (location->name == "Main deck" && (*it)->destination->name == "Sleeping quarters")
					{
						std::cout << "You cannot just avoid Slinger, coward!!";
						std::cout << std::endl;		
						return false;
					}
					else
					{
						location = (*it)->destination;
						return true;
					}
				}
				else
				{
					location = (*it)->destination;
					return true;
				}			
			}
		}

		std::cout << "There's nothing on that direction...";
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << ">";
		return false;
	}
}

//Unlocks a locked exit (Player must possess the key)
const void Player::Unlock(const char* dir)
{
	bool found = false;
	for (std::vector<Exit*>::iterator it = location->exits.begin(); it != location->exits.end(); ++it)
	{
		if ((*it)->direction == (*it)->directionNameEnum(dir))
		{
			found = true;
			if ((*it)->locked)
			{
				if (Find((*it)->keyName))
				{
					(*it)->locked = false;
					std::cout << "The door has been unlocked!";
				}
				else
				{
					std::cout << "You don't have the key, landlubber!";
				}
			}
			else
			{
				std::cout << "The door is not locked, sorry sea dog!";
			}
		}		
	}

	if (!found)
	{
		std::cout << "There's nothing there!";
	}

	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ">";
}