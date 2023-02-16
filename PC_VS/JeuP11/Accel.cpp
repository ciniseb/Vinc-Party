#include "Accel.h"


Accel::Accel(TypeMotion type) :Evenement(ACCEL) {
	this->type = type;

}

Accel::~Accel() {

}


TypeMotion Accel::getType() {
	return type;
}