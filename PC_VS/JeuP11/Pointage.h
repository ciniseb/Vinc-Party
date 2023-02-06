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
    std::string getNomJoueur();
    int getN_Atteint();
    double getTemps();
    float getMoy_t_n();

    void setNomJoueur(std::string);
    void setN_Atteint(int);
    void setTemps(double);
    void setMoy_t_n(float);

    //Méthodes
    
};
