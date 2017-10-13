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

	cout << "Yarr world!" << endl << "Welcome to Swashbuckler!" << endl;
	cout << "Story story story..." << endl;
	cout << "Story story story..." << endl;
	cout << "Story story story..." << endl << ">";

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
				theShip.readInput(tokens);
				userInput.clear();
			}
			else
			{
				userInput = userInput + inputKey;
				cout << inputKey;
			}
		}		
	}

	cout << "Thanks for playing Swashbuckler!" << endl << "See ya soon, landlover!" << endl;
	_getch();

	return 0;
}