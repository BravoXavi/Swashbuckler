#include <iostream>
#include "room.h"

Room::Room(const char* roomName, const char* roomDescription) : Entity(roomName, roomDescription)
{
	name = roomName;
	description = roomDescription;
	entityType = room;
}

Room::~Room() 
{
	for (std::vector<Exit*>::iterator it = exits.begin(); it != exits.end(); ++it)
		delete *it;

	for (std::list<Entity*>::iterator it = containedEntities.begin(); it != containedEntities.end(); ++it)
		delete *it;

	containedEntities.clear();
	exits.clear();
}

const void Room::checkRoom() 
{
	std::cout << "You're in " + name + "." << std::endl << description << std::endl;
}