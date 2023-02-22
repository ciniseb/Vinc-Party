#pragma once

enum PointCardinal
{
	NORD,
	SUD,
	EST,
	OUEST,
	AUCUN
};

class Boussole 
{
private:
	PointCardinal pointCardinal;
public:
	Boussole(PointCardinal pointCardinal);
	Boussole(char data);
	~Boussole();
	PointCardinal getPointCardinal();
	char dataOut();

};





