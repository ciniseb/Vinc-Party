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
#include "ThreadMoteur.h"
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>

class WidgetMenu : public QWidget
{
    Q_OBJECT

public:
    WidgetMenu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
    ~WidgetMenu();

    ThreadMoteur* threadMoteur;

private:
    //Attributs
    QGridLayout *layout_principal;
    QVBoxLayout *layout_boutons;

    QPushButton *bouton_jouer;
    QPushButton *bouton_pointages;
    QPushButton *bouton_quitter;

public slots:
    void selection(int);

signals:


};

