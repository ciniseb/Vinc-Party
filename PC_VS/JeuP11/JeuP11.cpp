// JeuP11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
/*-------------------------- Librairies externes ----------------------------*/
#include "FenetreMenu.h"
#include "FenetreJeuPiano.h"
#include "Tests.h"
#include "Evenement.h"
#include "Bouton.h"
#include "Joystick.h"
#include "Accel.h"
#include "Bargraph.h"
#include "Vibration.h"
#include "Boussole.h"
#include "CONSTANTES.h"
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
/*------------------------- Prototypes de fonctions -------------------------*/
void ShowConsoleCursor(bool showFlag);
/*----------------------------- Fonction "Main" -----------------------------*/
/*int main()
{
    //ES threadArduino;
    //FenetreMenu menu;

    //menu.ouvrir();
    SetConsoleTitle(TEXT("Le Chemin de Croix"));
    ShowConsoleCursor(false);

    ES threadArduino;
    threadArduino.demarrer();
    FenetreMenu menu(&threadArduino);

    menu.ouvrir();
   
 
    //FenetreMiniJeu *fenetreJeuPiano = new FenetreJeuPiano();
   // fenetreJeuPiano->ouvrir();


    //Tests. � commenter au besoin
    //Tests tests;
    //tests.tests_chronometre();
    //tests.tests_fenetrejeu();
    //tests.tests_autre();
    //tests.tests_FenetreJeuPiano();
    
    //tests.tests_fenetrePointages();
    // tests.tests_autre();
    
    return 0;
}*/

/*---------------------------Definition de fonctions ------------------------*/
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}