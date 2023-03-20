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
    int positionJoueur;
    int positionPoisson;
    int foisReussi;
    bool activation;
    bool firstscan;
    bool pretPecher;
    int comptePretPecher;

    double tempsInit;
    double tempsReussi;
    double totalReussi;
    double bit;
    double bitCount;
    double bitPrecedent;
    // Methodes

    bool Temps(); // G�re le temps et l'appel des methodes
    void AffichageEcran(int mode); // affiche l'ecran et ses valeurs

public:
    //Constructeurs & destructeurs
    FenetreJeuPeche(ES* thread);
    ~FenetreJeuPeche();

    //Getteurs & setteurs
    void setPoisson();
    void getJoueur(Direction touche);
    void VerificationJoueurPoisson();
    void initialiser();
    //M�thodes
    void ouvrir();
};

#endif