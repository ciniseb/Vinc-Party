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
	type = code ? PECHE : MINER;
}

TypeMotion Accel::getType() {
	return type;
}

std::string Accel::getDesciption() {
	std::string type_str = "";
	if (type == PECHE) {
		type_str = "PECHE";
	}
	else {
		type_str = "MINER";
	}

	return "Accelerometre: " + type_str;

}