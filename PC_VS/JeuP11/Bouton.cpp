#include "Bouton.h"

Bouton::Bouton(NomBouton nom) :Evenement(BOUTON) {
	this->nom = nom;

}

Bouton::~Bouton() {

}


NomBouton Bouton::getNom() {
	return nom;
}