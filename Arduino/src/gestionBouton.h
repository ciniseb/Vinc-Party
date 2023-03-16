#pragma once
#include "constantes.h"
#include "Bouton.h"

class GestionBouton
{
private:
    Dieu bouton;
    int pin;
    bool etatActuel;
    bool etatAncien;
    bool detection;
public:
    GestionBouton(Dieu bouton, int pin);
    ~GestionBouton();
    void init();
    bool getBoutonDetecte();
    bool getPianoReussi();
    Dieu getBouton();
    void rafraichir();
};