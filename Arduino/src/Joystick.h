#pragma once
enum Direction
{
	HAUT,
	BAS,
	GAUCHE,
	DROITE,
	AUCUNE
};


class Joystick 
{
private:
	Direction direction;
public:
	Joystick(Direction direction);
	Joystick(char data);
	~Joystick();
	Direction getDirection();
    char dataOut();

};
