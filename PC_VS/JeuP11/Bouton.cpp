#include "Bouton.h"
#include "Evenement.h"
#include "CONSTANTES.h"


Bouton::Bouton(Dieu nom, bool pianoReussi) :Evenement(BOUTON) {
	this->nom = nom;
	this->pianoReussi = pianoReussi;

}

Bouton::Bouton(char data):Evenement(BOUTON) {
	
	char code = (data & 0b00000011);
	pianoReussi = (data & 0b00000100) >> 2;
	switch (code) {
	case 0: nom = Dieu::D;
		break;
	case 1: nom = Dieu::I;
		break;
	case 2: nom = Dieu::E;
		break;
	case 3: nom = Dieu::U;
		break;
	default:
		nom = Dieu::D;
		break;
	}

}

Bouton::~Bouton() {

}


Dieu Bouton::getNom() {
	return nom;
}

bool Bouton::getPianoReussi() {
	return pianoReussi;
}