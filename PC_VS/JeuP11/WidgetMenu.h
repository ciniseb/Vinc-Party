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
Description: UI du menu
====================================================================================================*/
#pragma once

#include <QtWidgets/QWidget>
#include "ui_WidgetMenu.h"
#include "ThreadMoteur.h"

class WidgetMenu : public QWidget
{
    Q_OBJECT

public:
    WidgetMenu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
    ~WidgetMenu();

    ThreadMoteur* threadMoteur;

private:
    Ui::WidgetMenuClass ui;

public slots:
    void selection(int);

signals:


};

