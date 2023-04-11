/*====================================================================================================
Fichier: FenetrePointages.cpp
Auteurs: Antoine Allard
		 Charles Beaulieu
		 �mile Bois
		 Enes Caku
		 Zachari Gervais
		 Anne-Sophie Nguyen
		 S�bastien St-Denis
		 Date: 18 mars 2023
Description:
====================================================================================================*/
#pragma once

#include <QThread>
#include <QVector>
#include <QString>
#include <QInputDialog>
#include "ES.h"
#include "Coordonnee.h"
#include "Acteur.h"

class MoteurMenu;
class ThreadMoteur : public QThread
{
	Q_OBJECT

private:
	ES* threadArduino;
	MoteurMenu* moteur;

public:
	ThreadMoteur(ES* threadArduino = nullptr, QObject *parent = nullptr);
	~ThreadMoteur();

	void run();

signals:
	/*=======================================================================================
	-�crire ses signals dans sa section
	-Commencer le nom du signal avec le moteur en question et suivre d'une barre en bas (_)
	=======================================================================================*/
	void changementWidgetActif(int index);
	
	//MoteurMenu
	void menu_selection(int selection);

	//MoteurPointages


	//MoteurJeu
	void jeu_MAJ_Informations(std::string, int, std::string, int, int);
	void jeu_MAJ_Temps(std::string);
	void jeu_MAJ_Distance(int);
	void jeu_MAJ_MiniJeux(int);

	void jeu_MAJ_Carte(QVector<QVector<int>>);
	void jeu_MAJ_Acteur(int, Acteur);
	void jeu_MAJ_Coordonnee(Coordonnee, Coordonnee);

	//MoteurJeuPiano


	//Moteur...
	
	
public slots:
	void nomJoueur(std::string);
};
