#pragma once
class Wall sealed
{
	std::string title;
	std::string detailedDesc;
	double area;
public:
	Wall();
	virtual ~Wall();
	std::string getTitle();
	void setTitle(std::string);
	std::string getDetailedDesc();
	void setDetailedDesc(std::string);
	void setArea(double);
	double getArea();
};

