#include "QuadBargraph.h"
#include "CONSTANTES.h"
QuadBargraph::QuadBargraph(int valeur) {
    if (valeur > 10) valeur = 10;
    if (valeur < 0) valeur = 0;
    this->valeur = valeur;

}


QuadBargraph::QuadBargraph(char data) {
    valeur = (data & 0b00001111);

}

QuadBargraph::~QuadBargraph() {

}

int QuadBargraph::getValeur() {
    return valeur;
}

char QuadBargraph::dataOut() {
    char data = 0b11000000;
    data |= valeur;

    return data;
}