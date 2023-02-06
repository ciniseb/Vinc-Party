/*====================================================================================================
Fichier: FenetrePointages.cpp
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
#include "FenetrePointages.h"

//Constructeurs & destructeurs
FenetrePointages::FenetrePointages()
{

}
FenetrePointages::~FenetrePointages() {}

//Getteurs & setteurs
std::vector<Pointage> FenetrePointages::getPointages()
{
    return pointages;
}

void FenetrePointages::setPointages(std::vector<Pointage> p)
{
    pointages = p;
}

//Méthodes