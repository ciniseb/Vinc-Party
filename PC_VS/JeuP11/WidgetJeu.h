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
Description: UI du jeu
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ThreadMoteur.h"

class WidgetJeu : public QWidget
{
	Q_OBJECT

public:
	WidgetJeu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeu();

	ThreadMoteur* threadMoteur;

private:
    //Attributs

};
