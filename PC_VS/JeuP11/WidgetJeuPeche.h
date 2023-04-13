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
#include <QProgressBar>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include "WidgetRiviere.h"

class WidgetJeuPeche : public QWidget
{
	Q_OBJECT

public:
	WidgetJeuPeche(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeuPeche();

private:
    //Attributs
    ThreadMoteur* threadMoteur;

    QProgressBar* progressBar;

    WidgetRiviere* riviere;

    QWidget* widget;

    QWidget* widget2;
    
    QVBoxLayout* layout;

    QVBoxLayout* layout2;

    QLabel* label;

public slots:
    void MAJ_Instruction();

};
