#include "ES.h"
#include <thread>
#include <iostream>
#include <string>
#include "./include/serial/SerialPort.hpp"
#include "./include/json.hpp"
#include <mutex>
#include <Windows.h>
#include "Evenement.h"
#include "Bouton.h"
#include "Joystick.h"
#include "Accel.h"
#include "CONSTANTES.h"








ES::ES() {

}

ES::~ES() {
	es_thread->join();
    delete es_thread;
}

void ES::demarrer() {



    #if MODE_CLAVIER

    #else
    com = "COM3";
    arduino = new SerialPort(com.c_str(), BAUD);
    if (!arduino->isConnected()) {
        std::cerr << "Impossible de se connecter au port " << std::string(com) << ". Fermeture du programme!" << std::endl;
        exit(1);
    }
#endif // MODE_CLAVIER





    es_thread = new std::thread([this] { exec(); });
}

void ES::exec() {

#if MODE_CLAVIER
    //std::cout << "Thread E/S OK" << std::endl;
    while (true) {
        bool tempW = (GetKeyState('W') & 0x8000);
        if (W != tempW) {
            ajouterAuQueue(std::make_unique<Joystick>(tempW ? HAUT : AUCUNE));
        }
        W = tempW;

        bool tempA = (GetKeyState('A') & 0x8000);
        if (A != tempA) {
            ajouterAuQueue(std::make_unique<Joystick>(tempA ? GAUCHE : AUCUNE));
        }
        A = tempA;

        bool tempS = (GetKeyState('S') & 0x8000);
        if (S != tempS) {
            ajouterAuQueue(std::make_unique<Joystick>(tempS ? BAS : AUCUNE));
        }
        S = tempS;

        bool tempD = (GetKeyState('D') & 0x8000);
        if (D != tempD) {
            ajouterAuQueue(std::make_unique<Joystick>(tempD ? DROITE : AUCUNE));
        }
        D = tempD;

        bool tempZ = (GetKeyState('Z') & 0x8000);
        if (Z != tempZ && tempZ == true) {
            ajouterAuQueue(std::make_unique<Bouton>(Dieu::D));
        }
        Z = tempZ;

        bool tempX = (GetKeyState('X') & 0x8000);
        if (X != tempX && tempX == true) {
            ajouterAuQueue(std::make_unique<Bouton>(Dieu::I));
        }
        X = tempX;

        bool tempC = (GetKeyState('C') & 0x8000);
        if (C != tempC && tempC == true) {
            ajouterAuQueue(std::make_unique<Bouton>(Dieu::E));
        }
        C = tempC;

        bool tempV = (GetKeyState('V') & 0x8000);
        if (V != tempV && tempV == true) {
            ajouterAuQueue(std::make_unique<Bouton>(Dieu::U));
        }
        V = tempV;

        bool tempH = (GetKeyState('H') & 0x8000);
        if (H != tempH && tempH == true) {
            ajouterAuQueue(std::make_unique < Accel > (TypeMotion::PECHE));
        }
        H = tempH;

        bool tempB = (GetKeyState('B') & 0x8000);
        if (B != tempB && tempB == true) {
            ajouterAuQueue(std::make_unique<Accel>(TypeMotion::MINER));
        }
        B = tempB;


        ///
        /// !!!!ENTER == BOUTON D!!!! ////
        /// 
        bool tempENTER = (GetKeyState(VK_RETURN) & 0x8000);
        if (Enter != tempENTER && tempENTER == true) {
            ajouterAuQueue(std::make_unique<Bouton>(Dieu::JOYSTICK));
        }
        Enter = tempENTER;

    }

#else
    std::cout << "Thread E/S OK" << std::endl;
    
    char buf = 0;
    while (true) {
        int nbrLu = arduino->readSerialPort(&buf,1);
        if (nbrLu > 0) {
            ajouterAuQueue(Evenement::decoder(buf));
        }

        if (evenementAEnvoyerDisponible()) {
            char txBuf = prochainEvenementAEnvoyer()->dataOut();
            arduino->writeSerialPort(&txBuf,1);
        }

    }



#endif // MODE_CLAVIER

}






void ES::ajouterAuQueue(std::unique_ptr<Evenement> evenement) {
    lockQueueRecu.lock();
    evenementRecu.push(move(evenement));
    lockQueueRecu.unlock();

}


std::unique_ptr<Evenement> ES::prochainEvenement() {
    lockQueueRecu.lock();
    std::unique_ptr<Evenement> e = std::move(evenementRecu.front());
    evenementRecu.pop();
    lockQueueRecu.unlock();
    return e;
}

bool ES::evenementDisponible() {
    return !evenementRecu.empty();
}

bool ES::evenementAEnvoyerDisponible() {
    return !evenementAEnvoyer.empty();
}


std::unique_ptr<Evenement> ES::prochainEvenementAEnvoyer() {
    lockQueueAEnvoyer.lock();
    std::unique_ptr<Evenement> e = std::move(evenementAEnvoyer.front());
    evenementAEnvoyer.pop();
    lockQueueAEnvoyer.unlock();
    return e;
}




void ES::envoyerEvenement(std::unique_ptr<Evenement> evenement) {
    lockQueueAEnvoyer.lock();
    evenementAEnvoyer.push(move(evenement));
    lockQueueAEnvoyer.unlock();
}

