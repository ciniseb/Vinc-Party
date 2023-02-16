#include "Joystick.h"
#include "Evenement.h"

Joystick::Joystick(Direction direction) :Evenement(JOYSTICK) {
	this->direction = direction;

}

Joystick::~Joystick() {

}


Direction Joystick::getDirection() {
	return direction;
}