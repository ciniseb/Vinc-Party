#include "gestionBoussole.h"
#include "constantes.h"
#include <Arduino.h>

GestionBoussole::GestionBoussole(/* args */){

}
GestionBoussole::~GestionBoussole(){

}

void GestionBoussole::afficher(){
    digitalWrite(LED_N_PIN,led_n);
    digitalWrite(LED_E_PIN,led_e);
    digitalWrite(LED_W_PIN,led_w);
    digitalWrite(LED_S_PIN,led_s);
}
void GestionBoussole::commande(Boussole boussole){
    led_n = false;
    led_e = false;
    led_w = false;
    led_s = false;

    switch (boussole.getPointCardinal())
    {
    case NORD:
        led_n = true;
        break;
    case SUD:
        led_s = true;
        break;
    case EST:
        led_e = true;
        break;
    case OUEST:
        led_w = true;
        break;
    default:
        break;
    } 
}
void GestionBoussole::init(){
    pinMode(LED_N_PIN,OUTPUT);
    pinMode(LED_E_PIN,OUTPUT);
    pinMode(LED_W_PIN,OUTPUT);
    pinMode(LED_S_PIN,OUTPUT);
}