#include "Bargraph.h"
#include "CONSTANTES.h"
Bargraph::Bargraph(Dieu nomBargraph) :Evenement(BARGRAPH) {
	this->nomBargraph = nomBargraph;

}

Bargraph::~Bargraph() {

}

Dieu Bargraph::getNomBargraph() {
	return nomBargraph;
}

char Bargraph::dataOut() {
	char data = 0b00000000;

    switch (nomBargraph)
    {
    case Dieu::D:
        data |= 0b00000000;
        break;
    case Dieu::I:
        data |= 0b00000001;
        break;
    case Dieu::E:
        data |= 0b00000010;
        break;
    case Dieu::U:
        data |= 0b00000011;
        break;
    default: data |= 0b00000000;
        break;
    }

	return data;
}