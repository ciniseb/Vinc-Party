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
#ifndef FENETREJEUPIANO_H
#define FENETREJEUPIANO_H

#include <iostream>
#include <chrono>
#include "ES.h"
#include "MiniJeu.h"
#include "Fenetre.h"
//using namespace std::chrono;
//milliseconds mil(1000);


class FenetreJeuPiano : public MiniJeu, public Fenetre
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