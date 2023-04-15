//pragma once
/*====================================================================================================
Fichier: FenetreJeuPiano.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: Mini-jeu de piano style Piano tiles
====================================================================================================*/
#ifndef MOTEURJEUMINEUR_H
#define MOTEURJEUMINEUR_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <dos.h>
#include <chrono>
#include <conio.h>

#include "Joystick.h"
#include "Bouton.h"
#include "Chronometre.h"
#include "Moteur.h"
#include "ES.h"
#include "Accel.h"
#include "MoteurMiniJeu.h"
#include "CONSTANTES.h"
#include "Bargraph.h"
#include "QuadBargraph.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Vibration.h"
#include "ThreadMoteur.h"

class MoteurJeuMineur : public MoteurMiniJeu
{
private:

#define Menu 0
#define Jeu 1
	Chronometre chrono;

	int nbCoups; // compteur
	int nbVoulu; // changer pour augmenter la difficulte
	int tempsMax; // changer pour augmenter la difficulte
	double bit;
	double bitCount;
	bool positionHaut;
	bool positionBas;
	bool echouer;

	void affichageEcran(int mode);
	void variationAxe(TypeMotion variation);
	int getCoup(); // accelerometre
	void setCoup(int x); // accelerometre
	bool temps();

public:
	MoteurJeuMineur(ES* threadArduino = nullptr, ThreadMoteur* threadMoteur = nullptr);
	~MoteurJeuMineur();

	void demarrer();
	void initialiser();
};

#endif
