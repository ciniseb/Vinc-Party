#include "Vibration.h"


Vibration::Vibration() :Evenement(VIBRATION) {

}

Vibration::~Vibration() {

}


char Vibration::dataOut() {
	char data = 0b01000000;;
	return data;
}
