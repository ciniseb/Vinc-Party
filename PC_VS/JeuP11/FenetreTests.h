/*====================================================================================================
Fichier: FenetreTests.h
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
#ifndef FENETRETESTS_H
#define FENETRETESTS_H

#include <iostream>
#include "ES.h"
#include "Fenetre.h"

class FenetreTests : public Fenetre
{
private:
    //Attributs


public:
    //Constructeurs & destructeurs
    FenetreTests(ES *);
    ~FenetreTests();

    //Getteurs & setteurs


    //Méthodes
    void ouvrir();
};

#endif