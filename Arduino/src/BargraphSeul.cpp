#include "BargraphSeul.h"
#include "constantes.h"
#include <Arduino.h>

    
const int BargraphSeul::ledPin[] = {LED_1_PIN,LED_2_PIN,LED_3_PIN,LED_4_PIN,LED_5_PIN,LED_6_PIN,LED_7_PIN,LED_8_PIN,LED_9_PIN,LED_10_PIN};


BargraphSeul::BargraphSeul(){
}
BargraphSeul::~BargraphSeul(){


}
void  BargraphSeul::demarrer(){
    tempsDebut = millis();
    actif = true;
    intersectionFaite = false;
}

void  BargraphSeul::afficher(){
    for (int i = 0; i < 10; i++)
{
    digitalWrite(ledPin[i],i == position);
}
}



void  BargraphSeul::calculer(){
    unsigned long temps = millis() - tempsDebut;
    if(actif && temps <= DUREE_BARGRAPH){
        position = (int)(temps / (DUREE_BARGRAPH/10));
    }else{
        position = 11;
        actif = false;
    }
    
}

void BargraphSeul::reset(){
    actif = false;
}

bool BargraphSeul::intersection(){
    bool retour = (position <= NBR_BARRE_POUR_OK_PIANO) && actif && !intersectionFaite;
    if(retour) {
        intersectionFaite = true;
        reset();
    }
    return retour;
}