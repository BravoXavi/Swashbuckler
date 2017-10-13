#include <iostream>
#include "room.h"

Room::Room(const char* roomName, const char* roomDescription) : Entity(roomName, roomDescription)
{
	name = roomName;
	description = roomDescription;
	entityType = room;
}

Room::~Room() {}

void Room::checkRoom() 
{
	std::cout << "You're in " + name + "." << std::endl << description << std::endl;
}