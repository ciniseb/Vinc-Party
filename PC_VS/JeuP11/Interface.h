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
#include "WidgetPiano.h"
#include "WidgetPointage.h"


class Interface : public QStackedWidget
{
	Q_OBJECT

public:
	Interface(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~Interface();


private slots:
	void uiPointage();
	void uiJeu();
	void uiPiano();

private:
	Ui::InterfaceClass ui;

	ThreadMoteur* threadMoteur;

	WidgetMenu* widgetMenu;
	WidgetJeu* widgetJeu;
	WidgetPointage* widgetPointage;
	WidgetPiano* widgetPiano;

 
};