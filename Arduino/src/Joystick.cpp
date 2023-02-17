#include "Joystick.h"


Joystick::Joystick(Direction direction) {
	this->direction = direction;

}

Joystick::~Joystick() {

}


Direction Joystick::getDirection() {
	return direction;
}


char Joystick::dataOut(){
    char data = 0b01000000;
    switch (direction)
	{
	case HAUT: data |= 0b00000001;
		break;
	case BAS: data |= 0b00000010;
		break;
	case GAUCHE: data |= 0b00000011;
		break;
	case DROITE: data |= 0b00000100;
		break;
	case AUCUNE: data |= 0b00000000;
		break;
	default: data |= 0b00000000;
		break;
	}
    return data;
}