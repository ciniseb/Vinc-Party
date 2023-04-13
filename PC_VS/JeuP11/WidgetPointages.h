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
#include <QGridLayout>
#include <QPushButton>
#include <QVector>
#include <QHBoxLayout>
#include <cmath>


class WidgetPointages : public QWidget
{
	Q_OBJECT

public:
    WidgetPointages(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetPointages();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    ThreadMoteur* threadMoteur;

    void updateButtons();
    int currentPage = 0;
    int maxPages = 10;
    int maxPage();

    bool playerCard = false;
    int currentIndex = 0;
    int indexUpdate(int);

    QVector<std::string>* nameVector;
    QVector<int>* levelVector;
    QVector<double>* timeVector;
    QVector<double>* timelevelVector;
    QVector<int>* distanceVector;

    QList<QHBoxLayout*>* buttonLayouts;

    QPixmap* background;
    QRect* footprint;
    QGridLayout* layout;
    QPushButton* button;
    int numButtons = 5;
    int selectedButtonIndex = 0;
    void selectButton(int);
    void updateButtonFontSizes();
    int buttonFontSize = 0;


    QLabel* rulesLabel;
    QLabel* playerCardLabel;
    QLabel* titlelabel;
    void updateTitleLabelFontSize();
    void updatePlayerCard();

public slots:
    void right();
    void left();
    void up();
    void down();
    void select();

    void names(const std::string& playerName);
    void level(int);
    void time(double);
    void timeperlev(double);
    void distance(int);
};
