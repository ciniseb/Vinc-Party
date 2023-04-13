#pragma once

#include <QWidget>
#include <QPainter>
#include <QVector>
#include "CONSTANTES.h"
#include "ThreadMoteur.h"
#include "Coordonnee.h"
#include "Acteur.h"

class WidgetCarte : public QWidget
{
    Q_OBJECT

public:
    WidgetCarte(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
    ~WidgetCarte();

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    ThreadMoteur* threadMoteur;

    float taille_tuile;

    float espace_y;
    float espace_x;

    QVector<QVector<int>> q_carte;
    Acteur joueur;
    Acteur adversaire;

    //Méthodes
    float distance(Coordonnee, Coordonnee);

public slots:
    void MAJ_Carte(QVector<QVector<int>>);
    void MAJ_Acteur(int, Acteur);
    //void MAJ_Coordonnee(Coordonnee, Coordonnee);
};
