#include "UI_Menu.h"
#include "FenetreMenu.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication LeChemindeCroix(argc, argv);
    UI_Menu UI_menu;
    UI_menu.show();
    return LeChemindeCroix.exec();
}