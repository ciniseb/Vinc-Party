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
#include "bargraph.h"
#include "WidgetJeuPiano.h"

class MoteurJeuPiano : public MoteurMiniJeu
{
private:
    WidgetJeuPiano* widgetJeuPiano;

    Chronometre chrono;
    //Bouton* btn = Bouton();

    //Attribut
    Dieu chanson[200];
    char noteD[22]; // notes: indiqent si une note est présente ou non sur une rangée
    char noteI[22];
    char noteE[22];
    char noteU[22];

    bool matrice[50001][4]; // matrice de l'ecran
    int rangee_matrice;

    int noteReussi;
    double bit;
    double bitCount;
    // Methodes

    bool chargerChanson(bool matrice[50001][4]);
    bool temps(); // Gère le temps et l'appel des methodes
    void affichage(int mode); // affiche l'ecran et ses valeurs
    char GetNote(int btn, int ligne); // Renvoie les 4 tableaux de note
    void SetNote(int t); // prend la matrice et change les 4 tableaux de note
    char Dieu_en_char(Dieu dieu); // Convertie Dieu en char

public:
    //Constructeurs & destructeurs
    MoteurJeuPiano(ES* threadArduino = nullptr, ThreadMoteur* threadMoteur = nullptr);
    ~MoteurJeuPiano();

    //Getteurs & setteurs
    bool VersBoutonPressee(Dieu touche);

    //Méthodes
    void initialiser();
    void demarrer();
};

#endif