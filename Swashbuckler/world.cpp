#include "world.h"
#include "room.h"
#include "player.h"
#include "exit.h"
#include <iostream>
#include <algorithm>

using namespace std;

World::World() 
{
	Room* sleeping_quarters = new Room("Sleeping quarters", "It's kinda dark, and everyone is sleeping. I should not wake anyone...");
	Room* main_deck = new Room("Main deck", "Blablabla maindeck");

	//Exit* exit1 = new Exit("exit1", "sleepTOmain", up);
	//Exit* exit2 = new Exit("exit2", "mainTOsleep", down);

	mainguy = new Player("Slinger", "A young, untrained but clever pirate", sleeping_quarters);

	worldEntities.push_back(sleeping_quarters);
	worldEntities.push_back(main_deck);
	//worldEntities.push_back(exit1);
	//worldEntities.push_back(exit2);
	worldEntities.push_back(mainguy);
}

World::~World() {}

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
				cout << "Checking inventory" << endl << ">";
			}
			else
			{
				cout << "I didn't understand you, mate" << endl << ">";
			}
			break;

		case 2:
			if (userInput[0] == "Go")
			{
				if (userInput[1] == "north") cout << "Going north" << endl << ">";
				else if (userInput[1] == "south") cout << "Going south" << endl << ">";
				else if (userInput[1] == "east") cout << "Going east" << endl << ">";
				else if (userInput[1] == "west") cout << "Going west" << endl << ">";
				else cout << "That's not a valid direction!" << endl << ">";				
			}
			else if (userInput[0] == "Pick")
			{
				cout << "Picking something" << endl << ">";
			}
			else if (userInput[0] == "Drop")
			{
				cout << "Dropping something" << endl << ">";
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