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
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QGraphicsView>
#include <QtSvg>
#include <QSvgWidget>

class WidgetJeu : public QWidget
{
	Q_OBJECT

public:
	WidgetJeu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeu();

	ThreadMoteur* threadMoteur;

private:
    //Attributs
    QGridLayout *layout_principal;
    QHBoxLayout *layout_informations;

    //
    QLabel *nom_joueur;

    QSvgWidget *svg_distance;
    QLabel *distance;

    QSvgWidget *svg_temps;
    QLabel *temps;

    //
    QLabel *niveau;

    QLabel *mjx;
    QSvgWidget *svg_mjx;


    QSvgWidget *tuiles[HAUTEUR_CARTE][LARGEUR_CARTE];
};

/*QGraphicsView *view = new QGraphicsView(this);
QGraphicsScene *scene = new QGraphicsScene(this);

QGraphicsSvgItem *svgItem = new QGraphicsSvgItem(":/images/image.svg");*/