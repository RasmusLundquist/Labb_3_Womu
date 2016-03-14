#include "pch.h"
#include "Wall.h"

using namespace std;

Wall::Wall()
{
}


Wall::~Wall()
{
}

string Wall::getTitle() {
	return title;
}

void Wall::setTitle(string name) {
	title = name;
}

string Wall::getDetailedDesc() {
	return detailedDesc;
}

void Wall::setDetailedDesc(string desc) {
	detailedDesc = desc;
}