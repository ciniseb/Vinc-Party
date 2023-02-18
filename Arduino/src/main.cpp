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


#include "test.h"

#include "constantes.h"

/*------------------------------ Constantes ---------------------------------*/





/*---------------------------- Variables globales ---------------------------*/

GestionBoussole gestionBoussole;
GestionVibration gestionVibration;
GestionBargraph gestionBargraph;
GestionJoystick gestionJoystick;

int ledPin[] = {LED_1_PIN,LED_2_PIN,LED_3_PIN,LED_4_PIN,LED_5_PIN,LED_6_PIN,LED_7_PIN,LED_8_PIN,LED_9_PIN,LED_10_PIN};


bool bargraph[4][10];

bool btn_1 = false;
bool btn_2 = false;
bool btn_3 = false;
bool btn_4 = false;



bool mot = false;

bool btn_joy = false;
int joy_hb = 0;
int joy_gd = 0;

volatile int compteurMultiplex = 0;



/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(); 
int readMsg();
void lireEntrees();
void ecrireSorties();
void routineTest();
void multiplexLED();
/*---------------------------- Fonctions "Main" -----------------------------*/

void setup() {
  Serial.begin(BAUD);               // Initialisation de la communication serielle
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      bargraph[i][j] = false;
    }
  }

pinMode(BTN_1_PIN,INPUT);
pinMode(BTN_2_PIN,INPUT);
pinMode(BTN_3_PIN,INPUT);
pinMode(BTN_4_PIN,INPUT);


gestionBoussole.init();
gestionVibration.init();
gestionBargraph.init();

gestionJoystick.init();


pinMode(BTN_JOY_PIN,INPUT);

  


ITimer3.init();
ITimer3.attachInterruptInterval(3, multiplexLED);

}

/* Boucle principale (infinie) */
void loop() {


  lireEntrees();
  
  gestionJoystick.rafraichir();


  gestionBargraph.calculer();


  gestionVibration.afficher();
  gestionBoussole.afficher();





  if(btn_1){
    Bouton btn = Bouton(D);
    char test = btn.dataOut();
    Serial.write(test);
    delay(10);
  }

  if(btn_2){
    Bouton btn = Bouton(I);
    char test = btn.dataOut();
    Serial.write(test);
    delay(10);
  }

  if(btn_3){
    Bouton btn = Bouton(E);
    char test = btn.dataOut();
    Serial.write(test);
    delay(10);
  }

  if(btn_4){
    Bouton btn = Bouton(U);
    char test = btn.dataOut();
    Serial.write(test);
    delay(10);
  }


  if(gestionJoystick.getMouvementDetecte()){
    Direction mouvememt = gestionJoystick.getMouvement();
    Joystick joy = Joystick(mouvememt);
    Serial.write(joy.dataOut());
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
    
    default:
      break;
    }


    
  }
  


  delay(10);

}

/*---------------------------Definition de fonctions ------------------------*/



void lireEntrees(){
   btn_1 = !digitalRead(BTN_1_PIN);
   btn_2 = !digitalRead(BTN_2_PIN);
   btn_3 = !digitalRead(BTN_3_PIN);
   btn_4 = !digitalRead(BTN_4_PIN);


   btn_joy = !digitalRead(BTN_JOY_PIN);

}


/*void multiplexLED(){
if(compteurMultiplex == 0){
        digitalWrite(barPin[3],LOW);
    }else{
        digitalWrite(barPin[compteurMultiplex-1],LOW);
    }



    for (int i = 0; i < 10; i++)
    {
        digitalWrite(ledPin[i],bargraph[compteurMultiplex][i]);
    }

    digitalWrite(barPin[compteurMultiplex],HIGH);

    compteurMultiplex++;

    if(compteurMultiplex >= 4){
        compteurMultiplex =0;
    }

}*/


void multiplexLED(){
  gestionBargraph.afficher();
}