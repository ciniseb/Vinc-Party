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
#include "ui_Interface.h"
#include "ThreadMoteur.h"
#include "WidgetMenu.h"
#include "WidgetJeu.h"
#include "WidgetJeuPiano.h"
#include "WidgetPointages.h"
#include "WidgetJeuMineur.h"
#include "WidgetJeuPeche.h"

class Interface : public QStackedWidget
{
	Q_OBJECT

public:
	Interface(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~Interface();

public slots:
	void setWidgetActif(int);

private:
	Ui::InterfaceClass ui;

	ThreadMoteur* threadMoteur;

	WidgetMenu* widgetMenu;
	WidgetJeu* widgetJeu;
	WidgetPointages* widgetPointages;

	WidgetJeuPiano* widgetJeuPiano;
	WidgetJeuMineur* widgetJeuMineur;
	WidgetJeuPeche* widgetJeuPeche;

 
};