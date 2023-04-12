/*====================================================================================================
Fichier: Fenetre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: Classe abstraite pour l'UI des fenêtres.
====================================================================================================*/
#ifndef FENETRE_H
#define FENETRE_H

#include <iostream>
#include "ES.h"
#include "ThreadMoteur.h"

class Moteur
{
protected:
    //Attributs
    ES *threadArduino;
    ThreadMoteur* threadMoteur;
    
public:
    //Constructeurs & destructeurs
    Moteur(ES* threadArduino = nullptr, ThreadMoteur* threadMoteur = nullptr);
    virtual ~Moteur();

    //Getteurs & setteurs


    //Méthodes
    virtual void demarrer() = 0;
    virtual void initialiser() = 0;
};

#endif