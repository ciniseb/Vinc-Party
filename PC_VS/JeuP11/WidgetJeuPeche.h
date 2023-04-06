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
#include "ThreadMoteur.h"
#include <QImage>
#include <QPainter>
class WidgetJeuPeche : public QWidget
{
	Q_OBJECT

public:
	WidgetJeuPeche(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeuPeche();

    ThreadMoteur* threadMoteur;

private:
    //Attributs
    QImage* Riviere1;
    QImage* Riviere2;
};
