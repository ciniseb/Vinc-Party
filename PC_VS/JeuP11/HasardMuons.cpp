#include "HasardMuons.h"

int HasardMuons::valeurAleatoire() {
	return valeur;
}

bool HasardMuons::estMuon(char buf) {
	return (buf & 0b10000000) & 0b01000000;
}

void HasardMuons::setValeur(char buf) {
	valeur = buf & 31;
}
