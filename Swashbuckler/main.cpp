#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include "world.h"

using namespace std;

int main() {

	string userInput;
	World theShip;

	cout << "Yarr world!" << endl << "Welcome to Swashbuckler!" << endl;

	while (1) 
	{
		getline(cin, userInput);
		if (userInput == "Exit") 
		{
			break;
		}
	}

	cout << "Thanks for playing Swashbuckler!" << endl << "See ya soon, landlover!" << endl;
	_getch();

	return 0;
}