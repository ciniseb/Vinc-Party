/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
*/
#define USE_TIMER_3 true


/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include <TimerInterrupt.h>

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 1000000        // Frequence de transmission serielle
#define	BTN_1_PIN	21
#define	BTN_2_PIN	20
#define	BTN_3_PIN	19
#define	BTN_4_PIN	18
#define	BAR_1_PIN	2
#define	BAR_2_PIN	3
#define	BAR_3_PIN	4
#define	BAR_4_PIN	5
#define	LED_1_PIN	31
#define	LED_2_PIN	32
#define	LED_3_PIN	33
#define	LED_4_PIN	34
#define	LED_5_PIN	35
#define	LED_6_PIN	36
#define	LED_7_PIN	37
#define	LED_8_PIN	38
#define	LED_9_PIN	39
#define	LED_10_PIN	40
#define	LED_N_PIN	11
#define	LED_E_PIN	10
#define	LED_W_PIN	9
#define	LED_S_PIN	8
#define	MOT_PIN	7
#define	BTN_JOY_PIN	6
#define	JOY_HB_PIN	A1
#define	JOY_GD_PIN	A0



/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message

int ledPin[] = {LED_1_PIN,LED_2_PIN,LED_3_PIN,LED_4_PIN,LED_5_PIN,LED_6_PIN,LED_7_PIN,LED_8_PIN,LED_9_PIN,LED_10_PIN};
int barPin[] = {BAR_1_PIN,BAR_2_PIN,BAR_3_PIN,BAR_4_PIN};

bool bargraph[4][10];

bool btn_1 = false;
bool btn_2 = false;
bool btn_3 = false;
bool btn_4 = false;

bool led_n = false;
bool led_e = false;
bool led_w = false;
bool led_s = false;

bool mot = false;

bool btn_joy = false;
int joy_hb = 0;
int joy_gd = 0;

volatile int compteurMultiplex = 0;


/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(); 
int readMsg();
void serialEvent();
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
pinMode(BAR_1_PIN,OUTPUT);
pinMode(BAR_2_PIN,OUTPUT);
pinMode(BAR_3_PIN,OUTPUT);
pinMode(BAR_4_PIN,OUTPUT);
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
pinMode(LED_N_PIN,OUTPUT);
pinMode(LED_E_PIN,OUTPUT);
pinMode(LED_W_PIN,OUTPUT);
pinMode(LED_S_PIN,OUTPUT);
pinMode(MOT_PIN,OUTPUT);
pinMode(BTN_JOY_PIN,INPUT);
pinMode(JOY_HB_PIN,INPUT);
pinMode(JOY_GD_PIN,INPUT);
  


ITimer3.init();
ITimer3.attachInterruptInterval(5, multiplexLED);

}

/* Boucle principale (infinie) */
void loop() {

  if(Serial.available()){
    if(readMsg() == 1){
      sendMsg();
    }
  }

  routineTest();


  lireEntrees();
  ecrireSorties();





  //Serial.println(potValue);          // debug
  //delay(10);  // delais de 10 ms
}

/*---------------------------Definition de fonctions ------------------------*/



/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void sendMsg() {
  StaticJsonDocument<500> doc;
  // Elements du message
  doc["time"] = millis();
  doc["btn_1"]=btn_1;
  doc["btn_2"]=btn_2;
  doc["btn_3"]=btn_3;
  doc["btn_4"]=btn_4;
  doc["btn_joy"]=btn_joy;
  doc["joy_hb"]=joy_hb;
  doc["joy_gd"]=joy_gd;

  // Serialisation
  serializeJson(doc, Serial);
  //noInterrupts();
  // Envoie
  Serial.println();
  //interrupts();
  shouldSend_ = false;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
int readMsg(){
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;

    // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(doc, Serial);
  //delay(50);

  // Si erreur dans le message
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return 0;
  }
  
  // Analyse des éléments du message message
  parse_msg = doc["led"];
  led_n=doc["led_n"];
  led_e=doc["led_e"];
  led_w=doc["led_w"];
  led_s=doc["led_s"];
  mot=doc["mot"];
  //bargraph=doc["bargraph"];
  if (!parse_msg.isNull()) {
    // mettre la led a la valeur doc["led"]
  }
  return 1;
}


void lireEntrees(){
   btn_1 = !digitalRead(BTN_1_PIN);
   btn_2 = !digitalRead(BTN_2_PIN);
   btn_3 = !digitalRead(BTN_3_PIN);
   btn_4 = !digitalRead(BTN_4_PIN);


   btn_joy = !digitalRead(BTN_JOY_PIN);
   joy_hb = analogRead(JOY_HB_PIN);
   joy_gd = analogRead(JOY_GD_PIN);

}

void ecrireSorties(){
  digitalWrite(LED_N_PIN,led_n);
  digitalWrite(LED_E_PIN,led_e);
  digitalWrite(LED_W_PIN,led_w);
  digitalWrite(LED_S_PIN,led_s);
  digitalWrite(MOT_PIN,mot);
  //multiplexLED();
  
  
}



void routineTest(){
  int testNo = (millis() / 500) % 19;

  led_n = false;
  led_e = false;
  led_w = false;
  led_s = false;

  

  mot = false;

  switch (testNo)
  {
  case 0:
    led_n =true;
    break;
  case 1:
    led_s =true;
    break;
  case 2:
    led_e =true;
    break;
  case 3:
    led_w =true;
    break;
  case 4:
    mot =true;
    break;
  case 5:
    for(int i =0; i<4;i++){
      for (int j = 0; j < 3; j++)
      {
        bargraph[i][j] = true;
      }
      
    }
    break;
  case 6:
    for(int i =0; i<4;i++){
      for (int j = 0; j < 3; j++)
      {
        bargraph[i][j] = false;
      }
      
    }
    break;



  default: {
              int ledNo = testNo - 6;
              int barNo = ledNo / 3;
              int posNo = ledNo - (barNo * 3);
              bargraph[barNo][posNo] = true;
              break;
           }
    
  }
}


/*void multiplexLED(){
  digitalWrite(BAR_1_PIN,LOW);
  digitalWrite(BAR_2_PIN,LOW);
  digitalWrite(BAR_3_PIN,LOW);
  digitalWrite(BAR_4_PIN,LOW);
  


  for (int i = 0; i < 10; i++)
  {
    digitalWrite(ledPin[i],bargraph[compteurMultiplex][i]);
  }

  digitalWrite(BAR_1_PIN,compteurMultiplex==0);
  digitalWrite(BAR_2_PIN,compteurMultiplex==1);
  digitalWrite(BAR_3_PIN,compteurMultiplex==2);
  digitalWrite(BAR_4_PIN,compteurMultiplex==3);

  compteurMultiplex++;

  if(compteurMultiplex >= 4){
    compteurMultiplex =0;
  }
}*/


void multiplexLED(){

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
}