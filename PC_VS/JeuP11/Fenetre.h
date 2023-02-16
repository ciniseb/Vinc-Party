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

class Fenetre
{
protected:
    //Attributs
    ES *threadArduino;
    

public:
    //Constructeurs & destructeurs
    Fenetre();
    Fenetre(ES *);
    virtual ~Fenetre();

    //Getteurs & setteurs


    //Méthodes
    virtual void ouvrir() = 0;
};

#endif