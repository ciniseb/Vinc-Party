/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 12 f�vrier 2023
Description: Chronom�tre qui g�re le temps d'une partie
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

    //M�thodes
    void demarrer();

    bool tempsAtteint_ms(double ms);
};

#endif