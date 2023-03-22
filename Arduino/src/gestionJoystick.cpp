#include "gestionJoystick.h"
#include <Arduino.h>
#include "constantes.h"
#include "Joystick.h"


GestionJoystick::GestionJoystick(/* args */){

}
GestionJoystick::~GestionJoystick(){

}
void GestionJoystick::init(){
    pinMode(JOY_HB_PIN,INPUT);
    pinMode(JOY_GD_PIN,INPUT);
}

bool GestionJoystick::getMouvementDetecte(){
    return mouvementDetecte;
}

Direction GestionJoystick::getMouvement(){
    mouvementDetecte =false;
    return mouvement;
}

void GestionJoystick::rafraichir(){
    axeGaucheDroite = analogRead(JOY_GD_PIN);
    axeHautBas = analogRead(JOY_HB_PIN);
    

    //Algo vite fait pour pouvoir tester
    axeGaucheDroite -= 512;
    axeHautBas -= 512;

    int abs_axeGaucheDroite = abs(axeGaucheDroite);
    int abs_axeHautBas = abs(axeHautBas);
    Direction temporaire;
    //deadzone
    if(abs_axeGaucheDroite < 200 && abs_axeHautBas < 200){
        temporaire = AUCUNE;
    }else{
        
        //Trouver axe dominant
        if(abs_axeGaucheDroite > abs_axeHautBas){
            //GD dominant
            if(axeGaucheDroite > 0){
                temporaire = GAUCHE;
            }else{
                temporaire = DROITE;
            }

        }else{
            //HB dominant
            if(axeHautBas > 0){
                temporaire = BAS;
            }else{
                temporaire = HAUT;
            }
        }
    }

    

    

    if(temporaire != mouvement){
        mouvement = temporaire;
        mouvementDetecte = true;
    }


}