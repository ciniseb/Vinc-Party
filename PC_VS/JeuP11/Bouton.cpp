#include "Bouton.h"
#include "Evenement.h"


Bouton::Bouton(NomBouton nom, bool pianoReussi) :Evenement(BOUTON) {
	this->nom = nom;
	this->pianoReussi = pianoReussi;

}

Bouton::Bouton(char data):Evenement(BOUTON) {
	
	char code = (data & 0b00000011);
	pianoReussi = (data & 0b00000100) >> 2;
	switch (code) {
	case 0: nom = D;
		break;
	case 1: nom = I;
		break;
	case 2: nom = E;
		break;
	case 3: nom = U;
		break;
	default:
		nom = D;
		break;
	}

}

Bouton::~Bouton() {

}


NomBouton Bouton::getNom() {
	return nom;
}

bool Bouton::getPianoReussi() {
	return pianoReussi;
}