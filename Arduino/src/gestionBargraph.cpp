#include "gestionBargraph.h"
#include "constantes.h"
#include <Arduino.h>

const int GestionBargraph::barPin[] = {BAR_1_PIN,BAR_2_PIN,BAR_3_PIN,BAR_4_PIN};


GestionBargraph::GestionBargraph(/* args */){

}
GestionBargraph::~GestionBargraph(){

}

void GestionBargraph::afficher(){
    if(compteurMultiplex == 0){
        digitalWrite(barPin[3],LOW);
    }else{
        digitalWrite(barPin[compteurMultiplex-1],LOW);
    }

    if(modeQuad){
        digitalWrite(LED_1_PIN, valeurQuad >= 10);
        digitalWrite(LED_2_PIN, valeurQuad >= 9);
        digitalWrite(LED_3_PIN, valeurQuad >= 8);
        digitalWrite(LED_4_PIN, valeurQuad >= 7);
        digitalWrite(LED_5_PIN, valeurQuad >= 6);
        digitalWrite(LED_6_PIN, valeurQuad >= 5);
        digitalWrite(LED_7_PIN, valeurQuad >= 4);
        digitalWrite(LED_8_PIN, valeurQuad >= 3);
        digitalWrite(LED_9_PIN, valeurQuad >= 2);
        digitalWrite(LED_10_PIN, valeurQuad >= 1);

    }else{
        bargraphsListe[compteurMultiplex].afficher();
    }


    

    digitalWrite(barPin[compteurMultiplex],HIGH);

    compteurMultiplex++;

    if(compteurMultiplex >= 4){
        compteurMultiplex =0;
    }
}


void GestionBargraph::commande(Bargraph bargraph){
    modeQuad = false;
    bargraphsListe[bargraph.getNomBargraph()].demarrer();
    /*switch (bargraph.getNomBargraph())
    {
	case 0: bargraphsListe[0].demarrer();
		break;
	case 1: bargraphsListe[1].demarrer();
		break;
	case 2: bargraphsListe[2].demarrer();
		break;
	case 3: bargraphsListe[3].demarrer();
		break;
	default:
		break;
	}*/
}

void GestionBargraph::commande(QuadBargraph quad_bargraph){
    modeQuad = true;
    valeurQuad = quad_bargraph.getValeur();
    for (int i = 0; i < 4; i++)
    {
        bargraphsListe[i].reset();
    }

}



void GestionBargraph::init(){
    pinMode(LED_1_PIN,OUTPUT);
    pinMode(LED_2_PIN,OUTPUT);
    pinMode(LED_3_PIN,OUTPUT);
    pinMode(LED_4_PIN,OUTPUT);
    pinMode(LED_5_PIN,OUTPUT);
    pinMode(LED_6_PIN,OUTPUT);
    pinMode(LED_7_PIN,OUTPUT);
    pinMode(LED_8_PIN,OUTPUT);
    pinMode(LED_9_PIN,OUTPUT);
    pinMode(LED_10_PIN,OUTPUT);

    for (int i = 0; i < 4; i++)
    {
        pinMode(barPin[i],OUTPUT);
    }
    
}

void GestionBargraph::calculer(){
    if(!modeQuad){
        for (int i = 0; i < 4; i++)
        {
            bargraphsListe[i].calculer();
        }
    }
    

}