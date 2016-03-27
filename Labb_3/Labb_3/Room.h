#pragma once

#include "Wall.h"

ref class Room sealed
{
	Platform::String^ title;
	Platform::String^ detailedDesc;
	std::vector<Wall^> RoomWalls;
	double volume;


public:

	Room();
	virtual ~Room();
	Platform::String^ getTitle();
	void setTitle(Platform::String^ title);
	void setDetailedDesc(Platform::String^ desc);
	Platform::String^ getDetailedDesc();
	void setVolume(double area);
	double getVolume();
	void setCoordinates();
	void getCoordinates();
	void addWall(Wall^ wall);
	Wall^ getWall(int i);
	bool isEmpty();

};

