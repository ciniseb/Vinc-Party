#include "Boussole.h"


Boussole::Boussole(PointCardinal pointCardinal) {
	this->pointCardinal = pointCardinal;

}

Boussole::Boussole(char data) {
	char code = (data & 0b00000111);
	switch (code)
	{
	case 0: pointCardinal = NORD;
		/* code */
		break;
	case 1: pointCardinal = SUD;
		/* code */
		break;
	case 2: pointCardinal = EST;
		/* code */
		break;
	case 3: pointCardinal = OUEST;
		/* code */
		break;
	case 4: pointCardinal = AUCUN;
		/* code */
		break;
	default:
		break;
	}

}

Boussole::~Boussole() {

}

PointCardinal Boussole::getPointCardinal() {
	return pointCardinal;
}

char Boussole::dataOut() {
	char data = 0b10000000;

	switch (pointCardinal)
	{
	case NORD: data |= 0b00000000;
		break;
	case SUD: data |= 0b00000001;
		break;
	case EST: data |= 0b00000010;
		break;
	case OUEST: data |= 0b00000011;
		break;
	default: data |= 0b00000000;
		break;
	}

	return data;
}