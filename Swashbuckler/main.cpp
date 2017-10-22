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
	vector<string> tokens;

	std::cout << "Welcome to Swashbuckler! - The true pirates Zork-like game" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "You wake up in the ship, in the middle of the night, with a sound different than the usual snoring of the crew. Steps." << std::endl;
	std::cout << "With a quick look, you see the Captain passing silently between everyone. You notice a small letter with the navy seal falling from his pocket. THE NAVY SEAL?!" << std::endl;
	std::cout << "You wait until the captain goes back to his room and check the letter. Bad news. Very, very bad news." << std::endl;
	std::cout << "A true pirate would fight the Captain to take command of the ship and save your crew. A true pirate." << std::endl;
	std::cout << "YOU BETTER GET OUT OF HERE SOON, LAD!!" << std::endl;
	std::cout << "---------------------------------------------" << std::endl << ">";

	theShip.worldTimer = clock();

	while (1) 
	{			
		if (_kbhit())
		{
			inputKey = _getch();
			
			if (inputKey == '\b')
			{
				if (userInput.size() > 0) userInput.pop_back();
				std::cout << '\b';
				std::cout << ' ';
				std::cout << '\b';
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
				std::cout << inputKey;
			}
		}

		if (theShip.worldTurn(tokens))
		{
			tokens.clear();
		}

		if (theShip.mainguy->escaped || theShip.badguy->shot)
		{
			theShip.ending();			
			break;
		}
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Thanks for playing Swashbuckler!" << endl << "See ya soon, landlubber!" << std::endl;
	std::cout << "Xavier (Zelleryon) Bravo" << std::endl;
	_getch();

	return 0;
}