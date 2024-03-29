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

#include "CONSTANTES.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

class Chronometre
{
private:
    //Attributs
    std::chrono::time_point<std::chrono::steady_clock> t_depart;
    std::chrono::time_point<std::chrono::steady_clock> t_actuel;
    Etat etat;

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
    void pause();
    void continuer();
    void arreter();

    bool tempsAtteint_ms(double);

    //Op�rateurs surcharg�s
    friend std::ostream& operator<<(std::ostream &, Chronometre &);
};

#endif