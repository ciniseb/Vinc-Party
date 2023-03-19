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

WidgetMenu::WidgetMenu(ThreadMoteur* thread, QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    threadMoteur = thread;


    //Connexions
    connect(threadMoteur, SIGNAL(menu_selection(int)), this, SLOT(selection(int)));
}

WidgetMenu::~WidgetMenu()
{
    delete threadMoteur;
}

//Slots
void WidgetMenu::selection(int selection)
{
    switch (selection)
    {
    case 0:
        ui.bouton_jouer->setChecked(true);
        ui.bouton_pointages->setChecked(false);
        ui.bouton_quitter->setChecked(false);
        break;
    case 1:
        ui.bouton_jouer->setChecked(false);
        ui.bouton_pointages->setChecked(true);
        ui.bouton_quitter->setChecked(false);

        break;
    case 2:
        ui.bouton_jouer->setChecked(false);
        ui.bouton_pointages->setChecked(false);
        ui.bouton_quitter->setChecked(true);
        break;
    default:
        break;
    }
}