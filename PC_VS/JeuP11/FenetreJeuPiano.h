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
#include <conio.h>
#include "ES.h"
#include "FenetreMiniJeu.h"
#include "CONSTANTES.h"

class FenetreJeuPiano : public FenetreMiniJeu
{
private:
    //Attribut
    Dieu chanson[200];
    int index = 0;
    

public:
    //Constructeurs & destructeurs
    FenetreJeuPiano(ES *);
    ~FenetreJeuPiano();

    //Getteurs & setteurs
    bool VersBoutonPressee(Dieu touche);

    //Méthodes
    void ouvrir();
};

#endif