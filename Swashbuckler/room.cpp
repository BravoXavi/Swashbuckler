#include <iostream>
#include "room.h"
#include "exit.h"

Room::Room(const char* roomName, const char* roomDescription) : Entity(roomName, roomDescription)
{
	name = roomName;
	description = roomDescription;
	entityType = room;
}

Room::~Room() 
{}