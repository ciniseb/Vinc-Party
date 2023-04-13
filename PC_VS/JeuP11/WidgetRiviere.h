#pragma once

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QImage>
#include "CONSTANTES.h"
#include "ThreadMoteur.h"
#include "Coordonnee.h"

class WidgetRiviere : public QWidget
{
    Q_OBJECT

public:
    WidgetRiviere(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
    ~WidgetRiviere();

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    ThreadMoteur* threadMoteur;

    float taille_riviere;

    float espace_y;
    float espace_x;
    
    int riviere;
    
    int posBal;
    int lastPos;
    int posPeche;

    bool baleineShake;
    bool pretPecher;

    QPixmap* riviere1;
    QPixmap* riviere2;
    QPixmap* riviere3;
    QPixmap* Pecheur;
    QPixmap* BaleineDroite;
    QPixmap* BaleineGauche;
    QPixmap* Snorlax;
    QPixmap* Snorlax2;

    QPainter* toile;

    QVector<QVector<int>> q_riviere;

public slots:
    void MAJ_Riviere(int);
    void MAJ_Baleine(int);
    void MAJ_Pecheur(int);
};

