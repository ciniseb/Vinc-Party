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
#include <vector>
#include <map>
#include <random>
#include "HasardMuons.h"

//Constructeurs & destructeurs
Niveau::Niveau()
{
    numero = 0;
    nb_mj_finis = 0;
    nb_pleins_variables = 0;
    nb_mj_dispo = 0;
    for (int i = 0; i < NB_MINI_JEUX; i++)
    {
        mjx_faits[i] = false;
    }
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
int Niveau::getNB_Mj_Restants()
{
    return (nb_mj_dispo - nb_mj_finis);
}
void Niveau::miniJeuReussi(int mj)
{
    mjx_faits[mj] = true;
    nb_mj_finis++;
}
int Niveau::choixMiniJeu()
{
    std::vector<int> index_mjx;

    for (int i = 0; i < NB_MINI_JEUX; i++)
    {
        if (!mjx_faits[i])
        {
            index_mjx.push_back(i);
        }
    }
    //std::cout << std::endl << "nb mjx : " << index_mjx.size() << std::endl;

    if (index_mjx.empty())
    {
        int nb = -1;
        if (MODE_CLAVIER)
        {
            srand(time(NULL));
            nb = (rand() % (NB_MINI_JEUX - 1));
        }
        else
        {
            nb = (HasardMuons::valeurAleatoire() % (NB_MINI_JEUX - 1));
        }
        //std::cout << std::endl << "mj choisi : " << nb << std::endl;
        return nb;
    }

    std::mt19937 g;
    if (MODE_CLAVIER)
    {
        std::random_device rd;
        g = std::mt19937(rd());
    }
    else
    {
        g = std::mt19937(HasardMuons::valeurAleatoire());
    }
    std::shuffle(index_mjx.begin(), index_mjx.end(), g);

    //std::cout << std::endl << "mj choisi : " << index_mjx[0] << std::endl;

    return index_mjx[0];
    //return 0;
}

bool Niveau::niveauFinit()
{
    if (nb_mj_finis == nb_mj_dispo)
    {
        return true;
    }
    return false;
}
bool Niveau::niveauSuivant()
{
    for (int i = 0; i < NB_MINI_JEUX; i++)
    {
        mjx_faits[i] = false;
    }

    nb_mj_finis = 0;
    switch (++numero)
    {
    case 1:
        nb_pleins_variables = 45;
        nb_mj_dispo = 1;
        v_adversaire = 1;
        break;
    case 2:
        nb_pleins_variables = 70;
        nb_mj_dispo = 2;
        v_adversaire = 1.0666;
        break;
    case 3:
        nb_pleins_variables = 95;
        nb_mj_dispo = 3;
        v_adversaire = 1.1333;
        break;
    case 4:
        nb_pleins_variables = 120;
        nb_mj_dispo = 4;
        v_adversaire = 1.2;
        break;
    default:
        numero--;
        return false; //Jeu terminé
        break;
    }
    return true;
}