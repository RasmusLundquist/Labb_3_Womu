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
