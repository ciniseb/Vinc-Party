#include "Muons.h"


Muons::Muons(int valeur){
	this->valeur = (char)valeur;
}
Muons::Muons(char data) {
	this->valeur = data | 0b00011111;
}
Muons::~Muons(){

}
int Muons::getValeur(){
	return valeur;
}
char Muons::dataOut() {
	char data = 0b11000000;
	data |= ((valeur) & 0b0011111);
	return data;
}