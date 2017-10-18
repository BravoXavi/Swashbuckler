#include "world.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include <iostream>
#include <algorithm>

using namespace std;

World::World() 
{
	//Initializing turnTime to allow modifications later
	turnTime = 7000.0;

	//Room Creation
	Room* sleeping_quarters = new Room("Sleeping quarters", "It's kinda dark, and everyone is sleeping. I should not wake anyone...");
	Room* main_deck = new Room("Main deck", "DESCRIPTION. Slinger, the lookout, is awake at the crow's nest!! He could ruin the whole operation!!");
	Room* storage_room = new Room("Storage room", "need description");
	Room* poopdeck = new Room("Poopdeck", "need description");
	Room* crows_nest = new Room("Crow's nest", "need description");

	//Exit creation and storage
	Exit* exit1 = new Exit(up, sleeping_quarters, main_deck);
	sleeping_quarters->exits.push_back(exit1);
	Exit* exit2 = new Exit(down, main_deck, sleeping_quarters);	
	main_deck->exits.push_back(exit2);
	Exit* exit3 = new Exit(west, sleeping_quarters, storage_room);
	sleeping_quarters->exits.push_back(exit3);
	Exit* exit4 = new Exit(east, storage_room, sleeping_quarters);
	storage_room->exits.push_back(exit4);
	Exit* exit5 = new Exit(up, main_deck, crows_nest);
	main_deck->exits.push_back(exit5);
	Exit* exit6 = new Exit(down, crows_nest, main_deck);	
	crows_nest->exits.push_back(exit6);
	Exit* exit7 = new Exit(north, main_deck, poopdeck);
	main_deck->exits.push_back(exit7);
	Exit* exit8 = new Exit(south, poopdeck, main_deck);
	poopdeck->exits.push_back(exit8);

	//Player and Badguy creation
	mainguy = new Player("Zelleryon", "A young, untrained but clever pirate", sleeping_quarters);
	badguy = new Npc("Slinger", "The cruel and harsh lookout of the ship.", crows_nest);

	//Item creation and storage - Pickable
	Item* sword = new Item("Cutlass", "A slightly old, ugly but effective weapon.", USABLE);
	sleeping_quarters->containedEntities.push_back(sword);
	Item* letter = new Item("Letter", "Long description...", SIMPLE);
	sleeping_quarters->containedEntities.push_back(letter);	
	Item* hammer = new Item("Hammer", "A small hammer. Nothing special.", USABLE);
	poopdeck->containedEntities.push_back(hammer);
	Item* nails = new Item("Nails", "Wood nails. As simple as that.", SIMPLE);
	storage_room->containedEntities.push_back(nails);
	Item* oranges = new Item("Oranges", "The favorite defense of all pirates against scurvy! Pretty tasty, too.", FOOD);
	storage_room->containedEntities.push_back(oranges);
	Item* bottle = new Item("Water", "A small bottle with water. This could be perfect for the trip.", FOOD);
	crows_nest->containedEntities.push_back(bottle);
	Item* bag = new Item("Bag", "A small bag. Can be used to carry something.", CONTAINER);
	poopdeck->containedEntities.push_back(bag);
	Item* woodplank = new Item("Plank", "A pretty solid plank. Could be used to close a door or cover something damaged.", SIMPLE);
	storage_room->containedEntities.push_back(woodplank);
	Item* spyglass = new Item("Spyglass", "An old spyglass stolen from the lookout.", SIMPLE);
	crows_nest->containedEntities.push_back(spyglass);

	//Item creation and storage - UnPickable
	Item* sails = new Item("Sails", "The sails of the ship. You can see the ropes that hold them together on the sides.", UNPICKABLE);
	main_deck->containedEntities.push_back(sails);
	Item* helm = new Item("Helm", "The device taking care of controling the direction of the ship. Would be a shame if someone messes with it...", UNPICKABLE);
	poopdeck->containedEntities.push_back(helm);
	Item* boat = new Item("Boat", "You can sail away with this lil' boat, but it looks damaged. With some quick repairs it could work.", UNPICKABLE);
	main_deck->containedEntities.push_back(boat);

	//Storage of all entities in World class container
	worldEntities.push_back(sleeping_quarters);
	worldEntities.push_back(main_deck);
	worldEntities.push_back(mainguy);
	worldEntities.push_back(badguy);
}

World::~World() 
{
	for (vector<Entity*>::iterator it = worldEntities.begin(); it != worldEntities.end(); ++it)
		delete *it;

	worldEntities.clear();
}

bool World::worldTurn(vector<string> &userInput)
{
	clock_t timeChecker = clock();
	if ((double)(timeChecker - worldTimer) > turnTime)
	{
		//UPDATE WORLD
		updateWorld();
		worldTimer = timeChecker;
	}

	if (userInput.size() > 0) 
	{
		std::cout << endl;
		cout << "---------------------------------------------" << endl;
		readInput(userInput);
		return true;
	}
	else 
	{
		return false;
	}
}

void World::updateWorld()
{
	if (!badguy->aware)
	{
		badguy->checkShip(mainguy->location);
	}
	else
	{
		if(turnTime > 4000.0) turnTime = turnTime - 1500.0;
		badguy->getMad(mainguy->location);
	}
}

void World::readInput(vector<string> &userInput) 
{
	switch ( userInput.size() )
	{
		case 1:
			if (userInput[0] == "Look")
			{
				mainguy->Look();
			}
			else if (userInput[0] == "Inventory")
			{
				mainguy->Inventory();
			}
			else
			{
				cout << "I didn't understand you, mate" << endl << ">";
			}
			break;

		case 2:
			if (userInput[0] == "Go")
			{
				if (userInput[1] == "north")
				{
					if (mainguy->Go(north)) mainguy->Look();
				}
				else if (userInput[1] == "south")
				{
					if (mainguy->Go(south)) mainguy->Look();
				}
				else if (userInput[1] == "east")
				{
					if (mainguy->Go(east)) mainguy->Look();
				}
				else if (userInput[1] == "west")
				{
					if (mainguy->Go(west)) mainguy->Look();
				}
				else if (userInput[1] == "up")
				{
					if (mainguy->Go(up)) mainguy->Look();
				}
				else if (userInput[1] == "down")
				{
					if (mainguy->Go(down)) mainguy->Look();
				}
				else cout << "That's not a valid direction!" << endl << ">";				
			}
			else if (userInput[0] == "Pick")
			{
				mainguy->PickUp(userInput[1].c_str());
			}
			else if (userInput[0] == "Drop")
			{
				mainguy->Drop(userInput[1].c_str());
			}
			else if (userInput[0] == "Check")
			{
				mainguy->CheckItem(userInput[1].c_str());
			}
			else
			{
				cout << "I didn't understand you, mate" << endl << ">";
			}

			break;

		case 4:
			if (userInput[0] == "Use")
			{
				mainguy->Use(userInput[1].c_str(), userInput[3].c_str());
			}
			else if (userInput[0] == "Put")
			{
				mainguy->Put(userInput[1].c_str(), userInput[3].c_str());
			}
			else
			{
				cout << "I didn't understand you, mate" << endl << ">";
			}

			break;
	}	
}

void World::ending()
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
	if (mainguy->Find("Spyglass"))
	{
		std::cout << "Because you took the Spyglass with you, you could see an island and sail there, where you finally escaped. Good job!! Davy Jones smiles at you, lad!" << std::endl;
	}
	else
	{
		std::cout << "Sadly, you did not take a Spyglass with you. Getting in a boat in the middle of the sea is a real problem when you don't know where to go." << std::endl;
		std::cout << "Look at the bright side! Now you're the captain of your own ship! At least while you have something to eat..." << std::endl;
	}
}