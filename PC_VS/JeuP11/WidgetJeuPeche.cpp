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
    widget2 = new QWidget();
    riviere = new WidgetRiviere(threadMoteur, this);
    progressBar = new QProgressBar();
    label = new QLabel("Bougez le pecheur avec le joystick et allignez le avec la baleine pour monter la barre de progression.\nUne fois la barre de progression remplit brassez la manette pour pecher la baleine.\nSoyez vite vous avez un temps limite! \nBouger le joystick pour commencer le jeux!", widget2);
    label->setFixedHeight(200);
    label->setFixedWidth(1200);
    QFont font = label->font();
    font.setPointSize(18);
    label->setFont(font);


    progressBar->setRange(0, 10);


    layout = new QVBoxLayout(widget);
    layout->addWidget(riviere);
    layout->addWidget(progressBar);


    setLayout(layout);
    connect(threadMoteur, SIGNAL(jeuPecheMAJ_ProgressBar(int)), progressBar, SLOT(setValue(int)));
    connect(threadMoteur, SIGNAL(jeuPecheMAJ_Message()), widget2, SLOT(close()));
    connect(threadMoteur, SIGNAL(jeuPecheMAJ_Instruction()), this, SLOT(MAJ_Instruction()));
}

WidgetJeuPeche::~WidgetJeuPeche()
{

}

void WidgetJeuPeche::MAJ_Instruction()
{
    widget2->show();
}


