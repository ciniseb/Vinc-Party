#include "Accel.h"

Accel::Accel(TypeMotion type)  {
	this->type = type;

}

Accel::~Accel() {

}

char Accel::dataOut(){
    char data = 0b10000000;
    data |= (type == MINER);
    return data;
}

TypeMotion Accel::getType() {
	return type;
}