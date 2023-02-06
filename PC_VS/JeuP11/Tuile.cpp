/*====================================================================================================
Fichier: Tuile.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 02 février 2023
Description: 
====================================================================================================*/
#include "Tuile.h"
#include "CONSTANTES.h"

//Constructeurs & destructeurs
Tuile::Tuile()
{
    remplissage = PLEIN;
    chemin_image = "";
}
Tuile::~Tuile() {}

//Getteurs & setteurs
int Tuile::getRemplissage()
{
    return remplissage;
}
std::string Tuile::getCheminImage()
{
    return chemin_image;
}

void Tuile::setRemplissage(int r)
{
    remplissage = r;
}
void Tuile::setCheminImage(std::string c)
{
    chemin_image = c;
}

//Méthodes

