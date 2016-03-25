#pragma once
ref class Wall sealed
{
	Platform::String^ title;
	Platform::String^ detailedDesc;
	double area;
public:
	Wall();
	virtual ~Wall();
	Platform::String^ getTitle();
	void setTitle(Platform::String^ title);
	Platform::String^ getDetailedDesc();
	void setDetailedDesc(Platform::String^ desc);
	void setArea(double);
	double getArea();
};

