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
Description: UI du piano
====================================================================================================*/


#include "WidgetPiano.h"

WidgetPiano::WidgetPiano(ThreadMoteur* thread, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    threadMoteur = thread;

    //Connexions
}

WidgetPiano::~WidgetPiano()
{}
