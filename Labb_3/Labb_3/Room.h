#pragma once

#include "Wall.h"

class Room sealed
{
	std::string title;
	std::string detailedDesc;
	std::vector<Wall> RoomWalls;
	double volume;

public:

	Windows::Devices::Geolocation::Geolocator^ g;
	Room();
	virtual ~Room();
	std::string getTitle();
	void setTitle(std::string);
	void setDetailedDesc(std::string);
	std::string getDetailedDesc();
	void setVolume();
	double getVolume();
	void setCoordinates();
	void getCoordinates();
	void addWall(Wall wall);
	Wall getWall(int i);

};

