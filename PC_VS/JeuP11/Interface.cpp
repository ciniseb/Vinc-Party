/*====================================================================================================
Fichier: FenetrePointages.h
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


#include "Interface.h"

Interface::Interface(ThreadMoteur *thread, QWidget *parent)
	: QStackedWidget(parent)
{

	ui.setupUi(this);
	

	threadMoteur = thread;

	widgetMenu = new WidgetMenu(threadMoteur, this);
	widgetJeu = new WidgetJeu(threadMoteur, this);
	widgetPointage = new WidgetPointage(threadMoteur, this);
	widgetPiano = new WidgetPiano(threadMoteur, this);
	widgetPeche = new WidgetPeche(threadMoteur, this);
	widgetMineur = new WidgetMineur(threadMoteur, this);

	addWidget(widgetMenu);
	addWidget(widgetJeu);
	addWidget(widgetPointage);
	addWidget(widgetPiano);
	addWidget(widgetPeche);
	addWidget(widgetMineur);


	connect(threadMoteur, SIGNAL(selecPointage()), this, SLOT(uiPointage()));
}	


Interface::~Interface()
{
	delete threadMoteur;
	delete widgetMenu;

}

void Interface::uiPointage()
{
	setCurrentWidget(widgetPointage);
}

void Interface::uiJeu()
{
	setCurrentWidget(widgetJeu);
}

void Interface::uiPiano()
{
	setCurrentWidget(widgetPiano);
}

void Interface::uiPeche()
{
	setCurrentWidget(widgetPeche);

}

void Interface::uiMineur()
{
	setCurrentWidget(widgetMineur);

}
