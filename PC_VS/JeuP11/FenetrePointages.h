/*====================================================================================================
Fichier: FenetrePointages.h
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
#ifndef FENETREPOINTAGES_H
#define FENETREPOINTAGES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "ES.h"
#include "Fenetre.h"
#include "Pointage.h"

class FenetrePointages : public Fenetre
{
private:
    //Attributs
    std::vector<Pointage> pointages;
public:
    //Constructeurs & destructeurs
    FenetrePointages(ES *);
    ~FenetrePointages();

    //Getteurs & setteurs
    std::vector<Pointage> getPointages();

    void setPointages(std::vector<Pointage>);
    void ajoutPointage(Pointage);

    //M�thodes
    bool chargerPointages();
    bool enregistrerPointages();

    void ouvrir();

    void affichage_DEBUG(int);
};

#endif