// JeuP11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
 * Auteurs: Jean-Samuel Lauzon
 * Date: Fevrier 2022
 * Modif : Janvier 2023, Compatible VisualStudio, JpGouin
*/

/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>
/*-------------------------- Librairies externes ----------------------------*/
#include "FenetreMenu.h"
#include "Tests.h"
/*---------------------------- Variables globales ---------------------------*/

/*----------------------------- Fonction "Main" -----------------------------*/
int main()
{
    //ES threadArduino;
    FenetreMenu menu;

    menu.ouvrir();

    //Tests. � commenter au besoin
    //Tests tests;
    //tests.tests_chronometre();
    //tests.tests_fenetrejeu();
    //tests.tests_autre();
    tests.tests_FenetreJeuPiano();
    
    return 0;
}



/*---------------------------Definition de fonctions ------------------------*/

