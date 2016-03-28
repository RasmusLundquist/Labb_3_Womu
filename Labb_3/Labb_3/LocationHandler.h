#pragma once


ref class LocationHandler sealed
{
public:
	LocationHandler();
	virtual ~LocationHandler();
	void createLocationHandle(Room^ room);
	void addLocation(Room^ room);
private:
	Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geofencing::Geofence^>^ locations;
	Windows::Devices::Geolocation::Geofencing::Geofence^ createLocation(std::vector<std::string> container);
	Windows::Devices::Geolocation::Geofencing::Geofence^ createRoomLocation(Room^ room);
	Platform::String^ stringConvertion(std::string string);
};

