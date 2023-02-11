/*====================================================================================================
Fichier: FenetreJeuX.cpp
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
#include "FenetreJeuPiano.h"

//Constructeurs & destructeurs
FenetreJeuPiano::FenetreJeuPiano()
{

}
FenetreJeuPiano::~FenetreJeuPiano() {

}

//Getteurs & setteurs
bool FenetreJeuPiano::VersBoutonPressee()
{
if(DigitalRead(chanson[index]) == true && timer quelquechose)
{
    return true;
}
else
{
    return false;
}

}

//Méthodes
