#include "Accel.h"
#include "Evenement.h"


Accel::Accel(TypeMotion type) :Evenement(ACCELEROMETRE) {
	this->type = type;

}

Accel::~Accel() {

}


TypeMotion Accel::getType() {
	return type;
}