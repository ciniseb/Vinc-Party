/*====================================================================================================
Fichier: FenetreTests.h
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
#ifndef FENETRETESTS_H
#define FENETRETESTS_H

#include <iostream>
#include "ES.h"
#include "Fenetre.h"
#include "Chronometre.h"
#include "Joystick.h"
#include "Bouton.h"
#include "Evenement.h"
#include "Accel.h"
#include "Bargraph.h"
#include "Vibration.h"
#include "Boussole.h"
#include "CONSTANTES.h"

class MoteurTests : public Moteur
{
private:
    //Attributs
    bool active = true;
    Chronometre temps;
    double dernierTemps = 0;
    int compteur = 0;
    std::unique_ptr<Evenement> listeEvenements[15];

public:
    //Constructeurs & destructeurs
    MoteurTests(ES *);
    ~MoteurTests();

    //Getteurs & setteurs


    //Méthodes
    void initialiser();
    void demarrer();

    void afficher();
    void remplirListe();

};

#endif