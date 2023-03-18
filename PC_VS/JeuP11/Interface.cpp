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

	addWidget(widgetMenu);
	addWidget(widgetJeu);
	addWidget(widgetPointage);
	addWidget(widgetPiano);

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
