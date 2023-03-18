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
Description: UI des pointages
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ui_WidgetPointage.h"
#include "ThreadMoteur.h"


class WidgetPointage : public QWidget
{
	Q_OBJECT

public:
	WidgetPointage(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetPointage();

    ThreadMoteur* threadMoteur;

private:
	Ui::WidgetPointageClass ui;
signals:
    void selecPointage();
};
