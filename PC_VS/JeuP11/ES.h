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
using namespace std;


#define BOUTON 1
#define ACCEL 2
#define JOYSTICK 3


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
    queue<Evenement> evenementRecu;

    json j_msg_send, j_msg_rcv;
    bool SendToSerial(SerialPort* arduino, json j_msg);
    bool RcvFromSerial(SerialPort* arduino, string& msg);
    void decoderEvenement(json data);
    void ajouterAuQueue(struct Evenement evenement);
    mutex lockQueue;
    
public:
    ES();
    ~ES();
    void exec();
};


#endif#pragma once
