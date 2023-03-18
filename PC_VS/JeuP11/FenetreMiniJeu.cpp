/*====================================================================================================
Fichier: FenetreMiniJeu.cpp
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
#include "FenetreMiniJeu.h"

//Constructeurs & destructeurs
MoteurMiniJeu::MoteurMiniJeu(ES *thread) : Moteur(thread)
{
    reussite = false;
}
MoteurMiniJeu::~MoteurMiniJeu() {}

//Getteurs & setteurs


//Méthodes
//TODO : définir les méthodes communes aux mini-jeux ainsi que celles virtuelles pures.
bool MoteurMiniJeu::reussi()
{
    bool reponse = reussite;
    if (reussite)
    {
        !reussite;
    }

    return reponse;
}
