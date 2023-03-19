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
Description: UI de peche
====================================================================================================*/


#include "WidgetPeche.h"

WidgetPeche::WidgetPeche(ThreadMoteur* thread, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    threadMoteur = thread;

    //Connexions
}

WidgetPeche::~WidgetPeche()
{}
