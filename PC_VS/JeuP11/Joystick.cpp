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



std::string Joystick::getDesciption() {
	std::string direction_str = "_";

	switch (direction)
	{
	case HAUT: direction_str = "vers le HAUT";
		break;
	case BAS: direction_str = "vers le BAS";
		break;
	case GAUCHE: direction_str = "vers la GAUCHE";
		break;
	case DROITE: direction_str = "vers la DROITE";
		break;
	case AUCUNE: direction_str = "AUCUNE";
		break;
	default:
		break;
	}


	return std::string("Joystick: ") + direction_str;
}


