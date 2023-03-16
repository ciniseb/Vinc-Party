#include "Bouton.h"
#include "constantes.h"

Bouton::Bouton(Dieu nom, bool pianoReussi) {
	this->nom = nom;
	this->pianoReussi = pianoReussi;

}



Bouton::~Bouton() {

}


Dieu Bouton::getNom() {
	return nom;
}

bool Bouton::getPianoReussi() {
	return pianoReussi;
}

char Bouton::dataOut(){
    char data =0;
    data |= 0b00000000;

    switch (nom)
    {
    case D:
        data |= 0b00000000;
        break;
    case I:
        data |= 0b00000001;
        break;
    case E:
        data |= 0b00000010;
        break;
    case U:
        data |= 0b00000011;
        break;
    case JOYSTICK:
        data |= 0b00001000;
        break;
    default: data |= 0b00000000;
        break;
    }

    if(pianoReussi){
        data |= 0b00000100;
    }
    return data;
}