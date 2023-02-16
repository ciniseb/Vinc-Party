#ifndef ES_H
#define ES_H
#include <thread>
#include "./include/serial/SerialPort.hpp"
#include "./include/json.hpp"
#include<string>
#include <queue>
#include <mutex>

#define BAUD 1000000           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message
using json = nlohmann::json;

#define BOUTON 1
#define ACCEL 2
#define JOYSTICK 3

#define HAUT 1
#define BAS 2
#define GAUCHE 3
#define DROITE 4
#define ARRET 0
#define ENTER 32

#define TOUCHE_1 5
#define TOUCHE_2 6
#define TOUCHE_3 7
#define TOUCHE_4 8


struct Evenement
{
    int type;
    int arg1;
    int arg2;
};

class ES
{
private:
    std::thread *es_thread = nullptr;
    std::string raw_msg;
    std::string com;
    SerialPort* arduino;
    std::queue<Evenement> evenementRecu;

    json j_msg_send, j_msg_rcv;
    bool SendToSerial(SerialPort* arduino, json j_msg);
    bool RcvFromSerial(SerialPort* arduino, std::string& msg);
    void decoderEvenement(json data);
    void ajouterAuQueue(struct Evenement evenement);
    
    std::mutex lockQueue;




    //Etats pour mode clavier
    bool W = 0;
    bool A = 0;
    bool S = 0;
    bool D = 0;
    bool Z = 0;
    bool X = 0;
    bool C = 0;
    bool V = 0;
    bool Enter = 0;
    
public:
    ES();
    ~ES();
    void exec();
    Evenement prochainEvenement();
    bool evenementDisponible();
};


#endif#pragma once
