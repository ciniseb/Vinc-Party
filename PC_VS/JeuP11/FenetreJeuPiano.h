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
#ifndef FENETREJEUPIANO_H
#define FENETREJEUPIANO_H

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

class FenetreJeuPiano : public FenetreMiniJeu
{
private:

#define Menu 0
#define Jeu 1
#define Score 2
    Chronometre chrono;
    //Attribut
    Dieu chanson[200];
    char noteA[22]; // notes: indiqent si une note est présente ou non sur une rangée
    char noteS[22];
    char noteD[22];
    char noteF[22];

    bool matrice[40][4]; // matrice de l'ecran

    int noteReussi = 0;
    double bit;
    double bitCount = 0;
    // Methodes

    bool chargerChanson(bool matrice[40][4]);
    bool Temps(); // Gère le temps et l'appel des methodes
    void AffichageEcran(int mode); // affiche l'ecran et ses valeurs
    char GetNote(int btn, int ligne); // Renvoie les 4 tableaux de note
    void SetNote(int t); // prend la matrice et change les 4 tableaux de note
    

public:
    //Constructeurs & destructeurs
    FenetreJeuPiano(ES *thread);
    ~FenetreJeuPiano();

    //Getteurs & setteurs
    bool VersBoutonPressee(Dieu touche);

    //Méthodes
    void ouvrir();
};

#endif