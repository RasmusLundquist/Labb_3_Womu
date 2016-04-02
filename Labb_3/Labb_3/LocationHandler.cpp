#include "pch.h"
#include "LocationHandler.h"
#include <string>

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Devices::Geolocation;
using namespace Windows::Devices::Geolocation::Geofencing;
using namespace std;

LocationHandler::LocationHandler()
{
	//Här crashar den
	locations = GeofenceMonitor::Current->Geofences;
}


LocationHandler::~LocationHandler()
{
}

Windows::Devices::Geolocation::Geofencing::Geofence^ LocationHandler::createLocation(vector<string> container) {
	Geofence^ geof;
	BasicGeoposition pos;
	pos.Latitude = atof(container[2].c_str());
	pos.Longitude = atof(container[3].c_str());
	pos.Altitude = 0.0;
	double test = atof(container[26].c_str());
	double radius = 0;
	String^ key = stringConvertion(container[0]);
	MonitoredGeofenceStates states = static_cast<MonitoredGeofenceStates>(0);
	Geocircle^ geoCircle = ref new Geocircle(pos, radius);
	TimeSpan tSpan;
	tSpan.Duration = 1500000;

	if (test == 0) radius = 100;
	else radius = (sqrt(test) / 1.5);

	states = states | MonitoredGeofenceStates::Entered;
	states = states | MonitoredGeofenceStates::Exited;

	geof = ref new Geofence(key, geoCircle, states, false, tSpan);
	return geof;
}

Windows::Devices::Geolocation::Geofencing::Geofence^ LocationHandler::createRoomLocation(Room^ room) {
	Geofence^ geof;

	if (room != nullptr) {
		BasicGeoposition pos;
		pos.Latitude = room->getLatitude();
		pos.Longitude = room->getLongitude();
		pos.Altitude = 0;
		double radius = 0;
		String^ key = room->getTitle();
		MonitoredGeofenceStates states = static_cast<MonitoredGeofenceStates>(0);
		Geocircle^ geoCircle = ref new Geocircle(pos, radius);
		TimeSpan tSpan;
		tSpan.Duration = 1500000;

		if (room->getWall(0) == nullptr || room->getWall(0)->getArea() == 0) radius = 100;
		else radius = (sqrt(room->getWall(0)->getArea()) / 1.5);

		states = states | MonitoredGeofenceStates::Entered;
		states = states | MonitoredGeofenceStates::Exited;

		geof = ref new Geofence(key, geoCircle, states, false, tSpan);
		return geof;
	}
	return nullptr;
}

void LocationHandler::addLocation(Room^ room) {
	String^ title = room->getTitle();
	unsigned int index = 0;
	Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geofencing::Geofence^>^ vector = locations;
	Platform::Collections::Vector<Platform::String^>^ locationIDs = ref new Platform::Collections::Vector<Platform::String^>();
	Geofence^ geof = createRoomLocation(room);

	for each (auto loc in vector) locationIDs->Append(loc->Id);

	if (locationIDs->IndexOf(title, &index)) locations->RemoveAt(index);
	
	locations->InsertAt(0, geof);
}

String^ LocationHandler::stringConvertion(string string) {
	wstring string2 = wstring(string.begin(), string.end());
	
	const wchar_t* string3 = string2.c_str();
	return ref new String(string3);
}