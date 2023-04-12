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
Description: 
====================================================================================================*/
#pragma once

#include <QStackedWidget>
#include "ThreadMoteur.h"
#include "WidgetMenu.h"
#include "WidgetJeu.h"
#include "WidgetJeuPiano.h"
#include "WidgetPointages.h"
#include "WidgetJeuMineur.h"
#include "WidgetJeuPeche.h"
#include <QInputDialog>

class Interface : public QStackedWidget
{
	Q_OBJECT

public:
	Interface(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~Interface();

private:
	ThreadMoteur* threadMoteur;

	WidgetMenu* widgetMenu;
	WidgetJeu* widgetJeu;
	WidgetPointages* widgetPointages;

	WidgetJeuPiano* widgetJeuPiano;
	WidgetJeuMineur* widgetJeuMineur;
	WidgetJeuPeche* widgetJeuPeche;
	WidgetRiviere* widgetRiviere;

	QInputDialog* inputDialog;

signals:
	void MAJ_NomJoueur(std::string);

public slots:
	void setWidgetActif(int);
};