#include "Bargraph.h"
#include "constantes.h"
Bargraph::Bargraph(Dieu nomBargraph) {
	this->nomBargraph = nomBargraph;

}

Bargraph::Bargraph(char data) {
    char code = (data & 0b00000011);
	switch (code) {
	case 0: nomBargraph = D;
		break;
	case 1: nomBargraph = I;
		break;
	case 2: nomBargraph = E;
		break;
	case 3: nomBargraph = U;
		break;
	default:
		nomBargraph = D;
		break;
	}

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
    default: data |= 0b00000000;
        break;
    }

	return data;
}