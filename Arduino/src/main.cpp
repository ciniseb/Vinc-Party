/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
*/

/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 9600        // Frequence de transmission serielle
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

int compteurMultiplex = 0;


/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(); 
void readMsg();
void serialEvent();
void lireEntrees();
void ecrireSorties();
void routineTest();
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
  
}

/* Boucle principale (infinie) */
void loop() {

  if(shouldRead_){
    readMsg();
    sendMsg();
  }

  routineTest();



  lireEntrees();
  ecrireSorties();





  //Serial.println(potValue);          // debug
  //delay(10);  // delais de 10 ms
}

/*---------------------------Definition de fonctions ------------------------*/

void serialEvent() { shouldRead_ = true; }


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
  //doc["analog"] = potValue;

  // Serialisation
  serializeJson(doc, Serial);

  // Envoie
  Serial.println();
  shouldSend_ = false;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
void readMsg(){
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;

  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(doc, Serial);
  shouldRead_ = false;

  // Si erreur dans le message
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  // Analyse des éléments du message message
  parse_msg = doc["led"];
  if (!parse_msg.isNull()) {
    // mettre la led a la valeur doc["led"]
  }
}


void lireEntrees(){
  bool btn_1 = digitalRead(BTN_1_PIN);
  bool btn_2 = digitalRead(BTN_2_PIN);
  bool btn_3 = digitalRead(BTN_3_PIN);
  bool btn_4 = digitalRead(BTN_4_PIN);


  bool btn_joy = digitalRead(BTN_JOY_PIN);
  int joy_hb = 0;
  int joy_gd = 0;

}

void ecrireSorties(){
  digitalWrite(LED_N_PIN,led_n);
  digitalWrite(LED_E_PIN,led_e);
  digitalWrite(LED_W_PIN,led_w);
  digitalWrite(LED_S_PIN,led_s);

  digitalWrite(BAR_1_PIN,LOW);
  digitalWrite(BAR_2_PIN,LOW);
  digitalWrite(BAR_3_PIN,LOW);
  digitalWrite(BAR_4_PIN,LOW);
  digitalWrite(MOT_PIN,mot);


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
  Serial.println(compteurMultiplex);
  
}



void routineTest(){
  int testNo = (millis() / 500) % 18;

  led_n = false;
  led_e = false;
  led_w = false;
  led_s = false;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      bargraph[i][j] = false;
    }
  }

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
    bargraph[0][0] = true;
    bargraph[0][2] = true;
    bargraph[1][1] = true;
    bargraph[2][0] = true;
    bargraph[0][0] = true;
    bargraph[2][2] = true;
    bargraph[3][0] = true;
    bargraph[3][1] = true;
    bargraph[3][2] = true;
    break;




  default: {
              int ledNo = testNo - 5;
              int barNo = ledNo / 3;
              int posNo = ledNo - (barNo * 3);
              bargraph[barNo][posNo] = true;
              break;
           }
    
  }
}