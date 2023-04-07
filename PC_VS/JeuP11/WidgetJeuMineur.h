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
Description: UI du mineur
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ThreadMoteur.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>


class WidgetJeuMineur : public QWidget
{
	Q_OBJECT

public:
	WidgetJeuMineur(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
    ~WidgetJeuMineur();

    ThreadMoteur* threadMoteur;

private:
    int etat;

    QPixmap pixmap;
    QLabel* image;
    QStringList etatBlock;

    QGridLayout* layout_principal;
    QRect cube;
    QLabel* chrono;
    QRect* rect;
    QTimer* timer;

protected:
    void resizeEvent(QResizeEvent* event) override;

public slots:
    void debut();
    void temps(int time);
    void blockUpadate(float pourcentage);

};
