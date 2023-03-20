#pragma once
#include "constantes.h"
#include <Arduino.h>
#include "Accel.h"

class GestionAccel
{
private:
    unsigned long DerniereMesure = 0;
    bool accelerationdetectee = false;
    bool etatancien =false;
    bool etatactuel = true;
    TypeMotion coup;

public:
    GestionAccel(/* args */);
    ~GestionAccel();
    void init();  
    bool getAccelerationDetecte();
    TypeMotion getCoup();
    void rafraichir();

};
