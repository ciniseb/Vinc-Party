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
Description: UI du piano
====================================================================================================*/


#pragma once

#include <QWidget>
#include "ui_WidgetPiano.h"
#include "ThreadMoteur.h"

class WidgetPiano : public QWidget
{
	Q_OBJECT

public:
	WidgetPiano(ThreadMoteur* thread = nullptr, QWidget *parent = nullptr);
	~WidgetPiano();

	ThreadMoteur* threadMoteur;

private:
	Ui::WidgetPianoClass ui;
};
