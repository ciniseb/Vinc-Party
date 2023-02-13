/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 12 février 2023
Description: Chronomètre qui gère le temps d'une partie
====================================================================================================*/
#ifndef CHRONOMETRE_H
#define CHRONOMETRE_H

#include <iostream>
#include <chrono>
#include <cmath>

class Chronometre
{
private:
    //Attributs
    std::chrono::time_point<std::chrono::steady_clock> t_depart;
    std::chrono::time_point<std::chrono::steady_clock> t_actuel;
    bool actif;

public:
    //Constructeurs & destructeurs
    Chronometre();
    ~Chronometre();

    //Getteurs & setteurs
    double tempsEcoule_ms();
    double tempsEcoule_s();
    double tempsEcoule_m();

    //Méthodes
    void demarrer();

    bool tempsAtteint_ms(double ms);
};

#endif