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
Description: UI du mineur
====================================================================================================*/

#pragma once

#include <QWidget>
#include "ui_WidgetMineur.h"
#include "ThreadMoteur.h"

class WidgetMineur : public QWidget
{
	Q_OBJECT

public:
	WidgetMineur(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetMineur();

    ThreadMoteur* threadMoteur;

private:
	Ui::WidgetMineurClass ui;
};
