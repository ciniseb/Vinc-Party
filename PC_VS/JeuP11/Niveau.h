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

class Niveau
{
private:
    //Attributs
    int numero;
    int nb_pleins_variables;
    int nb_mj_dispo;
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
    int getNb_Mj_Finis();
    int getV_Adversaire();

    void setNumero(int);
    void setNb_PleinsVariables(int);
    void setNb_Mj_Dispo(int);
    void setNb_Mj_Finis(int);
    void setV_Adversaire(int);

    //Méthodes
    bool niveauSuivant();
};

#endif