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
#include <QPixmap>
#include <QPainter>
#include <QRect>
#include <QPropertyAnimation>

class WidgetJeuMineur : public QWidget
{
	Q_OBJECT
    Q_PROPERTY(QRect blockRect READ blockRect WRITE setBlockRect NOTIFY blockRectChanged)


public:
	WidgetJeuMineur(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
    ~WidgetJeuMineur();

    QRect blockRect() const;
    void setBlockRect(const QRect& rect);

private:
    
    void startShakingAnimation();

    ThreadMoteur* threadMoteur;

    //Mine Layout Section
    QPixmap* mine_background;
    QPixmap* block_shape;
    QVector<QString> shapes;

    //Animation Section
    QRect block_rect;
    QPropertyAnimation* shakeAnimation;

    //Timer Section
    QLabel* countdownLabel;
    QTimer* countdownTimer;
    int countdownTime=0;
    void updateCountdownLabel();
    void updateTimerLabelFontSize();
    bool timerStarted;

    //Rules Section
    QLabel* rulesLabel;
    void updateRulesLabelFontSize();


protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void showEvent(QShowEvent* event) override;

signals:
    void blockRectChanged();

public slots:

    void debut();
    void blockUpadate(float pourcentage);
    void updateCountdown();
    int timer(int);


};
