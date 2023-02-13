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
#include "Chronometre.h"
#include "FenetreJeu.h"

class Tests
{
public:
    //Constructeurs & destructeurs
    Tests();
    ~Tests();

    //M�thodes
    void tests_chronometre();

    void tests_fenetrejeu();

    void tests_autre();

};

#endif