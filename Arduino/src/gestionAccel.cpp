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
    //acceleration1 = sqrt((axe_Y*axe_Y)+(axe_Z*axe_Z));
    
    if( millis()-premieremesure > 60)
    {
        
        axe_Z2 = analogRead(ACCEL_Z);
        //acceleration2 = sqrt((axe_Y*axe_Y)+(axe_Z*axe_Z)); 
        
        premieremesure = millis();

        if(axe_Z2 > axe_Z1 + 90)
        {   coup = PECHE;
            //Serial.print("Peche");
            accelerationdetectee = true;
        }
        else if(axe_Z2 +70 < axe_Z1 ) 
        {
            coup = MINER;
            //Serial.print("Mineur");
            accelerationdetectee = true;
        }

        axe_Z1 = axe_Z2; 

    }

    
    /*if (millis()-DerniereMesure > 400 && acceleration > miner)
    {
        if(axe_Y < 430)
        {
            coup = PECHE;
            Serial.print("Peche");
            accelerationdetectee = true;
        } 
        else
        {
            coup = MINER;
            Serial.print("Mineur");
            accelerationdetectee = true;
        }
        
    }*/
}