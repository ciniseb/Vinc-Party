/*====================================================================================================
Fichier: Page.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: Classe abstraite pour l'UI des pages.
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ui_Page.h"
#include "ES.h"

class Page : public QWidget
{
    Q_OBJECT

protected:
    //Attributs
    ES* threadArduino;
    Ui::PageClass ui;

public:
    //Constructeurs & destructeurs
    Page(QWidget* parent = nullptr);
    Page(ES*, QWidget* parent = nullptr);
    virtual ~Page();

    //Getteurs & setteurs


    //Méthodes
    virtual void ouvrir() = 0;
    virtual void initialiser() = 0;
};
