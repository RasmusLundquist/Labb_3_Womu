#include "pch.h"
#include "Room.h"

using namespace std;

Room::Room()
{
}


Room::~Room()
{
}

Platform::String^ Room::getTitle() {
	return title;
}

void Room::setTitle(Platform::String^ name) {
	title = name;
}

void Room::setDetailedDesc(Platform::String^ desc) {
	detailedDesc = desc;
}


void Room::setVolume() {
	
}

double Room::getVolume() {
	return volume;
}

void Room::setCoordinates() {
	g = ref new Windows::Devices::Geolocation::Geolocator();
}

void Room::getCoordinates() {
	//Denna funktionen ska returnera kordinater n�r vi vet hur man g�r det
}

void Room::addWall(Wall wall) {
	//Kontrollera h�r hur m�nga v�ggar det �r i rummet eller i "appen?"
	RoomWalls.insert(RoomWalls.end(), wall);
}

Wall Room::getWall(int id) {
	Wall some = RoomWalls.at(id);
	return some;
}



