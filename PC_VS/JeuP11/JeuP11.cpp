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
    FenetreMenu menu;

    menu.ouvrir();

    //Tests. � commenter au besoin
    //Tests tests;
    //tests.tests_chronometre();
    //tests.tests_fenetrejeu();
    // tests.tests_autre();
    ES es;
     while (true) {
         if (es.evenementDisponible()) {
             Evenement e = es.prochainEvenement();
             switch (e.arg1)
             {
             case HAUT: cout << "HAUT" << endl;
                 break;

             case BAS: cout << "BAS" << endl;
                 break;

             case GAUCHE: cout << "GAUCHE" << endl;
                 break;

             case DROITE: cout << "DROITE" << endl;
                 break;

             case ARRET: cout << "ARRET" << endl;
                 break;
             default:
                 break;
             }
         }

    }
    return 0;
}



/*---------------------------Definition de fonctions ------------------------*/

