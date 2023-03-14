/*====================================================================================================
Fichier: FenetreMenu.h
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
#ifndef FENETREMENU_H
#define FENETREMENU_H

#include <QThread>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Fenetre_test.h"
#include "Fenetre.h"
#include "ES.h"
#include "FenetreJeu.h"
#include "FenetrePointages.h"
#include "FenetreTests.h"
#include "Joystick.h"
#include "Bouton.h"
#include "FenetreCR.h"

class FenetreMenu : public QThread, public Fenetre_test
{
    Q_OBJECT

private:
    //Attributs
    Fenetre *fenetres[3];

    //Overrides
    void run() override;

public:
    //Constructeurs & destructeurs
    FenetreMenu(ES* threadArduino = nullptr, QObject *parent = nullptr);
    ~FenetreMenu();

    //Getteurs & setteurs


    //Méthodes
    void initialiser();
    void ouvrir();

    void affichage_DEBUG(int);

signals:
    void test();

private slots:


};

#endif