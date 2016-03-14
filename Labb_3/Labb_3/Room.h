#pragma once

#include "Wall.h"

class Room sealed
{
	std::string title;
	std::string detailedDesc;
	std::list<Wall> RoomWalls;
public:
	Room();
	virtual ~Room();
	std::string getTitle();
	void setTitle(std::string);
};

