#include "world.h"
#include "room.h"
#include "player.h"
#include <iostream>

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
	cout << "Parsing..." << endl;

	for (vector<string>::iterator it = userInput.begin(); it != userInput.end(); ++it)
		cout << *it << endl;

	cout << "I didn't understand you, mate" << endl << ">";
}