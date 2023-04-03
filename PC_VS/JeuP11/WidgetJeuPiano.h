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
Description: UI du piano
====================================================================================================*/
#pragma once

#include <QWidget>
#include "ThreadMoteur.h"

class WidgetJeuPiano : public QWidget
{
	Q_OBJECT

public:
	WidgetJeuPiano(ThreadMoteur* thread = nullptr, QWidget *parent = nullptr);
	~WidgetJeuPiano();

	ThreadMoteur* threadMoteur;

private:
    //Attributs

};
