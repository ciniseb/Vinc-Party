#include "ES.h"
#include <thread>
#include <iostream>
#include <string>
#include "./include/serial/SerialPort.hpp"
#include "./include/json.hpp"
using json = nlohmann::json;

ES::ES() {
	
	// Initialisation du port de communication
	//cout << "Entrer le port de communication du Arduino: ";
	//cin >> com;
	/*com = "COM3";
	arduino = new SerialPort(com.c_str(), BAUD);
	if (!arduino->isConnected()) {
        std::cerr << "Impossible de se connecter au port " << std::string(com) << ". Fermeture du programme!" << std::endl;
		exit(1);
	}

    es_thread = new std::thread([this] { exec(); });*/
}

ES::~ES() {
	es_thread->join();
}


void ES::exec() {
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
            //cout << "raw_msg: " << raw_msg << endl;  // debug
            // Transfert du message en json

            j_msg_rcv = json::parse(raw_msg);
            std::cout << raw_msg << std::endl;
        }

        //Changement de l'etat led

        // Bloquer le fil pour environ 1 sec
        Sleep(50); // 1000ms

    }
	

	
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

        buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
        str_buffer.assign(char_buffer, buffer_size);
        msg.append(str_buffer);
    }


    // Version fonctionnelle dans VScode et Visual Studio
    /*buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);*/
    msg.pop_back(); //remove '/n' from string

    return true;
}