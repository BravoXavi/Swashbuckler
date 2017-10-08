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

	cout << "Yarr world!" << endl << "Welcome to Swashbuckler!" << endl << ">";
	theShip.mainguy->Look();

	while (1) 
	{		
		getline(cin, userInput);
		if (userInput != "") 
		{
			istringstream iss(userInput);
			vector<string> tokens{ istream_iterator<string>{iss},
				istream_iterator<string>{} };

			theShip.readInput(tokens);	
		}

		else if (userInput == "Exit") 
		{
			break;
		}

		else
		{
			cout << ">";
		}
	}

	cout << "Thanks for playing Swashbuckler!" << endl << "See ya soon, landlover!" << endl;
	_getch();

	return 0;
}