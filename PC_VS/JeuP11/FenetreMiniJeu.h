/*====================================================================================================
Fichier: FenetreMiniJeu.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: Classe abstraite pour chaque classe d'un mini-jeu spécifique
====================================================================================================*/
#ifndef FENETREMINIJEU_H
#define FENETREMINIJEU_H

#include <iostream>
#include "Fenetre.h"

class FenetreMiniJeu : public Fenetre
{
protected:
    //Attributs
    bool reussite;

public:
    //Constructeurs & destructeurs
    FenetreMiniJeu(ES *);
    ~FenetreMiniJeu();

    //Getteurs & setteurs


    //Méthodes
    //TODO : définir les méthodes communes aux mini-jeux ainsi que celles virtuelles pures.
    virtual void ouvrir() = 0;
    bool reussi();
};

#endif