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
Description: UI de peche
====================================================================================================*/


#pragma once

#include <QWidget>
#include "ui_WidgetPeche.h"
#include "ThreadMoteur.h"


class WidgetPeche : public QWidget
{
	Q_OBJECT

public:
	WidgetPeche(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetPeche();

    ThreadMoteur* threadMoteur;

private:
	Ui::WidgetPecheClass ui;
};
