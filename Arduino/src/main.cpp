#define USE_TIMER_3 true


/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include <TimerInterrupt.h>

#include "Bouton.h"
#include "Accel.h"
#include "Joystick.h"
#include "Vibration.h"
#include "Boussole.h"
#include "Bargraph.h"

#include "gestionBoussole.h"
#include "gestionAccel.h"
#include "gestionBargraph.h"
#include "gestionBouton.h"
#include "gestionJoystick.h"
#include "gestionVibration.h"
#include "gestionBouton.h"
#include "gestionMuons.h"
#include "gestionAccel.h"


#include "test.h"

#include "constantes.h"

/*------------------------------ Constantes ---------------------------------*/





/*---------------------------- Variables globales ---------------------------*/

GestionBoussole gestionBoussole;
GestionVibration gestionVibration;
GestionBargraph gestionBargraph;
GestionJoystick gestionJoystick;
GestionBouton gestionBouton[] = {GestionBouton(D,BTN_1_PIN),GestionBouton(I,BTN_2_PIN),GestionBouton(E,BTN_3_PIN),GestionBouton(U,BTN_4_PIN),GestionBouton(JOYSTICK,BTN_JOY_PIN)};
GestionMuons gestionMuons;
GestionAccel gestionAccel;

int ledPin[] = {LED_1_PIN,LED_2_PIN,LED_3_PIN,LED_4_PIN,LED_5_PIN,LED_6_PIN,LED_7_PIN,LED_8_PIN,LED_9_PIN,LED_10_PIN};

bool btn_joy = false;



/*------------------------- Prototypes de fonctions -------------------------*/
void lireEntrees();
void multiplexLED();
/*---------------------------- Fonctions "Main" -----------------------------*/

void setup() {
  Serial.begin(BAUD);               // Initialisation de la communication serielle

  gestionBoussole.init();
  gestionVibration.init();
  gestionBargraph.init();
  gestionJoystick.init();
  gestionAccel.init();

  for (int i = 0; i < 4; i++)
  {
    gestionBouton[i].init();
  }

  pinMode(BTN_JOY_PIN,INPUT);

  ITimer3.init();
  ITimer3.attachInterruptInterval(3, multiplexLED);

}

/* Boucle principale (infinie) */
void loop() {


  lireEntrees();
  
  gestionJoystick.rafraichir();
  for (int i = 0; i < 5 ;i++)
  {
    gestionBouton[i].rafraichir();
  }

  gestionMuons.rafraichir();


  gestionBargraph.calculer();


  gestionVibration.afficher();
  gestionBoussole.afficher();
  
  
  gestionAccel.rafraichir();
  



  if(gestionJoystick.getMouvementDetecte()){
    Direction mouvememt = gestionJoystick.getMouvement();
    Joystick joy = Joystick(mouvememt);
    Serial.write(joy.dataOut());
  }

  for (int i = 0; i < 5; i++)
  {
    if(gestionBouton[i].getBoutonDetecte()){
      Dieu nom_bouton = gestionBouton[i].getBouton();
      Bouton bouton = Bouton(nom_bouton,gestionBargraph.intesection(nom_bouton));
      Serial.write(bouton.dataOut());
    }
  }

  if(gestionMuons.getPret()){
    Muons muons = Muons(gestionMuons.getValeur());
    Serial.write(muons.dataOut());
  }

  if(gestionAccel.getAccelerationDetecte()){
    TypeMotion coup = gestionAccel.getCoup();
    Accel accel = Accel(coup);
    Serial.write(accel.dataOut());
    //Serial.print("Coup detecte");
  }

  while (Serial.available())
  {
    char data = Serial.read();

    char type = (data & 0b11000000)>>6;

    switch (type)
    {
    case 0: gestionBargraph.commande(Bargraph(data));
      /* code */
      break;
    case 1: gestionVibration.commande(Vibration());
      /* code */
      break;
    case 2: gestionBoussole.commande(Boussole(data));
      /* code */
      break;
    case 3: gestionBargraph.commande(QuadBargraph(data));
      /* code */
      break;
    
    default:
      break;
    }


    
  }
  


  delay(10);

}

/*---------------------------Definition de fonctions ------------------------*/



void lireEntrees(){
   btn_joy = !digitalRead(BTN_JOY_PIN);

}


void multiplexLED(){
  gestionBargraph.afficher();
}