#include "pch.h"
#include "Room.h"

using namespace std;

Room::Room()
{
}


Room::~Room()
{
}

string Room::getTitle() {
	return title;
}

void Room::setTitle(string name) {
	title = name;
}

void Room::setDetailedDesc(string desc) {
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



