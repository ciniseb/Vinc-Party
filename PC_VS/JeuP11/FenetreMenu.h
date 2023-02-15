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

class FenetreMenu : public Fenetre
{
private:
    //Attributs
    ES threadArduino;
    Fenetre *fenetres[3];

public:
    //Constructeurs & destructeurs
    FenetreMenu();
    ~FenetreMenu();

    //Getteurs & setteurs


    //Méthodes
    void ouvrir();

    void affichage_DEBUG(int);
};

#endif