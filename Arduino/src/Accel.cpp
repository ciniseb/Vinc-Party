#include "Accel.h"

Accel::Accel(TypeMotion type)  {
	this->type = type;

}

Accel::~Accel() {

}

char Accel::dataOut(){
    char data = 0b10000000;
    if (type == MINER)
    {
        data |= 0b00000001;
        return data;
    }
    else  
    data |= 0b00000000;
    return data;
}

TypeMotion Accel::getType() {
	return type;
}