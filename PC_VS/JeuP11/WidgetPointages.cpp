/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 18 mars 2023
Description: UI des pointages
====================================================================================================*/
#include "WidgetPointages.h"

WidgetPointages::WidgetPointages(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

	//Connextion
}

WidgetPointages::~WidgetPointages()
{}
