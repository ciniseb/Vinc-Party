#pragma once
#include "constantes.h"
#include "Joystick.h"

class GestionJoystick
{
private:
    int axeHautBas = 0;
    int axeGaucheDroite = 0;
    bool mouvementDetecte =false;
    Direction mouvement;
public:
    GestionJoystick(/* args */);
    ~GestionJoystick();
    void init();
    bool getMouvementDetecte();
    Direction getMouvement();
    void rafraichir();
};
