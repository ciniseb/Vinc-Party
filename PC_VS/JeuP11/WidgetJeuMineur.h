/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 18 mars 2023
Description: UI du mineur
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ThreadMoteur.h"

class WidgetJeuMineur : public QWidget
{
	Q_OBJECT

public:
	WidgetJeuMineur(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeuMineur();

    ThreadMoteur* threadMoteur;

private:
    //Attributs

};
