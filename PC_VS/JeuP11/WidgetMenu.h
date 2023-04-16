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
#include <QPainter>
#include <QSvgRenderer>
#include <QSvgWidget>

class WidgetMenu : public QWidget
{
    Q_OBJECT

public:
    WidgetMenu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
    ~WidgetMenu();

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    //Attributs
    ThreadMoteur* threadMoteur;

    QGridLayout *layout_principal;
    QVBoxLayout *layout_boutons;

    QSpacerItem* horizontalSpacer;
    QSpacerItem* verticalSpacer;

    QPushButton *bouton_jouer;
    QPushButton *bouton_pointages;
    QPushButton *bouton_quitter;

    QSvgRenderer *svg_fond;

    float espace_y;
    float espace_x;

public slots:
    void selection(int);

signals:


};

