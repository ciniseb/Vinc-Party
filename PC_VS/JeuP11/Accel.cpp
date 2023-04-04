#include "Accel.h"
#include "Evenement.h"
#include <string>


Accel::Accel(TypeMotion type) :Evenement(ACCELEROMETRE) {
	this->type = type;

}

Accel::~Accel() {

}

Accel::Accel(char data):Evenement(ACCELEROMETRE) {
	char code = (data & 0b00000001);
	if (code == 1)
		type = MINER;
	else
		type = PECHE;
}

TypeMotion Accel::getType() {
	return type;
}

std::string Accel::getDesciption() {
	std::string type_str = "";
	if (type == MINER) {
		type_str = "MINER";
	}
	else {
		type_str = "RIEN";
	}

	return "Accelerometre: " + type_str;

}