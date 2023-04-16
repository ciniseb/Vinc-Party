/*====================================================================================================
Fichier: main.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 18 mars 2023
Description: 
====================================================================================================*/
/*-------------------------- Librairies externes ----------------------------*/
#include "CONSTANTES.h"
#include "ES.h"

#if MODE_CONSOLE
#include "FenetreMenu.h"
#else
#include "Interface.h"
#include "ThreadMoteur.h"
#endif
/*------------------------------ Librairies ---------------------------------*/
///////

#if MODE_CONSOLE
///////
#else
#include <QtWidgets/QApplication>
#endif
/*------------------------- Prototypes de fonctions -------------------------*/
///////

#if MODE_CONSOLE
void ShowConsoleCursor(bool showFlag);
#else
///////
#endif
/*----------------------------- Fonction "Main" -----------------------------*/
///////

#if MODE_CONSOLE
int main()
{
    SetConsoleTitle(TEXT("Le Chemin de Croix"));
    ShowConsoleCursor(false);

    ES threadArduino;
    threadArduino.demarrer();
    MoteurMenu menu(&threadArduino);

    menu.demarrer();


    //FenetreMiniJeu *fenetreJeuPiano = new FenetreJeuPiano();
   // fenetreJeuPiano->demarrer();


    //Tests. � commenter au besoin
    //Tests tests;
    //tests.tests_chronometre();
    //tests.tests_fenetrejeu();
    //tests.tests_autre();
    //tests.tests_FenetreJeuPiano();

    //tests.tests_fenetrePointages();
    // tests.tests_autre();

    return 0;
}
#else
int main(int argc, char* argv[])
{
    //Application
    QApplication LeCheminDeCroix(argc, argv);

    //Threads
    ES threadArduino;
    ThreadMoteur threadMoteur(&threadArduino);

    //UI
    Interface interfaceApp(&threadMoteur);

    //affichage
    interfaceApp.show();

    //Démarrage des threads
    threadMoteur.start();
    threadArduino.demarrer();

    return LeCheminDeCroix.exec();
}
#endif

/*---------------------------Definition de fonctions ------------------------*/
///////

#if MODE_CONSOLE
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}
#else
///////
#endif
