#include "pch.h"
#include "Room.h"

using namespace std;
using namespace Platform::Collections;

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
Platform::String^ Room::getDetailedDesc() {
	return detailedDesc;
}


void Room::setVolume(double area) {
	volume = pow(area, 3);
}

double Room::getVolume() {
	return volume;
}
bool Room::isEmpty() {
	return RoomWalls->Size == 0;
}



void Room::setCoordinates() {
	
}

void Room::getCoordinates() {
	//Denna funktionen ska returnera kordinater när vi vet hur man gör det
}

void Room::addWall(Wall^ wall) {
	//Kontrollera här hur många väggar det är i rummet eller i "appen?"
	RoomWalls->InsertAt(RoomWalls->Size, wall);
}

Wall^ Room::getWall(int id) {
	Wall^ some = RoomWalls->GetAt(id);
	return some;
}


Vector<Wall^>^ Room::getWalls() {
	return RoomWalls;
}


double Room::getLatitude() {
	return latitude;
}

double Room::getLongitude() {
	return longitude;
}

void Room::setLatitude(double lat) {
	latitude = lat;
}

void Room::setLongitude(double lon) {
	longitude = lon;
}
