#include <iostream>
#include "room.h"

using namespace std;

Room::Room(const char* roomName, const char* roomDescription) : Entity(roomName, roomDescription)
{
	name = roomName;
	description = roomDescription;
	entityType = room;
}

Room::~Room() {}

void Room::checkRoom() 
{
	cout << "You're in " + name + "." << endl << description << endl;
}