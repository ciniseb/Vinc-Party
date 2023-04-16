/*====================================================================================================
Fichier: Tests.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 12 f�vrier 2023
Description: Tests unitaires et d'int�gration
====================================================================================================*/
#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <thread>
#include "ES.h"
#include "Chronometre.h"
#include "MoteurJeu.h"
#include "MoteurJeuPiano.h"
#include "MoteurPointages.h"
#include "MoteurJeuPeche.h"
#include "MoteurJeuMineur.h"

class Tests
{
public:
    //Constructeurs & destructeurs
    Tests();
    ~Tests();

    //M�thodes
    void tests_chronometre();

    void tests_fenetrejeu();

    void tests_fenetrePointages();

    void tests_autre();

    void tests_FenetreJeuPiano();

    void tests_FenetreJeuPeche();
    void tests_FenetreJeuMineur();

};

#endif