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
	return(RoomWalls.size() == 0);
}

void Room::setCoordinates() {
	
}

void Room::getCoordinates() {
	//Denna funktionen ska returnera kordinater när vi vet hur man gör det
}

void Room::addWall(Wall^ wall) {
	//Kontrollera här hur många väggar det är i rummet eller i "appen?"
	RoomWalls.insert(RoomWalls.end(), wall);
}

Wall^ Room::getWall(int id) {
	Wall^ some = RoomWalls.at(id);
	return some;
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