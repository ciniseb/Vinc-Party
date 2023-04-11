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
    pinMode(47,INPUT);
    PRR1 &= ~(1<<PRTIM5); //bit dans le power saving pour activer le compteur/timer 5
    TCCR5A &= 0b11111100; //Mode normal
    TCCR5B &= 0b11100111; //Mode nornal
    TCCR5B |= (0b00001111); //Source externe du clock sur la pin T5 (D47) + Mode CTC
    OCR5A = 0b00011111; // Compter jusqua 0b00011111 (31)
    TCNT5 = 0; //Reset du compteur
}

bool GestionMuons::getPret(){
    return pret;
}

int GestionMuons::getValeur(){
    pret = false;
    return valeur;
}

void GestionMuons::rafraichir(){
    /*if(millis() - tempsDerniereMesure >= 1000){
        tempsDerniereMesure = millis();
        valeur = static_cast<char>(rand()) & 0b00011111;
        pret = true;
    }*/    


    if(millis() - tempsDerniereMesure >= 1000){
        tempsDerniereMesure = millis();
        valeur = static_cast<char>(TCNT5) & 0b00011111;
        pret = true;
        //Serial.print("\n Valeur TCNT5: ");
        //Serial.println(valeur);
    }    

}