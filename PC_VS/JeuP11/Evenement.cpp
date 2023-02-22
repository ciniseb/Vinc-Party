#include "Evenement.h"
#include "Bouton.h"
#include "Joystick.h"
#include "Accel.h"
#include <memory>
#include <string>
 
std::unique_ptr<Evenement> Evenement::decoder(char data) {

	char type = (data & 0b11000000) >> 6;
	if (type == 0) {
		return std::make_unique<Bouton>(data);
	}
	if (type == 1) {
		return std::make_unique<Joystick>(data);
	}
	if (type == 2) {
		return std::make_unique<Accel>(data);
	}
}



Evenement::Evenement(CodeEvenement code) {
	this->code = code;
}
Evenement::~Evenement() {

}
CodeEvenement Evenement::getCode() {
	return code;
}


char Evenement::dataOut() {
	return 0;
}


std::string Evenement::getDesciption(){
	return std::string("Evenement generique");
}