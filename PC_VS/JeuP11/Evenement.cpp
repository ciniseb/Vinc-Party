#include "Evenement.h"
#include "Bouton.h"
#include "Joystick.h"
#include "Accel.h"
#include <memory>

 
std::unique_ptr<Evenement> Evenement::decoder(char data) {

	char type = (data & 0b11000000) >> 6;
	if (type == 0) {
		return std::make_unique<Bouton>(data);
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
