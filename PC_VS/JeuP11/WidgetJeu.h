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
Description: UI du jeu
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ThreadMoteur.h"
#include "WidgetCarte.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QGraphicsView>
#include <QtSvg>
#include <QSvgWidget>
#include <QString>

class WidgetJeu : public QWidget
{
	Q_OBJECT

public:
	WidgetJeu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeu();

	ThreadMoteur* threadMoteur;

private:
    //Attributs
    QVBoxLayout *layout_principal;


    QWidget* widget_informations;
    QHBoxLayout* layout_informations;
    //
    QLabel* nom_joueur;

    QSvgWidget* svg_distance;
    QLabel* distance;

    QSvgWidget* svg_temps;
    QLabel* temps;

    //
    QLabel* niveau;

    QLabel* mjx;
    QSvgWidget* svg_mjx;


    WidgetCarte* widgetCarte;
};