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
#ifndef FENETRE_TEST_H
#define FENETRE_TEST_H

#include <iostream>
#include "ES.h"

class Fenetre_test
{
protected:
    //Attributs
    ES *threadArduino;
    
public:
    //Constructeurs & destructeurs
    Fenetre_test(ES* threadArduino = nullptr);
    virtual ~Fenetre_test();

    //Getteurs & setteurs


    //Méthodes
    virtual void ouvrir() = 0;
    virtual void initialiser() = 0;
};

#endif