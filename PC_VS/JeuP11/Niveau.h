/*====================================================================================================
Fichier: Niveau.h
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
#ifndef NIVEAU_H
#define NIVEAU_H

#include <iostream>
#include "CONSTANTES.h"

class Niveau
{
private:
    //Attributs
    int numero;
    int nb_pleins_variables;
    int nb_mj_dispo;
    bool mjx_faits[NB_MINI_JEUX];
    int nb_mj_finis;
    int v_adversaire; //TODO : à discuter. La vitesse de déplacement de l'adversaire de plus en plus vite à chaque niveau suivant ?

public:
    //Constructeurs & destructeurs
    Niveau();
    ~Niveau();

    //Getteurs & setteurs
    int getNumero();
    int getNb_PleinsVariables();
    int getNb_Mj_Dispo();
    //bool[] getNb_Mjx_Faits();
    int getNb_Mj_Finis();
    int getV_Adversaire();

    void setNumero(int);
    void setNb_PleinsVariables(int);
    void setNb_Mj_Dispo(int);
    void setNb_Mj_Finis(int);
    void setV_Adversaire(int);

    //Méthodes
    int getNB_Mj_Restants();
    void miniJeuReussi(int);
    int choixMiniJeu();

    bool niveauFinit();
    bool niveauSuivant();
};

#endif