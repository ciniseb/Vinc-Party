#include "Accel.h"
#include "Evenement.h"


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