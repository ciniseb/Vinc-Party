#pragma once
#include "constantes.h"
#include "Boussole.h"

class GestionBoussole
{
private:
    bool led_n = false;
    bool led_e = false;
    bool led_w = false;
    bool led_s = false;
public:
    GestionBoussole(/* args */);
    ~GestionBoussole();
    void afficher();
    void commande(Boussole boussole);
    void init();
};

