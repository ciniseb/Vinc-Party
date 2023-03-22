/*====================================================================================================
Fichier: Fenetre.cpp
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
#include "Fenetre.h"

//Constructeurs & destructeurs
Fenetre::Fenetre()
{
    threadArduino = nullptr;
}
Fenetre::Fenetre(ES *thread)
{
    threadArduino = thread;
}
Fenetre::~Fenetre() {}

//Getteurs & setteurs


//Méthodes
