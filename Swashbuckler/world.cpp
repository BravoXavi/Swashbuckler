#include "world.h"
#include "room.h"
#include "player.h"
#include "exit.h"
#include "item.h"
#include <iostream>
#include <algorithm>

using namespace std;

World::World() 
{
	//Room Creation
	Room* sleeping_quarters = new Room("Sleeping quarters", "It's kinda dark, and everyone is sleeping. I should not wake anyone...");
	Room* main_deck = new Room("Main deck", "need description");
	Room* storage_room = new Room("Storage room", "need description");
	Room* poopdeck = new Room("Poopdeck", "need description");
	Room* crows_nest = new Room("Crow's nest", "need description");

	//Exit creation and storage
	Exit* exit1 = new Exit(up, sleeping_quarters, main_deck);
	sleeping_quarters->exits.push_back(exit1);

	Exit* exit2 = new Exit(down, main_deck, sleeping_quarters);	
	main_deck->exits.push_back(exit2);

	Exit* exit3 = new Exit(east, sleeping_quarters, storage_room);
	sleeping_quarters->exits.push_back(exit3);

	Exit* exit4 = new Exit(west, storage_room, sleeping_quarters);
	storage_room->exits.push_back(exit4);

	Exit* exit5 = new Exit(up, main_deck, crows_nest);
	main_deck->exits.push_back(exit5);

	Exit* exit6 = new Exit(down, crows_nest, main_deck);	
	crows_nest->exits.push_back(exit6);

	Exit* exit7 = new Exit(north, main_deck, poopdeck);
	main_deck->exits.push_back(exit7);

	Exit* exit8 = new Exit(south, poopdeck, main_deck);
	poopdeck->exits.push_back(exit8);

	//Player creation
	mainguy = new Player("Slinger", "A young, untrained but clever pirate", sleeping_quarters);

	//Item creation and storage - Pickable
	Item* sword = new Item("Cutlass", "A slightly old, ugly but effective weapon.", true);
	sleeping_quarters->containedEntities.push_back(sword);

	Item* letter = new Item("Letter", "Long description...", true);
	sleeping_quarters->containedEntities.push_back(letter);
	
	Item* hammer = new Item("Hammer", "A small hammer. Nothing special.", true);
	poopdeck->containedEntities.push_back(hammer);

	Item* nails = new Item("Nails", "Wood nails. As simple as that.", true);
	storage_room->containedEntities.push_back(nails);

	Item* oranges = new Item("Oranges", "The favorite defense of all pirates against scurvy! Pretty tasty, too.", true);
	storage_room->containedEntities.push_back(oranges);

	Item* bag = new Item("Bag", "A small bag. Can be used to carry something.", true);
	poopdeck->containedEntities.push_back(bag);

	Item* woodplank = new Item("Wood plank", "A pretty solid plank. Could be used to close a door or cover something damaged.", true);
	storage_room->containedEntities.push_back(woodplank);

	Item* spyglass = new Item("Spyglass", "An old spyglass stolen from the lookout.", true);
	crows_nest->containedEntities.push_back(spyglass);

	//Item creation and storage - UnPickable
	Item* sails = new Item("Sails", "The sails of the ship. You can see the ropes that hold them together on the sides.", false);
	main_deck->containedEntities.push_back(sails);

	Item* helm = new Item("Helm", "The device taking care of controling the direction of the ship. Would be a shame if someone messes with it...", false);
	poopdeck->containedEntities.push_back(helm);

	Item* boat = new Item("Boat", "You can sail away with this lil' boat, but it looks damaged. With some quick repairs it could work.", false);
	main_deck->containedEntities.push_back(boat);

	//Storage of all entities in World class container
	worldEntities.push_back(sleeping_quarters);
	worldEntities.push_back(main_deck);
	worldEntities.push_back(mainguy);
}

World::~World() 
{
	for (vector<Entity*>::iterator it = worldEntities.begin(); it != worldEntities.end(); ++it)
		delete *it;

	worldEntities.clear();
}

void World::readInput(vector<string> userInput) 
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
				cout << "Putting something in/on something" << endl << ">";
			}
			else
			{
				cout << "I didn't understand you, mate" << endl << ">";
			}

			break;

	}
}