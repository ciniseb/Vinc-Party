/*====================================================================================================
Fichier: Tests.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 12 février 2023
Description: Tests unitaires et d'intégration
====================================================================================================*/
#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <thread>
#include "ES.h"
#include "Chronometre.h"
#include "FenetreJeu.h"
#include "FenetreJeuPiano.h"

class Tests
{
public:
    //Constructeurs & destructeurs
    Tests();
    ~Tests();

    //Méthodes
    void tests_chronometre();

    void tests_fenetrejeu();

    void tests_autre();

    void tests_FenetreJeuPiano();

};

#endif