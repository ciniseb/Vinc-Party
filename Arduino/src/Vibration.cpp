#include "Vibration.h"


Vibration::Vibration() {

}

Vibration::~Vibration() {

}


char Vibration::dataOut() {
	char data = 0b01000000;;
	return data;
}
