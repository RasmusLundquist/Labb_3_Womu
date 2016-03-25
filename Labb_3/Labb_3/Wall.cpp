#include "pch.h"
#include "Wall.h"

using namespace std;

Wall::Wall()
{
}


Wall::~Wall()
{
}

Platform::String^ Wall::getTitle() {
	return title;
}

void Wall::setTitle(Platform::String^ name) {
	title = name;
}

Platform::String^ Wall::getDetailedDesc() {
	return detailedDesc;
}

void Wall::setDetailedDesc(Platform::String^ desc) {
	detailedDesc = desc;
}

void Wall::setArea(double a) {
	area = a;
}

double Wall::getArea() {
	return area;
}