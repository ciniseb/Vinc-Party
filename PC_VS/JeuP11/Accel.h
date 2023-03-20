#pragma once
#include "Evenement.h"
enum TypeMotion
{
	MINER,
	RIEN,
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
