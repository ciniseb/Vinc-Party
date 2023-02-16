/*====================================================================================================
Fichier: Niveau.cpp
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
#include "niveau.h"

//Constructeurs & destructeurs
Niveau::Niveau()
{
    numero = 0;
    nb_mj_finis = 0;
    nb_pleins_variables = 0;
    nb_mj_dispo = 0;
    v_adversaire = 0;
}
Niveau::~Niveau() {}

//Getteurs & setteurs
int Niveau::getNumero()
{
    return numero;
}
int Niveau::getNb_PleinsVariables()
{
    return nb_pleins_variables;
}
int Niveau::getNb_Mj_Dispo()
{
    return nb_mj_dispo;
}
int Niveau::getNb_Mj_Finis()
{
    return nb_mj_finis;
}
int Niveau::getV_Adversaire()
{
    return v_adversaire;
}

void Niveau::setNumero(int n)
{
    numero = n;
}
void Niveau::setNb_PleinsVariables(int pv)
{
    nb_pleins_variables = pv;
}
void Niveau::setNb_Mj_Dispo(int mj)
{
    nb_mj_dispo = mj;
}
void Niveau::setNb_Mj_Finis(int mj)
{
    nb_mj_finis = mj;
}
void Niveau::setV_Adversaire(int v)
{
    v_adversaire = v;
}

//Méthodes
bool Niveau::niveauSuivant()
{
    nb_mj_finis = 0;
    switch (++numero)
    {
    case 1:
        nb_pleins_variables = 8;
        nb_mj_dispo = 2;
        v_adversaire = 1;
        break;
    case 2:
        nb_pleins_variables = 16;
        nb_mj_dispo = 3;
        v_adversaire = 1.2;
        break;
    case 3:
        nb_pleins_variables = 24;
        nb_mj_dispo = 3;
        v_adversaire = 1.4;
        break;
    case 4:
        nb_pleins_variables = 24;
        nb_mj_dispo = 4;
        v_adversaire = 1.8;
        break;
    case 5:
        nb_pleins_variables = 36;
        nb_mj_dispo = 4;
        v_adversaire = 1.8;
        break;
    case 6:
        nb_pleins_variables = 44;
        nb_mj_dispo = 5;
        v_adversaire = 2;
        break;
    default:
        numero--;
        return false; //Jeu terminé
        break;
    }
    return true;
}