#include "Joystick.h"

Joystick::Joystick(Direction direction) :Evenement(JOYSTICK) {
	this->direction = direction;

}

Joystick::~Joystick() {

}


Direction Joystick::getDirection() {
	return direction;
}