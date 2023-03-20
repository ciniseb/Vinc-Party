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
Chronometre::Chronometre() { etat = Etat::Inactif; }
Chronometre::~Chronometre() {}

//Getteurs & setteurs
double Chronometre::tempsEcoule_ms()
{
    if(etat == Etat::Actif)
    {
        t_actuel = std::chrono::steady_clock::now();
    }
    
    if(etat != Etat::Inactif)
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
    if (etat == Etat::Actif)
    {
        t_actuel = std::chrono::steady_clock::now();
    }

    if (etat != Etat::Inactif)
    {
        std::chrono::duration<double, std::ratio<1>> t_ecoule = t_actuel - t_depart;
        return t_ecoule.count();
    }
    else
    {
        return -1;
    }
}
double Chronometre::tempsEcoule_m()
{
    if (etat == Etat::Actif)
    {
        t_actuel = std::chrono::steady_clock::now();
    }

    if (etat != Etat::Inactif)
    {
        std::chrono::duration<double, std::ratio<60>> t_ecoule = t_actuel - t_depart;
        return t_ecoule.count();
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
    etat = Etat::Actif;
}
void Chronometre::pause()
{
    if (etat == Etat::Actif)
    {
        etat = Etat::Pause;
    }
}
void Chronometre::continuer()
{
    if (etat == Etat::Pause)
    {
        etat = Etat::Actif;
    }
}
void Chronometre::arreter()
{
    etat = Etat::Inactif;
}

bool Chronometre::tempsAtteint_ms(double ms)
{
    if (etat == Etat::Actif)
    {
        t_actuel = std::chrono::steady_clock::now();
    }

    if (etat != Etat::Inactif)
    {
        std::chrono::duration<double, std::milli> t_ecoule = t_actuel - t_depart;
        return ms < t_ecoule.count();
    }
    else
    {
        return false;
    }
}

//Opérateurs surchargés
std::ostream& operator<<(std::ostream& flux, Chronometre& c)
{
    double ms = c.tempsEcoule_ms();

    int h = ms / (1000 * 60 * 60);
    ms -= h * (1000 * 60 * 60);

    int m = ms / (1000 * 60);
    ms -= m * (1000 * 60);

    int s = ms / 1000;
    ms -= s * 1000;

    flux << std::setfill('0') << std::setw(2) << h << ':' << std::setw(2) << m << ':' << std::setw(2) << s;
    return flux;
}