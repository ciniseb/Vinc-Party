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
#include "ThreadMoteur.h"
#include <QPainter>
#include <QLabel>


class WidgetPointages : public QWidget
{
	Q_OBJECT

public:
    WidgetPointages(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetPointages();

    ThreadMoteur* threadMoteur;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QPixmap* background;


    QLabel* titlelabel;
    void updateTitleLabelFontSize();


    //Attributs

};
