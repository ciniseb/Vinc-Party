#pragma once
#include "Evenement.h"
enum TypeMotion
{
	RIEN,
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
	std::string getDesciption();
};
