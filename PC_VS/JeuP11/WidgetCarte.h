#pragma once

#include <QWidget>
#include <QPainter>
#include <QVector>
#include "CONSTANTES.h"
#include "ThreadMoteur.h"
#include "Coordonnee.h"

class WidgetCarte : public QWidget
{
    Q_OBJECT

public:
    WidgetCarte(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
    ~WidgetCarte();

    ThreadMoteur* threadMoteur;

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    float taille_tuile;

    float espace_y;
    float espace_x;

    QVector<QVector<int>> q_carte;
    Coordonnee pos_joueur;
    Coordonnee pos_adversaire;

public slots:
    void MAJ_Carte(QVector<QVector<int>>);
    void MAJ_Coordonnee(int, Coordonnee, Coordonnee);
};
