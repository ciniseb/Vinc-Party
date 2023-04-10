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

    ThreadMoteur* threadMoteur;

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:

    float taille_riviere;

    float espace_y;
    float espace_x;
    
    int riviere;

    QVector<QVector<int>> q_riviere;

public slots:
    void MAJ_Riviere(int);
    void MAJ_Baleine(int);
    void MAJ_Pecheur(int);
};

