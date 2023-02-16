/*====================================================================================================
Fichier: FenetreJeuX.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: FenetreJeuX est un nom temporaire pour expliquer la Classe de la fenêtre d'un mini-jeu
====================================================================================================*/
#ifndef FENETREJEUPIANO_H
#define FENETREJEUPIANO_H

#include <iostream>
#include <windows.h>
#include <dos.h>

#include "Chronometre.h"
#include "MiniJeu.h"
#include "Fenetre.h"

class FenetreJeuPiano : public MiniJeu, public Fenetre
{
private:
    Chronometre chrono;

#define A 0
#define S 1
#define D 2
#define F 3

#define Menu 0
#define Jeu 1
#define Score 2

    //Attributs
    char noteA[22]; // notes: indiqent si une note est présente ou non sur une rangée
    char noteS[22];
    char noteD[22];
    char noteF[22];
    //                      A  S  D  F
    bool matrice[40][4] = { 0, 0, 0, 0, // matrice des notes et le temps de leur entrée sur l'ecran en seconde
                            1, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 1,
                            0, 0, 1, 0,
                            0, 1, 0, 0,
                            1, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 1,
                            0, 0, 1, 0,
                            0, 1, 0, 0,
                            1, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 1,
                            1, 1, 1, 1,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0, };

    // Methodes

    bool Temps(); // Gère le temps et l'appel des methodes
    void AffichageEcran(int mode); // affiche l'ecran et ses valeurs
    char GetNote(int btn, int ligne); // Renvoie les 4 tableaux de note
    void SetNote(int t); // prend la matrice et change les 4 tableaux de note

public:
    //Constructeurs & destructeurs
    FenetreJeuPiano();
    ~FenetreJeuPiano();

    //Getteurs & setteurs


    //Méthodes
    void ouvrir();
};

#endif