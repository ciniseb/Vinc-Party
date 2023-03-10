#pragma once
#include "Evenement.h"
#include <string>
enum Direction
{
	HAUT,
	BAS,
	GAUCHE,
	DROITE,
	AUCUNE
};


class Joystick :
	public Evenement
{
private:
	Direction direction;
public:
	Joystick(Direction direction);
	Joystick(char data);
	~Joystick();
	Direction getDirection();
	std::string getDesciption();

};
