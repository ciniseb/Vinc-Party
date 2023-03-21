/*====================================================================================================
Fichier: FenetrePointages.h
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
#ifndef FENETREPOINTAGES_H
#define FENETREPOINTAGES_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "ES.h"
#include "Fenetre.h"
#include "Pointage.h"
#include "Joystick.h"
#include "Bouton.h"
#include "ThreadMoteur.h"

class MoteurPointages : public Moteur
{
private:
    //Attributs
    std::vector<Pointage> pointages;
public:
    //Constructeurs & destructeurs
    MoteurPointages(ES* threadArduino = nullptr, ThreadMoteur* threadMoteur = nullptr);
    ~MoteurPointages();

    //Getteurs & setteurs
    std::vector<Pointage> getPointages();

    void setPointages(std::vector<Pointage>);
    void ajoutPointage(Pointage);

    //Méthodes
    bool chargerPointages();
    bool enregistrerPointages();

    void initialiser();
    void demarrer();

    void affichage(int);
};

#endif