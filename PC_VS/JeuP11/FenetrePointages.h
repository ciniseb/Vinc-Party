/*====================================================================================================
Fichier: FenetrePointages.h
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
#include <iostream>
#include <vector>
#include "Fenetre.h"
#include "Pointage.h"

class FenetrePointages : public Fenetre
{
private:
    //Attributs
    std::vector<Pointage> pointages;

public:
    //Constructeurs & destructeurs
    FenetrePointages();
    ~FenetrePointages();

    //Getteurs & setteurs
    std::vector<Pointage> getPointages();

    void setPointages(std::vector<Pointage>);

    //Méthodes

};