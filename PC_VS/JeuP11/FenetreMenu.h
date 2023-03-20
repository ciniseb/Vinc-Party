/*====================================================================================================
Fichier: FenetreMenu.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: 
====================================================================================================*/
#ifndef FENETREMENU_H
#define FENETREMENU_H

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Fenetre.h"
#include "ES.h"
#include "FenetreJeu.h"
#include "FenetrePointages.h"
#include "FenetreTests.h"
#include "Joystick.h"
#include "Bouton.h"
#include "FenetreCR.h"
#include "ThreadMoteur.h"

class MoteurMenu : public Moteur
{
private:
    //Attributs
    Moteur *moteurs[3];

public:
    //Constructeurs & destructeurs
    MoteurMenu(ES* threadArduino = nullptr, ThreadMoteur* threadMoteur = nullptr);
    ~MoteurMenu();

    //Getteurs & setteurs


    //Méthodes
    void initialiser();
    void demarrer();

    void affichage(int);
};

#endif