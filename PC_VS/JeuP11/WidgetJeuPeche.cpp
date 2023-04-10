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
Description: UI de peche
====================================================================================================*/
#include "WidgetJeuPeche.h"

WidgetJeuPeche::WidgetJeuPeche(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    //Connexions
    widget = new QWidget();
    riviere = new WidgetRiviere(threadMoteur, this);
    progressBar = new QProgressBar();

    layout = new QHBoxLayout(widget);
    layout->addWidget(riviere);
    layout->addWidget(progressBar);

    setLayout(layout);
    connect(threadMoteur, SIGNAL(jeuPecheMAJ_ProgressBar(int)), progressBar, SLOT(setValue(int)));
}

WidgetJeuPeche::~WidgetJeuPeche()
{

}

/*void WidgetJeuPeche::MAJ_ProgressBar(int x)
{

}*/


