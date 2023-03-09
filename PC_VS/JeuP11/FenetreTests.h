/*====================================================================================================
Fichier: FenetreTests.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 05 f�vrier 2023
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

class FenetreTests : public Fenetre
{
private:
    //Attributs
    bool active = true;
    Chronometre temps;
    double dernierTemps = 0;
    int compteur = 0;
    std::unique_ptr<Evenement> listeEvenements[10];

public:
    //Constructeurs & destructeurs
    FenetreTests(ES *);
    ~FenetreTests();

    //Getteurs & setteurs


    //M�thodes
    void initialiser();
    void ouvrir();

    void afficher();
    void remplirListe();

};

#endif