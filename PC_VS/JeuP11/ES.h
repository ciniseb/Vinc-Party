#ifndef ES_H
#define ES_H
#include <thread>
#include "./include/serial/SerialPort.hpp"
#include<string>
#include <queue>
#include <mutex>
#include "Evenement.h"

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
    bool Z = 0;
    bool X = 0;
    bool C = 0;
    bool V = 0;
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
