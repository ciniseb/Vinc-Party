/*====================================================================================================
Fichier: FenetrePointages.h
Auteurs: Antoine Allard
		 Charles Beaulieu
		 �mile Bois
		 Enes Caku
		 Zachari Gervais
		 Anne-Sophie Nguyen
		 S�bastien St-Denis
		 Date: 18 mars 2023
Description:
====================================================================================================*/
#include "Interface.h"

Interface::Interface(ThreadMoteur *thread, QWidget *parent) : QStackedWidget(parent)
{	
	threadMoteur = thread;

	widgetMenu = new WidgetMenu(threadMoteur, this);
	widgetJeu = new WidgetJeu(threadMoteur, this);
	widgetPointages = new WidgetPointages(threadMoteur, this);
	widgetJeuPiano = new WidgetJeuPiano(threadMoteur, this);
	widgetJeuPeche = new WidgetJeuPeche(threadMoteur, this);
	widgetJeuMineur = new WidgetJeuMineur(threadMoteur, this);

	addWidget(widgetMenu);
	addWidget(widgetJeu);
	addWidget(widgetPointages); //temp
	//addWidget(widgetPointages);
	addWidget(widgetJeuPiano);
	addWidget(widgetJeuPeche);
	addWidget(widgetJeuMineur);

	//Connexions
	connect(threadMoteur, SIGNAL(changementWidgetActif(int)), this, SLOT(setWidgetActif(int)));
	connect(this, SIGNAL(MAJ_NomJoueur(std::string)), threadMoteur, SLOT(nomJoueur(std::string)));
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
	if (currentIndex() == 0 && index == 1)
	{
		bool ok = false;

		QString nom = QInputDialog::getText(this, "Joueur", "Quel est votre pseudonyme ?", QLineEdit::Normal, QString(), &ok);

		if (ok && nom.isEmpty())
		{
			nom = "PeuplierBlanc";
		}
		else if (!ok)
		{
			exit(1);
		}
		emit MAJ_NomJoueur(nom.toStdString());
	}
	setCurrentIndex(index);
}