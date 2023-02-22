/*====================================================================================================
Fichier: Pointage.cpp
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
#include "Pointage.h"

//Constructeurs & destructeurs
Pointage::Pointage()
{
    nom_joueur = "";
    n_atteint = 0;
    temps = 0;
    moy_t_n = 0;
}
Pointage::Pointage(std::string nom, int niveau, double t, int nb)
{
    nom_joueur = nom;
    n_atteint = niveau;
    temps = t;
    moy_t_n = temps/niveau;
    nb_tuiles_parcourues = nb;
}
Pointage::~Pointage() {}

//Getteurs & setteurs
std::string Pointage::getNomJoueur() const
{
    return nom_joueur;
}
int Pointage::getN_Atteint() const
{
    return n_atteint;
}
double Pointage::getTemps() const
{
    return temps;
}
float Pointage::getMoy_t_n() const
{
    return moy_t_n;
}
int Pointage::getNb_tuiles_parcourues() const
{
    return nb_tuiles_parcourues;
}

void Pointage::setNomJoueur(std::string n)
{
    nom_joueur = n;
}
void Pointage::setN_Atteint(int n)
{
    n_atteint = n;
}
void Pointage::setTemps(double t)
{
    temps = t;
}
void Pointage::setMoy_t_n(float m)
{
    moy_t_n = m;
}
void Pointage::setNb_tuiles_parcourues(int nb)
{
    nb_tuiles_parcourues = nb;
}

//Méthodes
bool Pointage::enregistrerPointage()
{
    std::ofstream fichier;

    fichier.open("pointages.txt", std::fstream::app);

    if (fichier.is_open())
    {
        fichier << nom_joueur << ";" << n_atteint << ";" << temps << ";" << nb_tuiles_parcourues << std::endl;

        fichier.close();
        return true;
    }
    std::cout << "Fichier introuvable..." << std::endl;
    return false;
}