#ifndef ES_H
#define ES_H
#include <thread>
#include "./include/serial/SerialPort.hpp"
#include "./include/json.hpp"
#include<string>

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
    
    json j_msg_send, j_msg_rcv;
    bool SendToSerial(SerialPort* arduino, json j_msg);
    bool RcvFromSerial(SerialPort* arduino, string& msg);
    
public:
    ES();
    ~ES();
    void exec();
};


#endif#pragma once
