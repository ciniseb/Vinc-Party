#pragma once
#include "constantes.h"
#include "Muons.h"

class GestionMuons
{
private:
    int valeur;
    unsigned long tempsDerniereMesure = 0;
    int pinMuons =0;
    bool pret = false;

public:
    GestionMuons(/* args */);
    ~GestionMuons();
    void init();
    bool getPret();
    int getValeur();
    void rafraichir();
};
