/*====================================================================================================
Fichier: FenetreTests.h
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


    //M�thodes
    void ouvrir();
};

#endif