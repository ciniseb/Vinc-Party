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