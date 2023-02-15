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
    // tests.tests_autre();
    /*ES es;
     while (true) {
         if (es.evenementDisponible()) {
             Evenement e = es.prochainEvenement();
             switch (e.arg1)
             {
             case HAUT: std::cout << "HAUT" << std::endl;
                 break;

             case BAS: std::cout << "BAS" << std::endl;
                 break;

             case GAUCHE: std::cout << "GAUCHE" << std::endl;
                 break;

             case DROITE: std::cout << "DROITE" << std::endl;
                 break;

             case ARRET: std::cout << "ARRET" << std::endl;
                 break;
             default:
                 break;
             }
         }

    }*/
    return 0;
}



/*---------------------------Definition de fonctions ------------------------*/

