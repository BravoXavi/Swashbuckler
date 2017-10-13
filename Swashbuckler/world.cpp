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
	Room* sleeping_quarters = new Room("Sleeping quarters", "It's kinda dark, and everyone is sleeping. I should not wake anyone...");
	Room* main_deck = new Room("Main deck", "Blablabla maindeck");

	Exit* exit1 = new Exit(up, sleeping_quarters, main_deck);
	Exit* exit2 = new Exit(down, main_deck, sleeping_quarters);

	sleeping_quarters->exits.push_back(exit1);
	main_deck->exits.push_back(exit2);

	mainguy = new Player("Slinger", "A young, untrained but clever pirate", sleeping_quarters);

	Item* sword = new Item("Cutlass", "A slightly old, ugly but effective weapon.", true);
	Item* letter = new Item("Letter", "Long description...", true);

	sleeping_quarters->containedEntities.push_back(sword);
	sleeping_quarters->containedEntities.push_back(letter);

	worldEntities.push_back(sleeping_quarters);
	worldEntities.push_back(main_deck);
	worldEntities.push_back(mainguy);
}

World::~World() 
{
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
			if (userInput[0] == "Put")
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