/*====================================================================================================
Fichier: Pointage.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: Le pointage d'un joueur x.
====================================================================================================*/
#ifndef POINTAGE_H
#define POINTAGE_H

#include <iostream>

class Pointage
{
private:
    //Attributs
    std::string nom_joueur;
    int n_atteint;
    double temps;
    float moy_t_n;
    //int distance_parcourue; //TODO : À ajouter ?

public:
    //Constructeurs & destructeurs
    Pointage();
    Pointage(std::string, int, double);
    ~Pointage();

    //Getteurs & setteurs
    std::string getNomJoueur() const;
    int getN_Atteint() const;
    double getTemps() const;
    float getMoy_t_n() const;

    void setNomJoueur(std::string);
    void setN_Atteint(int);
    void setTemps(double);
    void setMoy_t_n(float);

    //Méthodes
    
};

#endif