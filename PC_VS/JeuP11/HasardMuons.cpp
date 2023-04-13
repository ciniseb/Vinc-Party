#include "HasardMuons.h"
#include <iostream>

int HasardMuons::valeurAleatoire() {
	valeur = rand();
	std::cout << std::endl << valeur << std::endl;
	return valeur;
}

bool HasardMuons::estMuon(char buf) {
	std::cout << buf << std::endl;
	return (buf &(0b11000000)) == 192 ;
}

void HasardMuons::setValeur(char buf) {
	//valeur = buf & 31;
	srand(buf & 31);
	//std::cout << std::endl << valeur << std::endl;

}

int HasardMuons::valeur = 0;
