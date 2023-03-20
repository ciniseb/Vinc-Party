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
#ifndef FENETREJEUMINEUR_H
#define FENETREJEUMINEUR_H

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
#include "Fenetre.h"
#include "ES.h"
#include "Accel.h"
#include "FenetreMiniJeu.h"
#include "CONSTANTES.h"
#include "Bargraph.h"
#include "QuadBargraph.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Vibration.h"


class FenetreJeuMineur : public FenetreMiniJeu
{
private:

#define Menu 0
#define Jeu 1
	Chronometre chrono;

	int nbCoups = 0; // compteur
	int nbVoulu = 5; // changer pour augmenter la difficulte
	int tempsMax = 10; // changer pour augmenter la difficulte
	double bit;
	double bitCount = 0;
	bool positionHaut = false;
	bool positionBas = false;
	bool echouer = false;

	void affichageEcran(int mode);
	void variationAxe(TypeMotion variation);
	int getCoup(); // accelerometre
	void setCoup(int x); // accelerometre
	bool Temps();

public:
	FenetreJeuMineur(ES* thread);
	~FenetreJeuMineur();

	void ouvrir();
	void initialiser();
};

#endif