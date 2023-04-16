/*====================================================================================================
Fichier: WidgetJeuPiano.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 18 mars 2023
Description: UI du piano
====================================================================================================*/
#pragma once

#include <QWidget>
#include <QtWidgets/QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPainter>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QStaticText>

#include "ThreadMoteur.h"

struct Note
{
    QPixmap image;
    int x;
    int y;
    int noteType;
    qreal initialY; 
    qreal initialHeight;
    qint64 creationTime;
};

class WidgetJeuPiano : public QWidget
{
	Q_OBJECT

public:
	WidgetJeuPiano(ThreadMoteur* thread = nullptr, QWidget *parent = nullptr);
	~WidgetJeuPiano();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    //Attributs
    ThreadMoteur* threadMoteur;

    QPixmap* background;
    qreal scaleFactor;
    QPixmap vert, rouge, bleu, orange; 
    QVector<Note> notes;
    QTimer* timer;
    int score = 0;
    QString infoText;
    bool firstNoteAppeared;
    QStaticText infoStaticText;

    void Ajout_Note(int);
    void Update_score(int);
    void Demarrage();
    void updateNotes();
};
