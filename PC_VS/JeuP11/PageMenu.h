/*====================================================================================================
Fichier: PageMenu.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description:
====================================================================================================*/
#pragma once

#include <QtWidgets/QWidget>
#include "ui_PageMenu.h"
#include <Windows.h>
#include <conio.h>
#include "Page.h"
#include "ES.h"
#include "FenetreJeu.h"
#include "FenetrePointages.h"
#include "FenetreTests.h"
#include "Joystick.h"
#include "Bouton.h"
#include "FenetreCR.h"
#include "PageTest.h"

class PageMenu : public Page
{
private:
    //Attributs
    Page* pages[3];
    Ui::PageMenuClass ui;

public:
    //Constructeurs & destructeurs
    PageMenu(ES*);
    ~PageMenu();

    //Getteurs & setteurs


    //Méthodes
    void initialiser();
    void ouvrir();

    void affichage_DEBUG(int);
};
