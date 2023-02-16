#pragma once


enum CodeEvenement
{
	BOUTON,
	JOYSTICK,
	ACCEL
};

class Evenement
{
private:
	CodeEvenement type;
public:
	Evenement(CodeEvenement code);
	virtual ~Evenement() = 0;
	CodeEvenement getCode();
};

