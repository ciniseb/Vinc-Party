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
#include "WidgetJeuMineur.h"

WidgetJeuMineur::WidgetJeuMineur(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
	threadMoteur = thread;

    //UI
        //Timer//
    timer = new QTimer(this);
    chrono = new QLabel("LOL");
    rect = new QRect;
    rect->adjust(20, 20, 20, 20);

    QFrame* frame = new QFrame(this);
    frame->setFrameShape(QFrame::Box);


    layout_principal = new QGridLayout();
    layout_principal->addWidget(chrono, 0, 0, (Qt::AlignRight | Qt::AlignTop));
    //layout_principal->addWidget(frame, 0, 0);

    setLayout(layout_principal);
    chrono->setText("Chrono");




    //Connexions
    connect(threadMoteur, SIGNAL(jeuMineur_block(float)), this, SLOT(blockUpadate(float)));
    connect(threadMoteur, SIGNAL(jeuMineur_menu()), this, SLOT(debut()));
    connect(threadMoteur, SIGNAL(jeuMineur_temps(int)), this, SLOT(temps(int)));
}

void WidgetJeuMineur::blockUpadate(float pourcentage)
{
    if (pourcentage <= 100 * (1 / 5.0))
    {
        rect->adjust(30, 30, 30, 30);
        chrono->setText("10");

    }
    else if (pourcentage <= 100 * (2 / 5.0))
    {
        rect->adjust(40, 40, 40, 40);
        chrono->setText("20");
    }
    else if (pourcentage <= 100 * (3 / 5.0))
    {
        rect->adjust(50, 50, 50, 50);
        chrono->setText("30");

    }
    else if (pourcentage <= 100 * (4 / 5.0))
    {
        rect->adjust(60, 60, 60, 60);
        chrono->setText("40");
    }
    else
    {
        rect->adjust(70, 70, 70, 70);
        chrono->setText("50");
    }
}

void WidgetJeuMineur::debut()
{
    chrono->setText("change");
}

void WidgetJeuMineur::temps(int time)
{
    chrono->setText(QString::number(time));
}

WidgetJeuMineur::~WidgetJeuMineur()
{
    delete layout_principal;
    delete chrono;
}
