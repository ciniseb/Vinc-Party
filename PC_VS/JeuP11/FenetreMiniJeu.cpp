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
FenetreMiniJeu::FenetreMiniJeu(ES *thread) : Fenetre(thread)
{
    reussite = false;
}
FenetreMiniJeu::~FenetreMiniJeu() {}

//Getteurs & setteurs


//Méthodes
//TODO : définir les méthodes communes aux mini-jeux ainsi que celles virtuelles pures.
bool FenetreMiniJeu::reussi()
{
    bool reponse = reussite;
    if (reussite)
    {
        !reussite;
    }

    return reponse;
}
