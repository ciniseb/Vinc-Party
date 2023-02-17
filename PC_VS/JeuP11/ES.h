#ifndef ES_H
#define ES_H
#include <thread>
#include "./include/serial/SerialPort.hpp"
#include<string>
#include <queue>
#include <mutex>
#include "Evenement.h"

#define BAUD 9600           // Frequence de transmission serielle
using namespace std;



#define MODE_CLAVIER true



class ES
{
private:
    std::thread *es_thread = nullptr;
    std::string raw_msg;
    std::string com;
    SerialPort* arduino;
    queue<unique_ptr<Evenement>> evenementRecu;
    queue<unique_ptr<Evenement>> evenementAEnvoyer;

    void ajouterAuQueue(std::unique_ptr<Evenement> evenement);
    
    mutex lockQueueRecu;
    mutex lockQueueAEnvoyer;

    bool evenementAEnvoyerDisponible();
    std::unique_ptr<Evenement> prochainEvenementAEnvoyer();

#if MODE_CLAVIER
    //Etats pour mode clavier
    bool W = 0;
    bool A = 0;
    bool S = 0;
    bool D = 0;
#endif // MODE_CLAVIER

   
    
public:
    ES();
    ~ES();
    void exec();
    std::unique_ptr<Evenement> prochainEvenement();
    void envoyerEvenement(std::unique_ptr<Evenement> evenement);
    bool evenementDisponible();
    void demarrer();
};


#endif#pragma once
