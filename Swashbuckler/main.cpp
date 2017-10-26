#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include "world.h"

using namespace std;

int main() {

	string userInput;
	World theShip;
	char inputKey;
	vector<string> tokens;

	cout << "Welcome to SWASHBUCKLER! - The true pirates Zork-like game" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "You wake up on the ship, in the middle of the night, with a sound different than the usual snoring of the crew. Steps." << endl;
	cout << "With a glance, you see the Captain passing silently between everyone. You notice a small letter with the navy seal falling from his pocket. THE NAVY SEAL?!" << endl;
	cout << "You wait until the captain goes back to his room and check the letter. Bad news. Very, very bad news." << endl;
	cout << "A true pirate would fight the Captain to take command of the ship and save your crew. A true pirate." << endl;
	cout << "A pity that you're just a novice! YOU BETTER GET OUT OF HERE SOON, LAD!!" << endl;
	cout << "---------------------------------------------" << endl << ">";

	theShip.worldTimer = clock();

	while (1) 
	{	
		//User Input loop
		if (_kbhit())
		{
			inputKey = _getch();
			
			if (inputKey == '\b')
			{
				if (userInput.size() > 0) userInput.pop_back();
				cout << '\b';
				cout << ' ';
				cout << '\b';
			}
			else if (inputKey == '\r')
			{
				string buf;
				stringstream ss(userInput);
				while (ss >> buf)
					tokens.push_back(buf);

				userInput.clear();
			}
			else
			{
				userInput = userInput + inputKey;
				cout << inputKey;
			}
		}

		//Update the world turn (Affects NPC behaviour)
		if (theShip.worldTurn(tokens))
		{
			tokens.clear();
		}

		//Ending step (Good or Bad)
		if (theShip.mainguy->escaped || theShip.badguy->shot)
		{
			theShip.ending();			
			break;
		}
	}

	cout << "---------------------------------------------" << endl;
	cout << "Thanks for playing Swashbuckler!" << endl << "See ya soon, landlubber!" << endl;
	cout << "Xavier (Zelleryon) Bravo" << endl;
	_getch();

	return 0;
}