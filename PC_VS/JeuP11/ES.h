#ifndef ES_H
#define ES_H
#include <thread>
#include "./include/serial/SerialPort.hpp"
#include "./include/json.hpp"
#include<string>
#include <queue>
#include <mutex>
#include "Evenement.h"

#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message
using json = nlohmann::json;
using namespace std;







class ES
{
private:
    std::thread *es_thread = nullptr;
    std::string raw_msg;
    std::string com;
    SerialPort* arduino;
    queue<unique_ptr<Evenement>> evenementRecu;

    json j_msg_send, j_msg_rcv;
    bool SendToSerial(SerialPort* arduino, json j_msg);
    bool RcvFromSerial(SerialPort* arduino, string& msg);
    void ajouterAuQueue(std::unique_ptr<Evenement> evenement);
    
    mutex lockQueue;




    //Etats pour mode clavier
    bool W = 0;
    bool A = 0;
    bool S = 0;
    bool D = 0;
    
public:
    ES();
    ~ES();
    void exec();
    std::unique_ptr<Evenement> prochainEvenement();
    bool evenementDisponible();
    void demarrer();
};


#endif#pragma once
