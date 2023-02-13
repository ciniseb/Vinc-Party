/*====================================================================================================
Fichier: Chronometre.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 12 février 2023
Description:
====================================================================================================*/
#include "Chronometre.h"

//Constructeurs & destructeurs
Chronometre::Chronometre() { actif = false; }
Chronometre::~Chronometre() {}

//Getteurs & setteurs
double Chronometre::tempsEcoule_ms()
{
    t_actuel = std::chrono::steady_clock::now();

    if(actif)
    {
        std::chrono::duration<double, std::milli> t_ecoule = t_actuel - t_depart;
        return t_ecoule.count();
    }
    else
    {
        return -1;
    }
}
double Chronometre::tempsEcoule_s()
{
    t_actuel = std::chrono::steady_clock::now();

    if(actif)
    {
        std::chrono::duration<double, std::ratio<1>> t_ecoule = t_actuel - t_depart;
        return round(t_ecoule.count());
    }
    else
    {
        return -1;
    }
}
double Chronometre::tempsEcoule_m()
{
    t_actuel = std::chrono::steady_clock::now();

    if(actif)
    {
        std::chrono::duration<double, std::ratio<60>> t_ecoule = t_actuel - t_depart;
        return round(t_ecoule.count());
    }
    else
    {
        return -1;
    }
}

//Méthodes
void Chronometre::demarrer()
{
    t_depart = std::chrono::steady_clock::now();
    actif = true;
}

bool Chronometre::tempsAtteint_ms(double ms)
{
    t_actuel = std::chrono::steady_clock::now();

    if(actif)
    {
        std::chrono::duration<double, std::milli> t_ecoule = t_actuel - t_depart;
        return ms < t_ecoule.count();
    }
    else
    {
        return false;
    }
}