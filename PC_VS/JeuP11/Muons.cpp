#include "Muons.h"
#include <string>

Muons::Muons(int valeur):Evenement(MUONS){
	this->valeur = valeur;
}
Muons::Muons(char data):Evenement(MUONS) {
	this->valeur = static_cast<int>(data & 0b00011111);
}
Muons::~Muons(){

}
int Muons::getValeur(){
	return (int)valeur;
}
char Muons::dataOut() {
	char data = 0b11000000;
	data |= (((char)valeur) & 0b0011111);
	return data;
}

std::string Muons::getDesciption() {
	return std::string("Muons: ") + std::to_string(valeur);
}