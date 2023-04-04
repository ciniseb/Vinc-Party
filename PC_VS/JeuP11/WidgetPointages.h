/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 18 mars 2023
Description: UI des pointages
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ThreadMoteur.h"

class WidgetPointages : public QWidget
{
	Q_OBJECT

public:
    WidgetPointages(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetPointages();

    ThreadMoteur* threadMoteur;

private:
    //Attributs

};
