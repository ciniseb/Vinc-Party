// JeuP11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>
/*-------------------------- Librairies externes ----------------------------*/
#include "FenetreMenu.h"
#include "Tests.h"
#include "Evenement.h"
#include "Bouton.h"
#include "Joystick.h"
#include "Accel.h"
#include "Bargraph.h"
#include "Vibration.h"
#include "Boussole.h"
#include "CONSTANTES.h"

/*------------------------------ Constantes ---------------------------------*/








/*------------------------- Prototypes de fonctions -------------------------*/



#include "FenetreJeuPiano.h"
#include <conio.h>
#include <cstdlib>
/*---------------------------- Variables globales ---------------------------*/

/*----------------------------- Fonction "Main" -----------------------------*/
int main()
{
    ES es;
    es.demarrer();
    FenetreMenu menu(&es);

    menu.ouvrir();
    //FenetreMiniJeu *fenetreJeuPiano = new FenetreJeuPiano();
    //fenetreJeuPiano->ouvrir();


    //Tests. � commenter au besoin
    //Tests tests;
    //tests.tests_chronometre();
    //tests.tests_fenetrejeu();
    // tests.tests_autre();
    /*es.demarrer();
    while (true) {
        while (es.evenementDisponible()) {
            std::unique_ptr<Evenement> e = es.prochainEvenement();
            if (e->getCode() == BOUTON) {
                Dieu nom = static_cast<Bouton*>(e.get())->getNom();
                es.envoyerEvenement(std::make_unique<Bargraph>(nom));
                switch (nom)
                {
                case Dieu::D: cout << "D" << endl;
                    
                    break;
                case Dieu::I: cout << "I" << endl;
                    break;
                case Dieu::E: cout << "E" << endl;
                    break;
                case Dieu::U: cout << "U" << endl;
                    break;
                default:
                    break;
                }
                
            }
            if (e->getCode() == JOYSTICK) {
                Direction direction = static_cast<Joystick*>(e.get())->getDirection();
                switch (direction)
                {
                case HAUT: cout << "HAUT" << endl;

                    break;
                case BAS: cout << "BAS" << endl;
                    break;
                case GAUCHE: cout << "GAUCHE" << endl;
                    break;
                case DROITE: cout << "DROITE" << endl;
                    break;
                default:
                    break;
                }
            }

        }

        es.envoyerEvenement(std::make_unique<Boussole>(NORD));
        Sleep(1000);
        es.envoyerEvenement(std::make_unique<Boussole>(SUD));
        Sleep(1000);
        es.envoyerEvenement(std::make_unique<Boussole>(EST));
        Sleep(1000);
        es.envoyerEvenement(std::make_unique<Boussole>(OUEST));
        Sleep(1000);


        es.envoyerEvenement(std::make_unique<Vibration>());
        Sleep(1000);
        
    }*/
    return 0;
}



/*---------------------------Definition de fonctions ------------------------*/

