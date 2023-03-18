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
Description: UI des pointages
====================================================================================================*/
#include "WidgetPointage.h"

WidgetPointage::WidgetPointage(ThreadMoteur* thread, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    threadMoteur = thread;

	//Connextion
}

WidgetPointage::~WidgetPointage()
{}
