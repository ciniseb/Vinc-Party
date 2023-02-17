#include "Joystick.h"
#include "Evenement.h"

Joystick::Joystick(Direction direction) :Evenement(JOYSTICK) {
	this->direction = direction;

}


Joystick::Joystick(char data):Evenement(JOYSTICK) {
	char code = (data & 0b00000111);
	switch (code)
	{
	case 0: direction = AUCUNE;
		break;
	case 1: direction = HAUT;
		break;
	case 2: direction = BAS;
		break;
	case 3: direction = GAUCHE;
		break;
	case 4: direction = DROITE;
		break;
	default: direction = AUCUNE;
		break;
	}
}

Joystick::~Joystick() {

}


Direction Joystick::getDirection() {
	
	return direction;
}



