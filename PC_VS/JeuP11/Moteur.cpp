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
#include "Moteur.h"

//Constructeurs & destructeurs
Moteur::Moteur(ES* threadArduino, ThreadMoteur* threadMoteur)
{
    this->threadArduino = threadArduino;
    this->threadMoteur = threadMoteur;
}
Moteur::~Moteur()
{
    delete threadArduino;
    delete threadMoteur;
}

//Getteurs & setteurs


//Méthodes
