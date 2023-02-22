/*====================================================================================================
Fichier: Acteur.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 02 février 2023
Description: Struct pour Joueur et Adversaire
====================================================================================================*/
#ifndef ACTEUR_H
#define ACTEUR_H

#include <iostream>
#include "Coordonnee.h"

struct Acteur
{
    std::string nom = "";
    Coordonnee position;
    double t_dernier_deplacement = 0;
    int nb_tuiles_parcourues = 0;
};

#endif