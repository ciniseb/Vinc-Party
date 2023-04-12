/*====================================================================================================
Fichier: ThreadMoteur.cpp
Auteurs: Antoine Allard
		 Charles Beaulieu
		 Émile Bois
		 Enes Caku
		 Zachari Gervais
		 Anne-Sophie Nguyen
		 Sébastien St-Denis
		 Date: 18 mars 2023
Description:
====================================================================================================*/
#include "ThreadMoteur.h"
#include "FenetreMenu.h"

ThreadMoteur::ThreadMoteur(ES* threadArduino, QObject *parent)
	: QThread(parent)
{
    this->threadArduino = threadArduino;
    this->moteur = new MoteurMenu(threadArduino, this);
}

ThreadMoteur::~ThreadMoteur()
{
    delete threadArduino;
    delete moteur;
}

void ThreadMoteur::run()
{
    moteur->demarrer();
}