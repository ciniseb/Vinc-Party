#include "ES.h"
#include <thread>
#include <iostream>
#include <string>
#include "./include/serial/SerialPort.hpp"
#include "./include/json.hpp"
#include <mutex>
#include <Windows.h>
using json = nlohmann::json;


#define MODE_CLAVIER true

ES::ES()
{
	
    // Initialisation du port de communication
    //cout << "Entrer le port de communication du Arduino: ";
    //cin >> com;
    #

    #if MODE_CLAVIER

    #else
    com = "COM3";
    arduino = new SerialPort(com.c_str(), BAUD);
    if (!arduino->isConnected()) {
        std::cerr << "Impossible de se connecter au port " << std::string(com) << ". Fermeture du programme!" << std:endl;
        exit(1);
    }
    #endif // MODE_CLAVIER

    es_thread = new std::thread([this] { exec(); });
}

ES::~ES() {
	es_thread->join();
    delete es_thread;
}


void ES::exec() {

#if MODE_CLAVIER
    while (true) {

        bool tempW = (GetKeyState('W') & 0x8000);
        if (W != tempW) {
            ajouterAuQueue({ JOYSTICK,tempW ? HAUT : ARRET });
        }
        W = tempW;

        bool tempA = (GetKeyState('A') & 0x8000);
        if (A != tempA) {
            ajouterAuQueue({ JOYSTICK,tempA ? GAUCHE : ARRET });
        }
        A = tempA;

        bool tempS = (GetKeyState('S') & 0x8000);
        if (S != tempS) {
            ajouterAuQueue({ JOYSTICK,tempS ? BAS : ARRET });
        }
        S = tempS;

        bool tempD = (GetKeyState('D') & 0x8000);
        if (D != tempD) {
            ajouterAuQueue({ JOYSTICK,tempD ? DROITE : ARRET });
        }
        D = tempD;

        bool tempZ = (GetKeyState('Z') & 0x8000);
        if (Z != tempZ) {
            ajouterAuQueue({ JOYSTICK,tempZ ? TOUCHE_1 : ARRET });
        }
        Z = tempZ;

        bool tempX = (GetKeyState('X') & 0x8000);
        if (X != tempX) {
            ajouterAuQueue({ JOYSTICK,tempX ? TOUCHE_2 : ARRET });
        }
        X = tempX;

        bool tempC = (GetKeyState('C') & 0x8000);
        if (C != tempC) {
            ajouterAuQueue({ JOYSTICK,tempC ? TOUCHE_3 : ARRET });
        }
        C = tempC;

        bool tempV = (GetKeyState('V') & 0x8000);
        if (V != tempV) {
            ajouterAuQueue({ JOYSTICK,tempV ? TOUCHE_4 : ARRET });
        }
        V = tempV;

        bool tempENTER = (GetKeyState(VK_RETURN) & 0x8000);
        if (Enter != tempENTER) {
            ajouterAuQueue({ JOYSTICK,tempENTER ? ENTER : ARRET });
        }
        Enter = tempENTER;

    }

#else
    // Boucle pour tester la communication bidirectionnelle Arduino-PC
    std::cout << "Thread E/S OK" << std::endl;
    while (true) {
        // Envoie message Arduino
        if (!SendToSerial(arduino, j_msg_send)) {
            std::cerr << "Erreur lors de l'envoie du message. " << std::endl;
        }
        // Reception message Arduino
        j_msg_rcv.clear(); // effacer le message precedent
        if (!RcvFromSerial(arduino, raw_msg)) {
            std::cerr << "Erreur lors de la reception du message. " << std::endl;
        }

        // Impression du message de l'Arduino si valide
        if (raw_msg.size() > 0) {
            cout << "raw_msg: " << raw_msg << endl;  // debug
            // Transfert du message en json

            j_msg_rcv = json::parse(raw_msg, nullptr, false);
            if (!j_msg_rcv.is_discarded()) {
                //decoderEvenement(j_msg_rcv);
            }
            else {
                std::cout << "out" << std::endl;
            }

        }

        //Changement de l'etat led

        // Bloquer le fil pour environ 1 sec
        Sleep(300); // 1000ms

    }
#endif // MODE_CLAVIER

}



bool ES::SendToSerial(SerialPort* arduino, json j_msg) {
    // Return 0 if error
    std::string msg = j_msg.dump();
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}


bool ES::RcvFromSerial(SerialPort* arduino, std::string& msg) {
    // Return 0 if error
    // Message output in msg
    std::string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear string
    // Read serialport until '\n' character (Blocking)

    // Version fonctionnel dans VScode, mais non fonctionnel avec Visual Studio

    while (msg.empty() || msg.back() != '\n') {
        if (msg.size() > MSG_MAX_SIZE) {
            return false;
        }

        buffer_size = arduino->readSerialPort(char_buffer, 1);
        str_buffer.assign(char_buffer, buffer_size);
        msg.append(str_buffer);
        if (msg[0] != '{') {
            msg.clear();
        }
    }


    // Version fonctionnelle dans VScode et Visual Studio
    /*buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);*/
    msg.pop_back(); //remove '/n' from string

    return true;
}



void ES::decoderEvenement(json data) {
    if (data["btn_1"])  ajouterAuQueue({ BOUTON, 1 });
    if (data["btn_2"])  ajouterAuQueue({ BOUTON, 2 });
    if (data["btn_3"])  ajouterAuQueue({ BOUTON, 3 });
    if (data["btn_4"])  ajouterAuQueue({ BOUTON, 4 });


}


void ES::ajouterAuQueue(struct Evenement evenement) {
    lockQueue.lock();
    evenementRecu.push(evenement);
    lockQueue.unlock();

}


Evenement ES::prochainEvenement() {
    lockQueue.lock();
    Evenement e = evenementRecu.front();
    evenementRecu.pop();
    lockQueue.unlock();
    return e;
}

bool ES::evenementDisponible() {
    return !evenementRecu.empty();
}