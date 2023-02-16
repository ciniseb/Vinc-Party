/*====================================================================================================
Fichier: FenetreJeuX.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: FenetreJeuX est un nom temporaire pour expliquer la Classe de la fenêtre d'un mini-jeu
====================================================================================================*/
#ifndef FENETREJEUX_H
#define FENETREJEUX_H

#include <iostream>
#include "ES.h"
#include "FenetreMiniJeu.h"

class FenetreJeuX : public FenetreMiniJeu
{
private:
    //Attributs
    

public:
    //Constructeurs & destructeurs
    FenetreJeuX();
    ~FenetreJeuX();

    //Getteurs & setteurs


    //Méthodes
    void ouvrir();
};

#endif