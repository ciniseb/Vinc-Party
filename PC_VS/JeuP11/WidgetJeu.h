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
#include <QImage>
#include <QFrame>
#include <QPalette>

class WidgetJeu : public QWidget
{
	Q_OBJECT

public:
	WidgetJeu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeu();

private:
    //Attributs
    ThreadMoteur* threadMoteur;

    QVBoxLayout *layout_principal;


    QWidget* widget_informations;
    QHBoxLayout* layout_informations;
    //
    QLabel* nom_joueur;

    QLabel* image_distance;
    QLabel* distance;

    QLabel* image_temps;
    QLabel* temps;

    //
    QLabel* niveau;

    QLabel* mjx;
    QLabel* image_mjx;


    WidgetCarte* widgetCarte;

    //Méthodes
    QFrame* ligneVerticale();

public slots:
    void MAJ_Informations(std::string, int, std::string, int, int);
    void MAJ_Temps(std::string);
    void MAJ_Distance(int);
    void MAJ_MiniJeux(int);
};