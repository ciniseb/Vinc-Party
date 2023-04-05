/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 18 mars 2023
Description: UI du mineur
====================================================================================================*/
#include "WidgetJeuMineur.h"

WidgetJeuMineur::WidgetJeuMineur(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
	threadMoteur = thread;

	//Connexions
}

WidgetJeuMineur::~WidgetJeuMineur()
{}
