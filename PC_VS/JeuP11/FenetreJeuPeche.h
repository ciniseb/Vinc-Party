#pragma once
/*====================================================================================================
Fichier: FenetreJeuPiano.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: Mini-jeu de piano style Piano tiles
====================================================================================================*/
#ifndef FENETREJEUPECHE_H
#define FENETREJEUPECHE_H

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
#include "FenetreMiniJeu.h"
#include "CONSTANTES.h"
#include "QuadBargraph.h"
#include "Accel.h"
#include "Vibration.h"

class FenetreJeuPeche : public FenetreMiniJeu
{
private:

#define Menu 0
#define Jeu 1
#define Score 2
    Chronometre chrono;
    //Attribut
    int positionJoueur = 0;
    int positionPoisson = 0;
    int foisReussi = 0;
    bool activation = true;
    bool firstscan = true;
    bool pretPecher = false;
    int comptePretPecher = 0;

    double tempsInit = 0;
    double tempsReussi = 0;
    double totalReussi = 0;
    double bit=0;
    double bitCount = 0;
    double bitPrecedent = 0;
    // Methodes

    bool Temps(); // Gère le temps et l'appel des methodes
    void AffichageEcran(int mode); // affiche l'ecran et ses valeurs

public:
    //Constructeurs & destructeurs
    FenetreJeuPeche(ES* thread);
    ~FenetreJeuPeche();

    //Getteurs & setteurs
    void setPoisson();
    void getJoueur(Direction touche);
    void VerificationJoueurPoisson();
    //Méthodes
    void ouvrir();
};

#endif