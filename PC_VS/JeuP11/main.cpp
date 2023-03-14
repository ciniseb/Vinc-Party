#include "PageMenu.h"
#include "FenetreMenu.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    ES threadArduino;
    threadArduino.demarrer();

    
    FenetreMenu menu(&threadArduino);
    menu.ouvrir();

    QApplication LeChemindeCroix(argc, argv);
    PageMenu UI_menu();
    UI_menu.show();
    return LeChemindeCroix.exec();
}