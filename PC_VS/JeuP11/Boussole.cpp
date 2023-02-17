#include "Boussole.h"


Boussole::Boussole(PointCardinal pointCardinal) :Evenement(BOUSSOLE) {
	this->pointCardinal = pointCardinal;

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
	default: data |= 0b00000100;
		break;
	}

	return data;
}