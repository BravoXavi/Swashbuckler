#include "world.h"
#include "room.h"
#include "player.h"
#include <iostream>
#include <algorithm>

using namespace std;

World::World() 
{
	Room sleeping_quarters("Sleeping quarters","It's kinda dark, and everyone is sleeping. I should not wake anyone...");
	Room main_deck("Main deck", "Blablabla maindeck");

	Player mainguy("Slinger", "A young, untrained but clever pirate");
}

World::~World() {}

void World::readInput(vector<string> userInput) 
{
	switch ( userInput.size() )
	{
		case 1:
			if (userInput[0] == "Look")
			{
				cout << "Looking at something" << endl << ">";
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