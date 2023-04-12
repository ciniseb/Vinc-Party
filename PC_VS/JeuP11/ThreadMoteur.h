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
#include "ES.h"
#include "Fenetre.h"
#include "Coordonnee.h"

class Moteur;
class ThreadMoteur : public QThread
{
	Q_OBJECT

private:
	ES* threadArduino;
	Moteur* moteur;

public:
	ThreadMoteur(ES* threadArduino = nullptr, QObject *parent = nullptr);
	~ThreadMoteur();

	void run();
	bool stop = false;
signals:
	/*=======================================================================================
	-�crire ses signals dans sa section
	-Commencer le nom du signal avec le moteur en question et suivre d'une barre en bas (_)
	=======================================================================================*/
	void changementWidgetActif(int index);
	
	//MoteurMenu
	void menu_selection(int selection);

	//MoteurPointages
	void Pointages_Right();
	void Pointages_Left();
	void Pointages_Up();
	void Pointages_Down();
	void Pointage_Select();
	void Pointages_Names(const std::string& playerName);
	void Pointages_Level(int);
	void Pointages_Time(double);
	void Pointages_TimePerLev(double);
	void Pointages_Distance(int);

	//MoteurJeu
	void jeuMAJ_Complet(std::string, int, std::string, int, int,  int[HAUTEUR_CARTE][LARGEUR_CARTE]);
	void jeuMAJ_Temps(std::string);
	void jeuMAJ_Adversaire(Coordonnee);
	void jeuMAJ_Joueur(Coordonnee, int);

	//MoteurJeuPiano


	//MoteurJeuMineur
	void jeuMineur_menu();
	void jeuMineur_block(float);
	void jeuMineur_temps(int);
	void jeuMineur_timer(int);


	//Moteur...
	
	
};
