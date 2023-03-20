#pragma once
#include "constantes.h"
#include "gestionAccel.h"

GestionAccel::GestionAccel(/* args */){

}
GestionAccel::~GestionAccel(){

}

void GestionAccel::init(){
    pinMode(ACCEL_Y,INPUT);
    pinMode(ACCEL_Z,INPUT);
}
bool GestionAccel::getAccelerationDetecte(){
    return accelerationdetectee;
}

TypeMotion GestionAccel:: getCoup(){
    accelerationdetectee = false;
    DerniereMesure = millis();
    return coup; 
}


void GestionAccel::rafraichir(){
     float axe_Y = analogRead(ACCEL_Y);
     float axe_Z = analogRead(ACCEL_Z);

    float acceleration = sqrt((axe_Y*axe_Y)+(axe_Z*axe_Z));
    
    //Serial.print("\n");
    //Serial.print(acceleration);
    //delay(1000);
    
    if (millis()-DerniereMesure > 200)
    {
        if (acceleration < miner)
        {
            coup = RIEN;
        }
        else
        {
            coup = MINER;
            accelerationdetectee = true;
        }
    }
}