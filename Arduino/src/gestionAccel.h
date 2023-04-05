#pragma once
#include "constantes.h"
#include <Arduino.h>
#include "Accel.h"

class GestionAccel
{
private:
    unsigned long DerniereMesure = 0;
    bool accelerationdetectee = false;
    unsigned long premieremesure =0; 
    float axe_Z1 =0;
    float axe_Z2;
    TypeMotion coup;

public:
    GestionAccel(/* args */);
    ~GestionAccel();
    void init();  
    bool getAccelerationDetecte();
    TypeMotion getCoup();
    void rafraichir();

};
