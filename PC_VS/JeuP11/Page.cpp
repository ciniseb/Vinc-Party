/*====================================================================================================
Fichier: Page.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 02 f�vrier 2023
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


//M�thodes