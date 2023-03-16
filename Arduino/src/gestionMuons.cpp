#include "gestionMuons.h"
#include <Arduino.h>
#include "constantes.h"
#include "Muons.h"


GestionMuons::GestionMuons(/* args */){

}
GestionMuons::~GestionMuons(){

}
void GestionMuons::init(){
    pinMode(MUONS_PIN,INPUT);
}

bool GestionMuons::getPret(){
    return pret;
}

int GestionMuons::getValeur(){
    pret = false;
    return valeur;
}

void GestionMuons::rafraichir(){
    if(millis() - tempsDerniereMesure >= 1000){
        tempsDerniereMesure = millis();
        valeur = static_cast<char>(rand()) & 0b00011111;
        pret = true;
    }    


}