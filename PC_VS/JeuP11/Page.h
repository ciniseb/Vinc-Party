/*====================================================================================================
Fichier: Page.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 05 f�vrier 2023
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


    //M�thodes
    virtual void ouvrir() = 0;
    virtual void initialiser() = 0;
};
