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

        //Label to display the picture//
    image = new QLabel(this);
    image->setAlignment(Qt::AlignCenter);
    image->setScaledContents(true);

        //Load image//
    etatBlock << ""
              << ""
              << ""
              << "";




    /*
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
    */



    //Connexions
    connect(threadMoteur, SIGNAL(jeuMineur_block(float)), this, SLOT(blockUpadate(float)));
    connect(threadMoteur, SIGNAL(jeuMineur_menu()), this, SLOT(debut()));
    //connect(threadMoteur, SIGNAL(jeuMineur_temps(int)), this, SLOT(temps(int)));
}

void WidgetJeuMineur::blockUpadate(float pourcentage)
{
    if (pourcentage <= 100 * (1 / 5.0))
    {
        pixmap.load(etatBlock[0]);
    }
    else if (pourcentage <= 100 * (2 / 5.0))
    {
        pixmap.load(etatBlock[1]);
    }
    else if (pourcentage <= 100 * (3 / 5.0))
    {
        pixmap.load(etatBlock[2]);
    }
    else if (pourcentage <= 100 * (4 / 5.0))
    {
        pixmap.load(etatBlock[3]);
    }
    else
    {
        pixmap.load(etatBlock[4]);
    }
    image->setPixmap(pixmap);
}

void WidgetJeuMineur::resizeEvent(QResizeEvent* event)
{
    QSize size = image->size();
    image->setPixmap(pixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void WidgetJeuMineur::debut()
{
    pixmap.load(etatBlock[0]);
    image->setPixmap(pixmap);
}

void WidgetJeuMineur::temps(int time)
{
}

WidgetJeuMineur::~WidgetJeuMineur()
{
    delete layout_principal;
    delete chrono;
}
