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
	widgetPointages = new WidgetPointages(threadMoteur, this);
	widgetJeuPiano = new WidgetJeuPiano(threadMoteur, this);
	widgetJeuPeche = new WidgetJeuPeche(threadMoteur, this);
	widgetJeuMineur = new WidgetJeuMineur(threadMoteur, this);

	addWidget(widgetMenu);
	addWidget(widgetJeu);
	addWidget(widgetPointages);
	addWidget(widgetJeuPiano);
	addWidget(widgetJeuPeche);
	addWidget(widgetJeuMineur);

	//Connexions
	connect(threadMoteur, SIGNAL(changementWidgetActif(int)), this, SLOT(setWidgetActif(int)));
}	


Interface::~Interface()
{
	//Enes, ne pas oublier de delete les pointeurs. Peut causer un memory leak.
	delete threadMoteur;

	delete widgetMenu;
	delete widgetJeu;
	delete widgetPointages;
	delete widgetJeuPiano;
	delete widgetJeuPeche;
	delete widgetJeuMineur;
}

//Slots
void Interface::setWidgetActif(int index)
{
	setCurrentIndex(index);
}