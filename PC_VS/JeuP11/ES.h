#ifndef ES_H
#define ES_H
#include <thread>
#include "./include/serial/SerialPort.hpp"
#include<string>
#include <queue>
#include <mutex>
#include <memory>
#include "Evenement.h"


#define ARRET 0


#define BAUD 9600           // Frequence de transmission serielle






class ES
{
private:
    std::thread *es_thread = nullptr;
    std::string com;
    SerialPort* arduino;
    std::queue<std::unique_ptr<Evenement>> evenementRecu;
    std::queue<std::unique_ptr<Evenement>> evenementAEnvoyer;

    void ajouterAuQueue(std::unique_ptr<Evenement> evenement);
    
    std::mutex lockQueueRecu;
    std::mutex lockQueueAEnvoyer;

    bool evenementAEnvoyerDisponible();
    std::unique_ptr<Evenement> prochainEvenementAEnvoyer();

#if MODE_CLAVIER
    //Etats pour mode clavier
    bool W = 0;
    bool A = 0;
    bool S = 0;
    bool D = 0;
    bool Z = 0;
    bool X = 0;
    bool C = 0;
    bool V = 0;
    bool H = 0;
    bool B = 0;
    bool Enter = 0;
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


#endif
#pragma once
