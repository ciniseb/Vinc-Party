/*====================================================================================================
Fichier: Page.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 02 février 2023
Description:
====================================================================================================*/
#include "Page.h"

//Constructeurs & destructeurs
Page::Page(QWidget* parent) : QWidget(parent)
{
    threadArduino = nullptr;
    ui.setupUi(this);
}
Page::Page(ES* thread, QWidget* parent) : QWidget(parent)
{
    threadArduino = thread;
}
Page::~Page() {}

//Getteurs & setteurs


//Méthodes