#pragma once

#include "Wall.h"

ref class Room sealed
{
	Platform::String^ title;
	Platform::String^ detailedDesc;
	Platform::Collections::Vector<Wall^>^ RoomWalls;
	double volume;
	double latitude;
	double longitude;


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
	double getLatitude();
	double getLongitude();
	void setLatitude(double lat);
	void setLongitude(double lon);
	void addWall(Wall^ wall);
	Wall^ getWall(int i);
	bool isEmpty();
	Windows::Foundation::Collections::IVector<Wall^>^ getWalls();
};

