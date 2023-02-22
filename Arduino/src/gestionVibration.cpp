#include "gestionVibration.h"
#include "constantes.h"
#include <Arduino.h>

GestionVibration::GestionVibration(/* args */){

}
GestionVibration::~GestionVibration(){

}

void GestionVibration::afficher(){
    if((millis()-tempsDepart < DUREE_VIBRATION) && actif){
        digitalWrite(MOT_PIN,HIGH);
    }else{
        digitalWrite(MOT_PIN,LOW);
    }
}
void GestionVibration::commande(Vibration vibration){
    tempsDepart = millis();
    actif = true;
}
void GestionVibration::init(){
    pinMode(MOT_PIN,OUTPUT);
}