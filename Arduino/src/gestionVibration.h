#pragma once
#include "Vibration.h"

class GestionVibration
{
private:
    unsigned long tempsDepart = 0;
    bool actif = false;
public:
    GestionVibration(/* args */);
    ~GestionVibration();
    void afficher();
    void commande(Vibration vibration);
    void init();
};