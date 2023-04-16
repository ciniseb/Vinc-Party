#pragma once
/*====================================================================================================
Fichier: FenetreJeuPiano.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 05 f�vrier 2023
Description: Mini-jeu de piano style Piano tiles
====================================================================================================*/
#ifndef MOTEURJEUPECHE_H
#define MOTEURJEUPECHE_H

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
#include "Moteur.h"
#include "ES.h"
#include "MoteurMiniJeu.h"
#include "CONSTANTES.h"
#include "QuadBargraph.h"
#include "Accel.h"
#include "Vibration.h"
#include "ThreadMoteur.h"

class MoteurJeuPeche : public MoteurMiniJeu
{
private:
    Chronometre chrono;
    //Attribut
    int positionJoueur;
    int positionPoisson;
    int foisReussi;
    bool activation;
    bool firstscan;
    bool pretPecher;
    bool Riviere1Etat;
    bool Riviere2Etat;
    int comptePretPecher;

    double tempsInit;
    double tempsReussi;
    double totalReussi;
    double bit;
    double bitCount;
    double bitPrecedent;
    // Methodes

    bool temps(); // G�re le temps et l'appel des methodes
    void affichage(int); // affiche l'ecran et ses valeurs

public:
    //Constructeurs & destructeurs
    MoteurJeuPeche(ES* threadArduino = nullptr, ThreadMoteur* threadMoteur = nullptr);
    ~MoteurJeuPeche();

    //Getteurs & setteurs
    void setPoisson();
    void getJoueur(Direction touche);
    void verificationJoueurPoisson();
    void initialiser();
    //M�thodes
    void demarrer();
};

#endif
