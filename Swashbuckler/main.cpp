#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include "world.h"
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {

	string userInput;
	World theShip;
	char inputKey;

	cout << "Welcome to Swashbuckler!" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "You wake up in the ship, in the middle of the night, with a sound different than the usual snoring of the crew. Steps." << endl;
	cout << "With a quick look, you see the Captain passing silently between everyone. You notice a small letter with the navy seal falling from his pocket. THE NAVY SEAL?!" << endl;
	cout << "You wait until the captain goes back to his room and check the letter. Bad news. Very, very bad news." << endl;
	cout << "A true pirate would fight the Captain to take command of the ship and save your crew. A true pirate." << endl;
	cout << "LET'S GET OUT OF HERE!!" << endl;
	cout << "---------------------------------------------" << endl << ">";

	while (1) 
	{			
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
				istringstream iss(userInput);
				vector<string> tokens{ istream_iterator<string>{iss},
					istream_iterator<string>{} };
				
				std::cout << endl;
				cout << "---------------------------------------------" << endl;
				theShip.readInput(tokens);
				userInput.clear();
			}
			else
			{
				userInput = userInput + inputKey;
				cout << inputKey;
			}
		}

		if (theShip.mainguy->escaped)
		{
			theShip.ending();			
			break;
		}
	}

	std::cout << "---------------------------------------------" << std::endl;
	cout << "Thanks for playing Swashbuckler!" << endl << "See ya soon, landlubber!" << endl;
	cout << "Xavier (Zelleryon) Bravo" << endl;
	_getch();

	return 0;
}