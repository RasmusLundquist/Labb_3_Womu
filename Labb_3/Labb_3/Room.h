#pragma once

#include "Wall.h"

class Room sealed
{
	Platform::String^ title;
	Platform::String^ detailedDesc;
	std::vector<Wall> RoomWalls;
	double volume;


public:

	Windows::Devices::Geolocation::Geolocator^ g;
	Room();
	virtual ~Room();
	Platform::String^ getTitle();
	void setTitle(Platform::String^ title);
	void setDetailedDesc(Platform::String^ desc);
	Platform::String^ getDetailedDesc();
	void setVolume();
	double getVolume();
	void setCoordinates();
	void getCoordinates();
	void addWall(Wall wall);
	Wall getWall(int i);

};

