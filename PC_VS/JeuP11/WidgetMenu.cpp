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
Description: UI du menu
====================================================================================================*/
#include "WidgetMenu.h"

WidgetMenu::WidgetMenu(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    //UI
    bouton_jouer = new QPushButton("Jouer");
    bouton_jouer->setCheckable(true);
    bouton_jouer->setFixedSize(500, 50);

    bouton_pointages = new QPushButton("Pointages");
    bouton_pointages->setCheckable(true);
    bouton_pointages->setFixedSize(500, 50);

    bouton_quitter = new QPushButton("Quitter");
    bouton_quitter->setCheckable(true);
    bouton_quitter->setFixedSize(500, 50);

    layout_boutons = new QVBoxLayout();
    layout_boutons->addWidget(bouton_jouer);
    layout_boutons->addWidget(bouton_pointages);
    layout_boutons->addSpacing(50);
    layout_boutons->addWidget(bouton_quitter);

    layout_principal = new QGridLayout();
    layout_principal->addLayout(layout_boutons, 0, 0, Qt::AlignCenter);

    setLayout(layout_principal);

    //Connexions
    connect(threadMoteur, SIGNAL(menu_selection(int)), this, SLOT(selection(int)));
}

WidgetMenu::~WidgetMenu()
{
    delete bouton_jouer;
    delete bouton_pointages;
    delete bouton_quitter;

    delete layout_boutons;
    delete layout_principal;

    delete threadMoteur;
}

//Slots
void WidgetMenu::selection(int selection)
{
    switch (selection)
    {
    case 0:
        bouton_jouer->setChecked(true);
        bouton_pointages->setChecked(false);
        bouton_quitter->setChecked(false);
        break;
    case 1:
        bouton_jouer->setChecked(false);
        bouton_pointages->setChecked(true);
        bouton_quitter->setChecked(false);

        break;
    case 2:
        bouton_jouer->setChecked(false);
        bouton_pointages->setChecked(false);
        bouton_quitter->setChecked(true);
        break;
    default:
        break;
    }
}

/*QGridLayout * layout = new QGridLayout(this);
QListWidget * listWidget = new QListWidget(this);
listWidget->setFixedSize(640,480);
listWidget->adjustSize();

layout->addWidget(listWidget,0, 0,Qt::AlignCenter);*/