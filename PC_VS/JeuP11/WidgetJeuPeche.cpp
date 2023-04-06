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
    Riviere1 = new QImage("Riviere1.png");

    Riviere2 = new QImage("Riviere2.png");
}

WidgetJeuPeche::~WidgetJeuPeche()
{

}


