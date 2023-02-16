/*====================================================================================================
Fichier: FenetreJeuPiano.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: Mini-jeu de piano style Piano tiles
====================================================================================================*/
#ifndef FENETREJEUPIANO_H
#define FENETREJEUPIANO_H

#include <iostream>
#include <chrono>
#include "ES.h"
#include "FenetreMiniJeu.h"

class FenetreJeuPiano : public FenetreMiniJeu
{
private:
    //Attribut
    char chanson[200];
    int index = 0;
    

public:
    //Constructeurs & destructeurs
    FenetreJeuPiano();
    ~FenetreJeuPiano();

    //Getteurs & setteurs
    bool VersBoutonPressee(char c);

    //Méthodes
    void ouvrir();
};

#endif