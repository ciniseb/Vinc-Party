#include "constantes.h"
#include "Bouton.h"
#include "gestionBouton.h"
#include <Arduino.h>


GestionBouton::GestionBouton(Dieu bouton, int pin){
    this->bouton = bouton;
    this->pin =pin;
    etatActuel =false;
    detection =false;
    etatAncien =false;
}

GestionBouton::~GestionBouton(){

}

void GestionBouton::init(){
    pinMode(pin,INPUT);
}

bool GestionBouton::getBoutonDetecte(){
    return detection;
}

Dieu GestionBouton::getBouton(){
    return bouton;
}

void GestionBouton::rafraichir(){
    etatActuel = !digitalRead(pin);
    if ((etatActuel != etatAncien) && etatActuel ){
        detection = true;
        
    }else{
        detection =false;
    }
    etatAncien = etatActuel;
}
