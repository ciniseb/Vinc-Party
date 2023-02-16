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

#include"ES.h"
#include "Tests.h"
#include "Evenement.h"
#include "Bouton.h"
#include "Joystick.h"
#include "Accel.h"


/*------------------------------ Constantes ---------------------------------*/








/*------------------------- Prototypes de fonctions -------------------------*/



/*---------------------------- Variables globales ---------------------------*/
//ES es;




/*----------------------------- Fonction "Main" -----------------------------*/
int main() {


    // Structure de donnees JSON pour envoie et reception



    //Tests. � commenter au besoin
    Tests tests;
    //tests.tests_chronometre();
    tests.tests_fenetrejeu();
    // tests.tests_autre();
    ES es;
    es.demarrer();
    while (true) {
        while (es.evenementDisponible()) {
            std::unique_ptr<Evenement> e = es.prochainEvenement();
            if (e->getCode() == BOUTON) {
                NomBouton nom = static_cast<Bouton*>(e.get())->getNom();
                switch (nom)
                {
                case D: cout << "D" << endl;
                    break;
                case I: cout << "I" << endl;
                    break;
                case E: cout << "E" << endl;
                    break;
                case U: cout << "U" << endl;
                    break;
                default:
                    break;
                }
            }

        }
        
    }
    return 0;
}



/*---------------------------Definition de fonctions ------------------------*/

