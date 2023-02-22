#pragma once
#include "Evenement.h"

enum PointCardinal
{
	NORD,
	SUD,
	EST,
	OUEST,
	OFF
};

class Boussole :
    public Evenement
{
private:
	PointCardinal pointCardinal;
public:
	Boussole(PointCardinal pointCardinal);
	~Boussole();
	PointCardinal getPointCardinal();
	char dataOut();

};





