#pragma once
#include "FenetreMiniJeu.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <dos.h>
#include <chrono>
#include <conio.h>

#include "Joystick.h"
#include "Bouton.h"
#include "Chronometre.h"
#include "Fenetre.h"
#include "ES.h"
#include "CR_Vehicule.h"
#include "CONSTANTES.h"



class MoteurCR : public MoteurMiniJeu
{
private:

    Chronometre chrono;
    //Attribut
    int posX = 0;
    int posY = 0;

    CR_Vehicule *vehicules[6];

    // Methodes

    void afficher();


public:
    //Constructeurs & destructeurs
    MoteurCR(ES* thread);
    ~MoteurCR();


    //Méthodes
    void initialiser();
    void demarrer();
};

