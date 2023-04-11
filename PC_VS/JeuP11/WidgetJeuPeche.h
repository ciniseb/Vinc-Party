/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 18 mars 2023
Description: UI de peche
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ThreadMoteur.h"
#include <QImage>
#include <QPainter>
#include <QProgressBar>
#include <QVBoxLayout>
#include "WidgetRiviere.h"

class WidgetJeuPeche : public QWidget
{
	Q_OBJECT

public:
	WidgetJeuPeche(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeuPeche();

    ThreadMoteur* threadMoteur;

private:
    //Attributs

    QProgressBar* progressBar;

    WidgetRiviere* riviere;

    QWidget* widget;
    
    QVBoxLayout* layout;


};
