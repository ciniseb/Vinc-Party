#pragma once
#include "Evenement.h"
class Vibration :
    public Evenement
{
public:
	Vibration();
	~Vibration();
	char dataOut();
};

