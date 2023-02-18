#pragma once
#include "Evenement.h"
enum TypeMotion
{
	PECHE,
	MINER,
};


class Accel :
	public Evenement
{
private:
	TypeMotion type;
public:
	Accel(TypeMotion type);
	Accel(char data);
	~Accel();
	TypeMotion getType();

};
