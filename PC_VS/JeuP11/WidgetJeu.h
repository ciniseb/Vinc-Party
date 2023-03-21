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
Description: UI du jeu
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ThreadMoteur.h"
#include <QHBoxLayout>
#include <QGridLayout>

class WidgetJeu : public QWidget
{
	Q_OBJECT

public:
	WidgetJeu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeu();

	ThreadMoteur* threadMoteur;

private:
    //Attributs
    QGridLayout *layout_principal;
    QHBoxLayout *layout_informations;

    QWidget* tuiles[HAUTEUR_CARTE][LARGEUR_CARTE];
};