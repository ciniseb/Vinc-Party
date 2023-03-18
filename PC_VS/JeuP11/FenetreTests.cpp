/*====================================================================================================
Fichier: FenetreTests.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: 
====================================================================================================*/
#include <iostream>
#include "ES.h"
#include "Fenetre.h"
#include "Chronometre.h"
#include "FenetreTests.h"
#include "Joystick.h"
#include "Bouton.h"
#include "Evenement.h"
#include "Accel.h"
#include "Bargraph.h"
#include "Vibration.h"
#include "Boussole.h"
#include "QuadBargraph.h"
#include "CONSTANTES.h"

//Constructeurs & destructeurs
MoteurTests::MoteurTests(ES *thread) : Moteur(thread) { initialiser(); }
MoteurTests::~MoteurTests() {}

//Getteurs & setteurs


//Méthodes
void MoteurTests::initialiser()
{
    //TODO
    remplirListe();
}

void MoteurTests::demarrer()
{
    std::unique_ptr<Evenement> evenement;
    temps.demarrer();
    dernierTemps = temps.tempsEcoule_ms();

    system("cls");
    std::cout << "DEMO OK" << std::endl;
    while (active)
    {
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();

            std::cout << evenement->getDesciption() << std::endl;
        }

        if (temps.tempsAtteint_ms(dernierTemps + 750)) {
            dernierTemps = dernierTemps + 750;
            threadArduino->envoyerEvenement(std::move(listeEvenements[compteur]));

            compteur++;
            if (compteur >= 15) {
                compteur = 0;
                remplirListe();
            } 
        }
    }
}

void MoteurTests::afficher()
{

}

void MoteurTests::remplirListe()
{
    listeEvenements[0] = std::make_unique<Boussole>(NORD);
    listeEvenements[1] = std::make_unique<Boussole>(SUD);
    listeEvenements[2] = std::make_unique<Boussole>(EST);
    listeEvenements[3] = std::make_unique<Boussole>(OUEST);
    listeEvenements[4] = std::make_unique<Boussole>(OFF);

    listeEvenements[5] = std::make_unique<Bargraph>(Dieu::D);
    listeEvenements[6] = std::make_unique<Bargraph>(Dieu::I);
    listeEvenements[7] = std::make_unique<Bargraph>(Dieu::E);
    listeEvenements[8] = std::make_unique<Bargraph>(Dieu::U);

    listeEvenements[9] = std::make_unique<Vibration>();

    listeEvenements[10] = std::make_unique<QuadBargraph>(0);
    listeEvenements[11] = std::make_unique<QuadBargraph>(2);
    listeEvenements[12] = std::make_unique<QuadBargraph>(8);
    listeEvenements[13] = std::make_unique<QuadBargraph>(5);
    listeEvenements[14] = std::make_unique<QuadBargraph>(10);
}