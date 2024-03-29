/*====================================================================================================
Fichier: FenetreMenu.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 05 f�vrier 2023
Description: 
====================================================================================================*/
#ifndef MOTEURMENU_H
#define MOTEURMENU_H

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Moteur.h"
#include "ES.h"
#include "MoteurJeu.h"
#include "MoteurPointages.h"
#include "MoteurTests.h"
#include "Joystick.h"
#include "Bouton.h"
#include "MoteurCR.h"
#include "ThreadMoteur.h"

class ThreadMoteur;
class MoteurMenu : public Moteur
{
private:
    //Attributs
    Moteur *moteurs[3];
    std::string nom_joueur;

public:
    //Constructeurs & destructeurs
    MoteurMenu(ES* threadArduino = nullptr, ThreadMoteur* threadMoteur = nullptr);
    ~MoteurMenu();

    //Getteurs & setteurs
    void setNomJoueur(std::string);

    //M�thodes
    void initialiser();
    void demarrer();

    void affichage(int);
};

#endif
