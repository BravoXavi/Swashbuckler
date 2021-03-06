#include <iostream>
#include <algorithm>
#include <string>
#include "world.h"
#include "room.h"
#include "exit.h"
#include "item.h"

World::World() 
{
	//Initializing turnTime to allow modifications later
	turnTime = 13000.0;

	//Room Creation
	Room* sleeping_quarters = new Room("Sleeping quarters", "It's kinda dark, and everyone is sleeping. You should not wake anyone...");
	Room* main_deck = new Room("Main deck", "The main deck of the ship. It's very peacefull at night, and you hear the waves hitting the ship. A light can be seen up, in the Crow's nest.");
	Room* storage_room = new Room("Storage room", "A couple of handy materials, food and general things. Everything the crew loots ends up here.");
	Room* poopdeck = new Room("Poopdeck", "The rest of the ship can be seen from this position and the helm is resting in front of you, without anyone moving it at night.");
	Room* crows_nest = new Room("Crow's nest", "The lookouts' favourite place. The salty wind goes through you, slightly cold. You can see everything from here.");

	//Exit creation and storage
	Exit* exit1 = new Exit(up, sleeping_quarters, main_deck, false, "none");
	sleeping_quarters->exits.push_back(exit1);
	Exit* exit2 = new Exit(down, main_deck, sleeping_quarters, false, "none");	
	main_deck->exits.push_back(exit2);
	Exit* exit3 = new Exit(west, sleeping_quarters, storage_room, true, "Key");
	sleeping_quarters->exits.push_back(exit3);
	Exit* exit4 = new Exit(east, storage_room, sleeping_quarters, false, "none");
	storage_room->exits.push_back(exit4);
	Exit* exit5 = new Exit(up, main_deck, crows_nest, false, "none");
	main_deck->exits.push_back(exit5);
	Exit* exit6 = new Exit(down, crows_nest, main_deck, false, "none");
	crows_nest->exits.push_back(exit6);
	Exit* exit7 = new Exit(south, main_deck, poopdeck, false, "none");
	main_deck->exits.push_back(exit7);
	Exit* exit8 = new Exit(north, poopdeck, main_deck, false, "none");
	poopdeck->exits.push_back(exit8);

	//Player and Badguy creation
	mainguy = new Player("Zelleryon", "A young, untrained but clever pirate", sleeping_quarters);
	badguy = new Npc("Slinger", "The cruel and harsh lookout of the ship.", crows_nest);

	//Item creation and storage - Pickable
	Item* sword = new Item("Cutlass", "A slightly old, ugly but effective weapon.", USABLE);
	sleeping_quarters->containedEntities.push_back(sword);
	Item* letter = new Item("Letter", "[...] By our majesty's name, this letter will serve as a forgiveness for the former pirate Joe 'Hound' Emmerick [...] surrendering of his whole crew to the navy [...] crew will be hanged with no possibility of trial. Signed: Admiral Robert Blake.", SIMPLE);
	sleeping_quarters->containedEntities.push_back(letter);	
	Item* hammer = new Item("Hammer", "A small hammer. Nothing special.", USABLE);
	poopdeck->containedEntities.push_back(hammer);
	Item* nails = new Item("Nails", "Wood nails. As simple as that.", SIMPLE);
	storage_room->containedEntities.push_back(nails);
	Item* oranges = new Item("Oranges", "The favorite defense of all pirates against scurvy! Pretty tasty, too.", FOOD);
	storage_room->containedEntities.push_back(oranges);
	Item* bottle = new Item("Water", "A small bottle of water. This could be perfect for the trip.", FOOD);
	crows_nest->containedEntities.push_back(bottle);
	Item* bag = new Item("Bag", "A small bag. It can be used to carry something.", CONTAINER);
	poopdeck->containedEntities.push_back(bag);
	Item* woodplank = new Item("Plank", "A pretty solid plank. Could be used to close a door or cover something damaged.", SIMPLE);
	storage_room->containedEntities.push_back(woodplank);
	Item* spyglass = new Item("Spyglass", "An old spyglass stolen from the lookout.", SIMPLE);
	crows_nest->containedEntities.push_back(spyglass);
	Item* storagekey = new Item("Key", "The key of the Storage room.", SIMPLE);
	crows_nest->containedEntities.push_back(storagekey);

	//Item creation and storage - UnPickable
	Item* sails = new Item("Sails", "The sails of the ship. You can see the ropes that hold them together on the sides.", UNPICKABLE);
	main_deck->containedEntities.push_back(sails);
	Item* helm = new Item("Helm", "The device taking care of controling the direction of the ship. Would be a shame if someone messes with it...", UNPICKABLE);
	poopdeck->containedEntities.push_back(helm);
	Item* boat = new Item("Boat", "You can sail away with this lil' boat, but it looks damaged. With some quick repairs it could work.", UNPICKABLE);
	main_deck->containedEntities.push_back(boat);

	//Storage of all entities in World class container
	worldEntities.push_back(storagekey);
	worldEntities.push_back(spyglass);
	worldEntities.push_back(woodplank);
	worldEntities.push_back(bag);
	worldEntities.push_back(bottle);
	worldEntities.push_back(oranges);
	worldEntities.push_back(nails);
	worldEntities.push_back(hammer);
	worldEntities.push_back(letter);
	worldEntities.push_back(sword);
	worldEntities.push_back(sails);
	worldEntities.push_back(helm);
	worldEntities.push_back(boat);
	worldEntities.push_back(sleeping_quarters);
	worldEntities.push_back(poopdeck);
	worldEntities.push_back(crows_nest);
	worldEntities.push_back(storage_room);
	worldEntities.push_back(main_deck);
	worldEntities.push_back(mainguy);
	worldEntities.push_back(badguy);
}

World::~World() 
{
	for (std::vector<Entity*>::iterator it = worldEntities.begin(); it != worldEntities.end(); ++it)
		delete *it;

	worldEntities.clear();
}

//Reads user input and checks if its time to update the world (NPC Behaviour).
bool World::worldTurn(std::vector<std::string> &userInput)
{
	clock_t timeChecker = clock();
	if ((double)(timeChecker - worldTimer) > turnTime)
	{
		updateWorld();
		worldTimer = timeChecker;
	}

	if (userInput.size() > 0) 
	{
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		readInput(userInput);
		return true;
	}
	else 
	{
		return false;
	}
}

//Updates the status of the world (Calls for NPC behaviours)
const void World::updateWorld()
{
	if (badguy->alive)
	{
		if (!badguy->aware)
		{
			badguy->checkShip(mainguy->location);
			if (badguy->aware)	mainguy->trapped = true;
		}
		else
		{			
			if (turnTime > 5000.0) turnTime = turnTime - 1000.0;
			badguy->getMad(mainguy->location);
		}
	}
	else
	{
		mainguy->trapped = false;
	}
}

//Input reading and calls for player actions
void World::readInput(std::vector<std::string> &userInput) 
{
	switch ( userInput.size() )
	{
		case 1:
			if (compareInput(userInput[0].c_str(), "Look"))
			{
				mainguy->Look();
			}
			else if (compareInput(userInput[0].c_str(), "Inventory"))
			{
				mainguy->Inventory();
			}
			else if (compareInput(userInput[0].c_str(), "Exits"))
			{
				mainguy->Exits();
			}			
			else
			{
				std::cout << "I didn't understand you, mate";
				std::cout << std::endl;
				std::cout << "---------------------------------------------" << std::endl;
				std::cout << ">";
			}
			break;

		case 2:
			if (compareInput(userInput[0].c_str(), "Go"))
			{
				if (compareInput(userInput[1].c_str(), "North"))
				{
					if (mainguy->Go(north)) mainguy->Look();
				}
				else if (compareInput(userInput[1].c_str(), "South"))
				{
					if (mainguy->Go(south)) mainguy->Look();
				}
				else if (compareInput(userInput[1].c_str(), "East"))
				{
					if (mainguy->Go(east)) mainguy->Look();
				}
				else if (compareInput(userInput[1].c_str(), "West"))
				{
					if (mainguy->Go(west)) mainguy->Look();
				}
				else if (compareInput(userInput[1].c_str(), "Up"))
				{
					if (mainguy->Go(up)) mainguy->Look();
				}
				else if (compareInput(userInput[1].c_str(), "Down"))
				{
					if (mainguy->Go(down)) mainguy->Look();
				}
				else
				{
					std::cout << "That's not a valid direction!";
					std::cout << std::endl;
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << ">";
				}
			}
			else if (compareInput(userInput[0].c_str(), "Unlock"))
			{
				mainguy->Unlock(userInput[1].c_str());
			}
			else if (compareInput(userInput[0].c_str(), "Pick"))
			{
				mainguy->PickUp(userInput[1].c_str());
			}
			else if (compareInput(userInput[0].c_str(), "Drop"))
			{
				mainguy->Drop(userInput[1].c_str());
			}
			else if (compareInput(userInput[0].c_str(), "Check"))
			{
				mainguy->CheckItem(userInput[1].c_str());
			}
			else if (compareInput(userInput[0].c_str(), "Repair"))
			{
				mainguy->Repair(userInput[1].c_str());
			}
			else if (compareInput(userInput[0].c_str(), "Kill"))
			{
				if (badguy->alive)
					mainguy->Kill(badguy, userInput[1].c_str());
				else
					std::cout << "That's not necessary anymore, butcher..." << std::endl << ">";
			}
			else
			{
				std::cout << "I didn't understand you, mate";
				std::cout << std::endl;
				std::cout << "---------------------------------------------" << std::endl;
				std::cout << ">";
			}
			break;

		case 4:
			if (compareInput(userInput[0].c_str(), "Use"))
			{
				mainguy->Use(userInput[1].c_str(), userInput[3].c_str());
			}
			else if (compareInput(userInput[0].c_str(), "Put"))
			{
				mainguy->Put(userInput[1].c_str(), userInput[3].c_str());
			}
			else
			{
				std::cout << "I didn't understand you, mate";
				std::cout << std::endl;
				std::cout << "---------------------------------------------" << std::endl;
				std::cout << ">";
			}
			break;

		default:
			std::cout << "I didn't understand you, mate";
			std::cout << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
			std::cout << ">";
			break;
	}	
}

//Ending flavour text with conditionals
const void World::ending()
{
	if (badguy->shot)
	{
		std::cout << "Tired of you, and beeing the cruel pirate he is, Slinger does not think twice before making sure you won't disobey again." << std::endl;
		std::cout << "The last thing you listen is a loud sound. And then, all black." << std::endl;
		std::cout << "Davy Jones be with you. YOU DIED." << std::endl;
	}
	else if (badguy->hidden)
	{
		std::cout << "You managed to move fast and silently enough to get out of there with the boat without Slinger beeing able to stop you!" << std::endl;
		std::cout << "Yeah. But did you really think that the lookout was just going to disappear without you making sure of it?" << std::endl;
		std::cout << "The last thing you listen is someone crawling into your boat. And then, all black." << std::endl;
		std::cout << "Davy Jones be with you. YOU DIED." << std::endl;
	}
	else
	{
		if (mainguy->helmDamaged && mainguy->sailsDamaged)
		{
			std::cout << "You take the boat in the silence of the night and sail away!" << std::endl;
			std::cout << "Thankfully, you where smart enough to make sure that the ship was damaged enough." << std::endl;
			std::cout << "When the Captain woke up and saw the lookout missing, the ship damaged and the letter not in his pocket, he panicked and tried to escape the ship." << std::endl;
			std::cout << "Let's hope the rest of the crew noticed it and did something, because he's the only one that knows for sure who destroyed his plans..." << std::endl;
		}
		else
		{
			std::cout << "You take the boat in the silence of the night and sail away!" << std::endl;
			std::cout << "But you did not think about something. The ship sailed to port without any problem, where all your crew was captured by the Navy." << std::endl;
			std::cout << "Only your old Captain survided and is now a very influential man. Let's hope he do not uses that power to look for you..." << std::endl;
		}
		if (mainguy->fullBag && mainguy->Find("Spyglass"))
		{
			std::cout << "Because you took the Spyglass with you, you could see an island and sail there. With your bag of supplies, you sustained yourself enough to reach it, where you finally escaped. Good job!! Davy Jones smiles at you, lad!" << std::endl;
		}
		else
		{
			std::cout << "Sadly, you thought that the sea was going to have mercy on you. To be sure to reach a safe pleace you need to SEE where are you leading and have ENOUGH SUPPLIES to reach it. Without one of them ..." << std::endl;
			std::cout << "Sadly, you did not take a Spyglass with you. Getting in a boat in the middle of the sea is a real problem when you don't know where to go and " << std::endl;
			std::cout << "But well, look at the bright side! Now you're the captain of your own ship! At least while you have something to eat..." << std::endl;
		}
	}
}

//Compares the two inputs (Solves upper/lowerCase problems)
const bool World::compareInput(const char* a, const char* b)
{
	return _stricmp(a, b) == 0;
}